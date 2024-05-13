#include "opencv2/core.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

using namespace cv;
using namespace cv::face;
using namespace std;

std::vector<std::string> names;

void detect_faces(cv::Mat& img, Ptr<FisherFaceRecognizer>&model)
{
  cv::CascadeClassifier face_cascade;
  face_cascade.load("../../haarcascade_frontalface_default.xml");

  if (face_cascade.empty())
    std::cout << "Classifier has not been loaded!\n";

  std::vector<cv::Rect> faces;
  face_cascade.detectMultiScale(img, faces, 1.1,10); 
  
  Mat testFrame = img;
  resize(testFrame, testFrame, cv::Size(500,500), 1,1);

  int predictedLabel = model->predict(testFrame);
  cout << names[predictedLabel] << endl;

  for (auto& face : faces) {
    rectangle(img, face.tl(), face.br(), cv::Scalar(255, 0, 255), 3);
  }
}

int main(int argc, const char *argv[]) {
    std::string path = "../../images/";
    std::string output_folder = "../../images";

    std::vector<cv::Mat> images;
    std::vector<int> labels;

    names.push_back("Arsen");
    names.push_back("David");
    names.push_back("Narek");
    names.push_back("Velison");

    for (int i = 0; i < 4; i++) {
        for (const auto& entry : std::filesystem::directory_iterator(path + std::to_string(i))) {
            std::string imagePath = entry.path().string();
            cv::Mat image = cv::imread(imagePath, cv::IMREAD_COLOR);

            if (image.empty()) {
                std::cout << "Could not open or find the image" << std::endl;
            } else {
                resize(image, image, cv::Size(500,500), 1,1);
                images.push_back(image);            
                labels.push_back(i);
            }
        }
    }

    Ptr<FisherFaceRecognizer> model = FisherFaceRecognizer::create();
    model->train(images, labels);

    VideoCapture cap(0);
    Mat frame;
    while(true) {
        cap >> frame;
        if(frame.empty()) break;

        detect_faces(frame, model);
        char key = (char) waitKey(1);

        imshow("Webcam", frame);
        if(key==27) break;
    }

    cap.release();
    destroyAllWindows();

    
    return 0;
}