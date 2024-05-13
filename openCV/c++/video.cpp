#include <iostream> 
#include <opencv2/opencv.hpp> 
#include <chrono>

using namespace cv;

bool flipVerticaly = false;
bool flipHorizontaly = false;
    
bool bgrToRgb  = false;
bool bgrToLab  = false;
bool bgrToGray = false;
bool bgrToHsv  = false;

bool isCroped = false;
bool isBlured = false;

Mat my_crop(Mat image, Rect roi);
void my_resize(Mat image, Mat* dest, Size size);
void my_flipVertically(Mat image, Mat *dest);
void my_flipHorizontally(Mat image, Mat *dest);
void my_flipBoth(Mat image, Mat *dest);
void my_rotate(Mat image, Mat* dest, Point2f point);
void bgrToRGB(Mat image, Mat* dest);
void bgrToHSV(Mat image, Mat* dest);
void bgrToLAB(Mat image, Mat* dest);
void bgrToGRAY(Mat image, Mat* dest);
void drawLine(Mat image, Mat* dest, Point pointA, Point pointB);
void drawCircle(Mat image, Mat* dest, Point circle_center, int radius);
void drawRectangle(Mat image, Mat* dest, Point start, Point end);
void putText(Mat image, Mat* dest, std::string text, Point point);
void blurImage(Mat image, Mat* dest);
void saveImage(std::string name, Mat image);
void handleKeyPress(char key);
void putTexts(Mat* frame, std::chrono::time_point<std::chrono::_V2::system_clock, std::chrono::duration<long int, std::ratio<1, 1000000000>>> start);
void handleActions(Mat* frame);

int main(int argc, char *argv[])
{
    auto start = std::chrono::high_resolution_clock::now();
    VideoCapture cap(0);
    
    if(!cap.isOpened()) {
        std::cerr << "Error opening video stream" << std::endl;
        return -1;
    }

    Mat frame;
    while(true) {
        cap >> frame;
        if(frame.empty()) break;

        handleActions(&frame);
        putTexts(&frame, start);

        char key = (char) waitKey(100);
        handleKeyPress(key);

        imshow("Webcam", frame);
        if(key==27) break;
    }

    cap.release();
    destroyAllWindows();

    return 0;
}
 
 
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
    return image(roi);
}

void my_rotate(Mat image, Mat* dest, Point2f point) {
    Mat rotMat = cv::getRotationMatrix2D(point, 45, 1.0);
    cv::warpAffine(image, *dest, rotMat, image.size());
}

void bgrToRGB(Mat image, Mat* dest) {
    cv::cvtColor(image, *dest, COLOR_BGR2RGB);
}

void bgrToHSV(Mat image, Mat* dest) {
    cv::cvtColor(image, *dest, COLOR_BGR2HSV);
}

void bgrToLAB(Mat image, Mat* dest) {
    cv::cvtColor(image, *dest, COLOR_BGR2Lab);
}

void bgrToGRAY(Mat image, Mat* dest) {
    cv::cvtColor(image, *dest, COLOR_BGR2GRAY);
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
    putText(*dest, text, point, FONT_HERSHEY_COMPLEX, 0.7, Scalar(0,0,0));
}

void blurImage(Mat image, Mat* dest) {
    cv::GaussianBlur(image, *dest, Size(5,5), 9999);
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

void handleKeyPress(char key) {
    if (key == 118) { // v
        flipHorizontaly = false;
        flipVerticaly = !flipVerticaly;
    }
    else if (key == 104) { // h
        flipHorizontaly = !flipHorizontaly;
        flipVerticaly = false;
    }
    else if (key == 103) { // g
        bgrToGray = !bgrToGray;
        bgrToRgb = false;
        bgrToHsv = false;
        bgrToLab = false;
    }
    else if (key == 114) { // r
        bgrToRgb = !bgrToRgb;
        bgrToGray = false;
        bgrToHsv  = false;
        bgrToLab  = false;
    }
    else if (key == 108) { // l
        bgrToLab = !bgrToLab;
        bgrToRgb = false;
        bgrToHsv  = false;
        bgrToGray  = false;
    }
    else if (key == 115) { // s
        bgrToHsv = !bgrToHsv;
        bgrToRgb = false;
        bgrToLab = false;
        bgrToGray = false;
    }
    else if (key == 99) { // c
        isCroped = !isCroped;
    }
    else if (key == 98) { // b
        isBlured = !isBlured;
    }
}

void putTexts(Mat* frame, std::chrono::time_point<std::chrono::_V2::system_clock, std::chrono::duration<long int, std::ratio<1, 1000000000>>> start) {
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    std::string elapsedTimeStr = std::to_string(elapsed.count());

    putText(*frame, &(*frame), "Time spent: " + elapsedTimeStr, Point(10,40));
    putText(*frame, &(*frame), "Flip Vert: v", Point(10,60));
    putText(*frame, &(*frame), "Flip Horiz: h", Point(10,80));
    putText(*frame, &(*frame), "Bgr to Rgb: r", Point(10,100));
    putText(*frame, &(*frame), "Bgr to Hsv: s", Point(10,120));
    putText(*frame, &(*frame), "Bgr to Lab: l", Point(10,140));
    putText(*frame, &(*frame), "Bgr to Gray: g", Point(10,160));
    putText(*frame, &(*frame), "Crop to 450x450: c", Point(10,180));
    putText(*frame, &(*frame), "Gaussian blur: b", Point(10,200));
    putText(*frame, &(*frame), "Esc to close", Point(10,220));
}

void handleActions(Mat* frame) {
    if (flipVerticaly) {
        my_flipVertically(*frame, &(*frame));
    }
    else if (flipHorizontaly) {
        my_flipHorizontally(*frame, &(*frame));
    }

    if (bgrToGray) {
        bgrToGRAY(*frame, &(*frame));
    } 
    else if (bgrToRgb) {
        bgrToRGB(*frame, &(*frame));
    }
    else if (bgrToLab) {
        bgrToLAB(*frame, &(*frame));
    }
    else if (bgrToHsv) {
        bgrToHSV(*frame, &(*frame));
    }

    if (isCroped) {
        Rect roi(0,0,450,450);
        *frame = my_crop(*frame, roi);
    }
    if (isBlured) {
        blurImage(*frame, &(*frame));
    }
}




