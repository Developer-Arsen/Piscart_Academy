#include <opencv2/opencv.hpp>
#include <iostream>

int main () {
    cv::Mat image = cv::imread("../../images/test.jpg");
    cv::Mat testImage;

    // resize
    cv::resize(image, image, cv::Size(500,500));

    // crop
    cv::Rect roi(0,0, 300 ,300);
    testImage = image(roi);

    // rotate
    cv::Point2d point (image.cols / 2.0F, image.rows / 2.0F);
    cv::Mat rotMat = cv::getRotationMatrix2D(point, 45, 2);
    cv::warpAffine(image, testImage, rotMat, image.size());

    // flip
    cv::flip(testImage, testImage, 1); // 1 y horizonakan
    cv::flip(testImage, testImage, 0); // vertical
    cv::flip(testImage, testImage, -1); // both flipping

    // convert to other color spaces
    cv::cvtColor(testImage, testImage, cv::COLOR_BGR2RGB);
    cv::cvtColor(testImage, testImage, cv::COLOR_BGR2Lab);
    cv::cvtColor(testImage, testImage, cv::COLOR_BGR2HSV);
    cv::cvtColor(testImage, testImage, cv::COLOR_BGR2GRAY);

    // Bluring images 
    cv::GaussianBlur(testImage, testImage, cv::Size(5,5), 0);
    cv::medianBlur(testImage, testImage, 9);
    cv::filter2D(testImage, testImage, 0, std::vector<float> (3,5));

    // text annotations and shapes
    cv::putText(testImage, "test", cv::Point2d(testImage.cols / 2.0F, testImage.rows / 2.0F), cv::FONT_ITALIC, 1, cv::Scalar(255,0,255));
    cv::rectangle(testImage, cv::Rect(cv::Point2d(0,0), cv::Point2d(100,100)), cv::Scalar(255,0,255));
    cv::circle(testImage, cv::Point(testImage.cols / 2.0F, testImage.rows / 2.0F), 25, cv::Scalar(255,0,255));
    cv::line(testImage, cv::Point(0,0), cv::Point(100,0), cv::Scalar(255,0,255));
    
    cv::imshow("test", testImage);
    cv::waitKey(0);
}

Hello, My name is Arsen I am a Software Engineer at Picsart Academy. 
I am the Technical Lead of an AI surveillance project which is an employee activity monitoring system.
I can say that tracking employee activity played an essential role for us because some of the employees were not using their potential fully
also, I had separated low-activity employees and had interviews with them so some of them had personal problems which we tried to solve.
As a result, we had made great success in this project increasing the financial outcome of Picsart Academy by 25%. 
So as nowadays AI is prevailing It is a great idea to include that good toolkit in our problem-solving. 
I am ready to get more from this technology, well if you are interested we can have discussions about this topic.
