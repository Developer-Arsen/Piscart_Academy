#include <opencv2/opencv.hpp>
#include <iostream>

cv::Mat img;

void handlePos(int size , void *) {
    cv::resize(img, img , cv::Size(size,size));
    cv::imshow("test",img);
}

int main( int argc, char* argv[] ) {
    cv::Mat img = cv::imread("../images/test.jpg");

    cv::Mat gray = img;
    cv::cvtColor(gray, gray, cv::COLOR_BGR2GRAY);

    cv::pyrDown(gray,gray);
    cv::pyrDown(img,img);
    cv::Canny(gray, gray, 10, 100 ,3, true);
    cv::imshow("test",gray);
    cv::imshow("tes",img);
    cv::waitKey(0);
    // cv::namedWindow( "Example2_11", cv::WINDOW_AUTOSIZE );
    // cv::namedWindow( "Log_Polar",cv::WINDOW_AUTOSIZE );

    // cv::VideoCapture capture(0);
    // int fourcc = cv::VideoWriter::fourcc('X', 'V', 'I', 'D');

    // double fps = capture.get( cv::CAP_PROP_FPS );
    // int width = capture.get(cv::CAP_PROP_FRAME_WIDTH);
    // int height = capture.get(cv::CAP_PROP_FRAME_HEIGHT);

    // cv::Size size( width, height);
    // cv::VideoWriter writer;
    // writer.open("0", fourcc, fps, size);

    // cv::namedWindow("test", cv::WINDOW_AUTOSIZE);
    // img = cv::imread("../images/test.jpg");
    // cv::createTrackbar("Position", "test", NULL, 1000, handlePos);
    
    // cv::imshow("test",img);
    // cv::waitKey(0);


    // capture.set(cv::CAP_PROP_FPS, 1);
    // std::cout << capture.get(cv::CAP_PROP_FPS) << std::endl;
    // capture.set(cv::CAP_PROP_, 1);

    // cv::Mat logpolar_frame, bgr_frame;
    // for(;;) {
    //     // writer >> bgr_frame;
    //     cv::imshow( "Example2_11", bgr_frame );
    //     // cv::Point2f center =  cv::Point2f( bgr_frame.cols/2, bgr_frame.rows/2 );
    //     // cv::logPolar(bgr_frame, logpolar_frame, center, 100, cv::WARP_FILL_OUTLIERS);

    //     // cv::imshow( "Log_Polar", logpolar_frame );
    //     // writer << logpolar_frame;
    //     char c = cv::waitKey(10);
    //     if( c == 27 ) break;
    // }
    // capture.release();
}

// void handlePos(int, void*) {
//     cap.set(cv::CAP_PROP_POS_FRAMES, slider_pos);
// }

// int main () {
    // cv::Mat img = cv::imread("../images/test.jpg");

    // cv::Mat gray = img;
    // cv::cvtColor(gray, gray, cv::COLOR_BGR2GRAY);

    // cv::pyrDown(gray,gray);
    // cv::Canny(gray, gray, 10, 100 ,3, true);

//     cv::imshow("test", img);
//     cv::imshow("test2", gray);
//     cv::waitKey(0);

    // cv::namedWindow("test", cv::WINDOW_AUTOSIZE);
    // std::string videoPath = "../video/piano.mp4";
    // cap.open(videoPath);

    // int frames = cap.get(cv::CAP_PROP_FRAME_COUNT);
    // std::cout << frames;
    // cv::createTrackbar("Position", "test", &slider_pos, frames, handlePos);

    // cv::Mat frame;
    // while (true)
    // {
    //     cap >> frame;

    //     int cur_pos = cap.get(cv::CAP_PROP_POS_FRAMES);
    //     cv::setTrackbarPos("Position", "test", cur_pos);

    //     cv::imshow("test", frame);

    //     char key = (char) cv::waitKey(1);
    //     if (key == 'q') break;
    // }

    // cap.release();
    // cv::destroyAllWindows();
    
// }


// int g_slider_postion = 0;
// int g_run = 1, g_dontset = 0;

// cv::VideoCapture g_cap;

// void onTrackbarSlide(int pos, void *) {
//     g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);

//     if (!g_dontset) {
//         g_run = 1;
//         g_dontset = 0;
//     }
// }

// int main () {
//     cv::namedWindow("Example2_4", cv::WINDOW_AUTOSIZE);
//     std::string videoPath = "../video/piano.mp4";
//     g_cap.open(videoPath);

//     int frames = g_cap.get(cv::CAP_PROP_FRAME_COUNT);
//     int tmpw   = g_cap.get(cv::CAP_PROP_FRAME_WIDTH); 
//     int tmph   = g_cap.get(cv::CAP_PROP_FRAME_HEIGHT); 

//     cv::createTrackbar("Position", "Example2_4", &g_slider_postion, frames, onTrackbarSlide);
//     cv::Mat frame;
//     for (;;)
//     {
//         if (g_run != 0) {
//             g_cap >> frame;
//             if (frame.empty()) break;

//             int current_pos = (int) g_cap.get(cv::CAP_PROP_POS_FRAMES);
//             g_dontset = 1;

//             cv::setTrackbarPos("Position", "Example2_4", current_pos);
//             cv::imshow("Example2_4", frame);

//             g_run = -1;
//         } 

//         char c = (char) cv::waitKey(10);
//         if( c == 's' ) {g_run = 1; std::cout << "Single step, run = " << g_run << std::endl;}
//         if( c == 'r' ) {g_run = -1; std::cout << "Run mode, run = " << g_run << std::endl;}
//         if( c == 27 )
//         break;

//     }
    
//     g_cap.release();
//     cv::destroyAllWindows();
//     return 0;

// }