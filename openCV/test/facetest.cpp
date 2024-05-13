
#include <opencv2/opencv.hpp>
#include "opencv2/face.hpp"
#include <iostream>
#include <vector>
#include <filesystem>

const int WIDTH = 300;
const int HEIGHT = 300;

std::vector<std::string> names;
std::string path = "../../images/";
std::vector<cv::Mat> images;
std::vector<int> labels;

void detect_faces(cv::Mat&img, cv::Ptr<cv::face::FisherFaceRecognizer>&model, cv::Mat mean, cv::Mat eigenfaces, cv::Mat projected);
void addLabelNames();
void addImages();
cv::Mat createDataMatrix(std::vector<cv::Mat>&images);

int main () {
    addImages();
    addLabelNames();

    cv::Ptr<cv::face::FisherFaceRecognizer> model = cv::face::FisherFaceRecognizer::create();
    model -> train(images, labels);
    cv::VideoCapture cap(0);

    cv::Mat data = createDataMatrix(images);
    
    cv::PCA pca(data, cv::Mat(), cv::PCA::DATA_AS_ROW, 37);
    cv::Mat mean = pca.mean;
    cv::Mat eigenVectors = pca.eigenvectors;
    cv::Mat projected = mean * eigenVectors.t();

    cv::Mat frame;
    while (true)
    {
        cap >> frame;

        char key = (char) cv::waitKey(1);
        if (key == 27) break;

        detect_faces(frame, model, mean, eigenVectors, projected);
        cv::imshow("test", frame);
    }
    cap.release();
    return 0;
}

void addLabelNames() {
    names.push_back("Arsen");
    names.push_back("David");
    names.push_back("Narek");
    names.push_back("Velison");
    names.push_back("Victoria");
}

void addImages() {
    for (int i = 0; i < 5; i++) {
        for (const auto& entry : std::filesystem::directory_iterator(path + std::to_string(i))) {
            std::string imagePath = entry.path().string();
            cv::Mat image = cv::imread(imagePath, cv::IMREAD_COLOR);

            if (image.empty()) {
                std::cout << "Could not open or find the image" << std::endl;
            } else {
                resize(image, image, cv::Size(WIDTH, HEIGHT));
                cvtColor(image, image, cv::COLOR_RGB2GRAY);
                images.push_back(image);            
                labels.push_back(i);
            }
        }
    }
}

void detect_faces(cv::Mat&img, cv::Ptr<cv::face::FisherFaceRecognizer>&model, cv::Mat mean, cv::Mat eigenfaces, cv::Mat projected) {
    cv::CascadeClassifier face_cascades;

    face_cascades.load("../../haarcascade_frontalface_default.xml");
    
    if (face_cascades.empty()) {std::cout << "error";}

    std::vector<cv::Rect> faces;
    face_cascades.detectMultiScale(img, faces, 1.1, 10);

    cv::Mat testFrame;
    cv::cvtColor(img, testFrame, cv::COLOR_BGR2GRAY);

    for( auto &face: faces) {
        testFrame = testFrame(face);
        cv::resize(testFrame, testFrame, cv::Size(WIDTH, HEIGHT));
        int predictedLabel = model -> predict(testFrame);

        cv::Mat testttt = testFrame.reshape(1, 1);
        testttt.convertTo(testttt, CV_32F);
        testttt = (testttt - mean) * eigenfaces.t();

        double min_dis = DBL_MAX;
        for (int i = 0; i < projected.rows; ++i) {
            double dist = cv::norm(testttt, projected.row(i), cv::NORM_L2);
            if (dist < min_dis) {
                min_dis = dist;
            }
        }

        if (min_dis > 30000) {
            putText(img, names[predictedLabel], cv::Point(face.tl().x, face.tl().y - 20), cv::FONT_ITALIC, 2, cv::Scalar(255,0,255));
        } else {
            putText(img, "Don't know", cv::Point(face.tl().x, face.tl().y - 20), cv::FONT_ITALIC, 1, cv::Scalar(255,0,255));
        }
        rectangle(img, face.tl(), face.br(), cv::Scalar(255,0,255), 3);
    }
}

cv::Mat createDataMatrix(std::vector<cv::Mat>&images) {
    cv::Mat data(static_cast<int>(images.size()), images[0].rows * images[0].cols, CV_32F);

    for (size_t i = 0; i < 37; i++)
    {
        cv::Mat image = images[i].reshape(1,1);
        image.copyTo(data.row(i));  
    }

    return data;
}