#include <iostream> // for standard I/O
#include <string> // for strings
#include <iomanip> // for controlling float print precision
#include <sstream> // string to number conversion
#include <opencv2/core.hpp> // Basic OpenCV structures (Mat, Scalar)
#include <opencv2/imgproc.hpp> // Gaussian Blur
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp> // OpenCV window I/O
 
using namespace cv;
 
int main(int argc, char *argv[])
{
    VideoCapture cap(0);
    
    if(!cap.isOpened()) {
        std::cerr << "Error opening video stream" << std::endl;
        return -1;
    }

    Mat frame;
    while(true) {
        cap >> frame;

        if(frame.empty())
            break;

        imshow("Webcam", frame);

        char c = (char)waitKey(25);
        if(c==27)
            break;
    }

    cap.release();
    destroyAllWindows();

    return 0;
}
 
