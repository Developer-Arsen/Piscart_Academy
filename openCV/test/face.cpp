#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
#include <vector>
#include <filesystem>

std::vector<cv::Mat> images;
std::vector<int> labels;
std::vector<std::string> names;

const int width = 300;
const int height = 300; 
std::string folder_path = "../../images/";

void addImages();
void addLablesNames();
void detectFaces(cv::Mat &image, cv::Ptr<cv::face::EigenFaceRecognizer> &model, cv::Mat &mean, cv::Mat &eigenVectors, cv::Mat &projected);
cv::Mat makeAllImagesToMatrix();


int main() {
    addImages();
    addLablesNames();

    cv::Mat data;
    data = makeAllImagesToMatrix();

    cv::PCA pca(data, cv::Mat(), cv::PCA::DATA_AS_ROW, 0);
    cv::Mat mean = pca.mean;
    cv::Mat eigenVectors = pca.eigenvectors;
    cv::Mat projected = mean * eigenVectors.t();

    cv::Ptr<cv::face::EigenFaceRecognizer> model = cv::face::EigenFaceRecognizer::create();
    model -> train(images, labels);

    cv::VideoCapture cap(0);
    cv::Mat frame;

    while (true)
    {
        cap >> frame;
        if (frame.empty()) {
            break;
        }

        detectFaces(frame, model, mean, eigenVectors, projected);
        cv::imshow("WebCam", frame);

        char key = (char) cv::waitKey(1);
        if (key == 27) break;
    }

    cap.release();       
}

void detectFaces(cv::Mat &image, cv::Ptr<cv::face::EigenFaceRecognizer> &model, cv::Mat &mean, cv::Mat &eigenVectors, cv::Mat &projected) {
    cv::CascadeClassifier face_cascades;
    face_cascades.load("../../haarcascade_frontalface_default.xml");

    if (face_cascades.empty()) {
        exit(EXIT_FAILURE);
    }

    std::vector<cv::Rect> faces;
    face_cascades.detectMultiScale(image, faces, 1.1, 10);

    for (auto &face: faces) {   
        cv::Mat gray_frame;
        cv::cvtColor(image, gray_frame, cv::COLOR_BGR2GRAY);

        cv::Mat test = gray_frame(face);
        cv::resize(gray_frame, gray_frame, cv::Size(width, height), 1, 1);

        cv::Mat testingPredictance = gray_frame.reshape(1,1);
        testingPredictance.convertTo(testingPredictance, CV_32F);

        testingPredictance = (testingPredictance - mean) * eigenVectors.t();
        double min_dist = DBL_MAX;

        for (size_t i = 0; i < projected.rows; i++) {
            double dist = cv::norm(testingPredictance, projected.row(i), cv::NORM_L2);
            if (dist < min_dist) min_dist = dist;
        }

        int predictedLabel= model -> predict(gray_frame);

        if (min_dist ) {
            cv::putText(image, names[predictedLabel], cv::Point(face.tl().x, face.tl().y - 30), cv::FONT_ITALIC, 1, cv::Scalar(255,0,255));
        } else {
            cv::putText(image, "chgitem", cv::Point(face.tl().x, face.tl().y - 30), cv::FONT_ITALIC, 1, cv::Scalar(255,0,255));
        }
        cv::rectangle(image, cv::Rect(face.tl(), face.br()), cv::Scalar(255,0,255), 3);
    }
}

void addImages() {
    int number_of_persons = 5;

    for (size_t i = 0; i < number_of_persons; i++)
    {
        for (const auto &entry: std::filesystem::directory_iterator(folder_path + std::to_string(i))) {
            std::string imagePath = entry.path().string();
            cv::Mat image = cv::imread(imagePath, cv::COLOR_BGR2RGB);
            cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);

            if (image.empty()) {
                continue;
            }  else {
                cv::resize(image, image, cv::Size(width, height), 1, 1);
                images.push_back(image);
                labels.push_back(i);
            }
        }
    }
}

void addLablesNames() {
    names.push_back("Arsen");
    names.push_back("David");
    names.push_back("Narek");
    names.push_back("Velison");
    names.push_back("Victoria");
}

cv::Mat makeAllImagesToMatrix() {
    cv::Mat data(static_cast<int>(images.size()), images[0].rows * images[0].cols, CV_32F);
    
    for (size_t i = 0; i < images.size(); i++)
    {
        cv::Mat test = images[i].reshape(1,1);
        test.copyTo(data.row(i));
    }

    return data;
}
