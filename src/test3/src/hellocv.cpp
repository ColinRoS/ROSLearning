#include <ros/ros.h>
//#include <cv_bridge/cv_bridge.h>
//#include <image_transport/image_transport.h>
//#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
 
//using namespace cv;

int main()
{
    cv::Mat img = cv::imread("/home/rs/roslearning/src/test3/doc/1.jpg");
    cv::imshow("【载入的图片】",img);
    cv::waitKey(6000);
}