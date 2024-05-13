#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
#include <iostream>
#include <filesystem>
#include <vector>

#define WIDTH 300
#define HEIGHT 300

std::vector<cv::Mat> images;
std::vector<int> labels;
std::vector<std::string> names;

std::string folderPath = "../../images/";

void addImages();
void addLablesNames();
void 

int main () {
    addImages();
    addLablesNames();

    

}


void addImages() {
    int size = 5;

    for (size_t i = 0; i < size; i++)
    {
        for (const auto& entry: std::filesystem::directory_iterator(folderPath + std::to_string(i)))
        {
            std::string imgPath = entry.path().string();
            cv::Mat img = cv::imread(imgPath);

            cv::resize(img, img, cv::Size(WIDTH, HEIGHT));
            cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
            images.push_back(img);

            labels.push_back(i);
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