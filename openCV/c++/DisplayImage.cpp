#include <iostream>
#include <opencv2/opencv.hpp>
 
using namespace cv;

void my_resize(Mat image, Mat* dest, Size size) {
    resize(image, *dest, size, 0, 0, INTER_LINEAR);
}

void my_flipVertically(Mat image, Mat *dest) {
    cv::flip(image, *dest, 0);
}

void my_flipHorizontally(Mat image, Mat *dest) {
    cv::flip(image, *dest, 1);
}

void my_flipBoth(Mat image, Mat *dest) {
    cv::flip(image, *dest, -1);
}

Mat my_crop(Mat image, Rect roi) {
    Mat cropImage = image;
    return cropImage(roi);
}

void my_rotate(Mat image, Mat* dest, Point2f point) {
    Mat rotMat = cv::getRotationMatrix2D(point, 45, 1.0);
    cv::warpAffine(image, *dest, rotMat, image.size());
}

void bgrToRgb(Mat image, Mat* dest) {
    cv::cvtColor(image, *dest, COLOR_BGR2RGB);
}

void bgrToHSV(Mat image, Mat* dest) {
    cv::cvtColor(image, *dest, COLOR_BGR2HSV);
}

void bgrToLab(Mat image, Mat* dest) {
    cv::cvtColor(image, *dest, COLOR_BGR2Lab);
}

void bgrToGray(Mat image, Mat* dest) {
    cv::cvtColor(image, *dest, COLOR_BGR2GRAY);
}

void saveImage(std::string name, Mat image) {
    try
    {
        cv::imwrite(name, image);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }
    return;
}

void drawLine(Mat image, Mat* dest, Point pointA, Point pointB) {
    *dest = image.clone();
    cv::line(*dest, pointA, pointB, Scalar(100, 255, 30), 2, 8, 0);
}

void drawCircle(Mat image, Mat* dest, Point circle_center, int radius) {
    *dest = image.clone();
    cv::circle(*dest, circle_center, radius, Scalar(0, 0, 255), 3, 8, 0);
}

void drawRectangle(Mat image, Mat* dest, Point start, Point end) {
    *dest = image.clone();
    cv::rectangle(*dest, start, end, Scalar(0, 0, 255), 3, 8, 0);
}

void putText(Mat image, Mat* dest, std::string text, Point point) {
    *dest = image.clone();
    putText(*dest, text, point, FONT_HERSHEY_COMPLEX, 1.5, Scalar(250,225,100));

}

int main(int argc, char** argv )
{
    Mat image;
    Mat dest;

    image = imread("./image.jpg", IMREAD_COLOR );
    
    // RESIZE
    // Size size(600,600);
    // my_resize(image, &image, size);
    // my_resize(image, &dest, size);

    // FLIP
    // my_flipBoth(image, &dest);

    // CROP
    // Rect roi(50, 50, 200, 150);
    // dest = my_crop(image, roi);

    // ROTATE
    // Point2f point(image.cols / 2.0F, image.rows / 2.0F);
    // my_rotate(image, &dest, point);

    // CONVERT TO ANOTHER IMAGE FORMAT
    // bgrToRgb(image, &dest);
    // bgrToHSV(image, &dest);
    // bgrToLab(image, &dest);
    // bgrToGray(image, &dest);

    // DRAW A LINE
    // Point pointA(image.cols / 2.0F - 80, image.rows / 1.3F);
    // Point pointB(image.cols / 2.0F + 80, image.rows / 1.3F);
    // drawLine(image, &dest, pointA, pointB);

    // DRAW A CIRCLE
    // Point circle_center(image.cols / 2.0F, image.rows / 1.35F);
    // int radius = 50;
    // drawCircle(image, &dest, circle_center, radius);

    // DRAW RECTANGLE
    // Point start_point(300,115);
    // Point end_point(475,225);
    // drawRectangle(image, &dest, start_point, end_point);

    // PUT TEXT
    // std::string a = "tex asdasdt";
    // putText(image, &dest, "tex asdasdt", Point(350,100));

    imshow("Display Image", image);
    imshow("Display", dest);

    waitKey(0);

    saveImage("newimage.jpg", dest);
    return 0;
}