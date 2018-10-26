#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

#include <stdio.h>

int main(int argc, char** argv)
{
  //ROS节点初始化，节点名叫image_publisher（此处区分生成的可执行文件名）
  ros::init(argc, argv, "image_publisher");
  //创建节点句柄
  ros::NodeHandle nh;
  //创建一个Publisher，发布名为camera/image的Topic，消息类型见ImageTransport类里
  image_transport::ImageTransport it(nh);
  image_transport::Publisher pub = it.advertise("camera/image", 1);

  //用OpenCV的函数去读取一张图片
  cv::Mat image = cv::imread("/home/rs/roslearning/src/test4/1.jpg", CV_LOAD_IMAGE_COLOR);
  if(image.empty())
  {
      printf("open error\n");
  }
  //通过ROS提供的数据转换函数cv_bridge，把OpenCV读取的图片转换成ROS的消息类型
   sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();

   //设置循环频率
   ros::Rate loop_rate(5);
   while (nh.ok())
   {
       //发布消息
       pub.publish(msg);
       //循环等待回调函数：保持程序的完成性，此处没有意义的该函数也把回调函数加上
       ros::spinOnce();
       //sleep一段时间以保持频率为5赫兹
       loop_rate.sleep();
   }

   return 0;
}


//实现发布者的流程:
//初始化ROS节点
//向ROS Master注册节点信息，包括发布的话题名和话题中的消息类型
//按照一定频率循环发布消息

//      Node                    Topic           Node
//    image_publisher——————>camera/image——————>listener