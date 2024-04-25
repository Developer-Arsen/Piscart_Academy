#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

void detect_faces(cv::Mat& img)
{
  cv::CascadeClassifier face_cascade;
  face_cascade.load("/home/arsen/Piscart_Academy/openCV/haarcascade_frontalface_default.xml");

  if (face_cascade.empty())
    std::cout << "Classifier has not been loaded!\n";

  std::vector<cv::Rect> faces;
  face_cascade.detectMultiScale(img, faces, 1.1,10); 
 
  for (auto& face : faces)
    rectangle(img, face.tl(), face.br(), cv::Scalar(255, 0, 255), 3);
}
int main()
{
  cv::VideoCapture cap(0);

  cv::Mat frame;

  while (true)
  {
    cap >> frame;
    detect_faces(frame);
    cv::imshow("test", frame);
    char key = (char) cv::waitKey(5);
    if (key == 27) break;
  }

  cap.release();
  cv::destroyAllWindows();

  return 0;
}