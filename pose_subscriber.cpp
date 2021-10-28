/*
订阅/turtle1/pose话题，消息类型turtlesim::pose
*/

#include <ros/ros.h>
#include "turtlesim/Pose.h"

//不同于publisher,subscriber需要调用消息回调函数（自定义）
void poseCallback(const turtlesim::Pose::ConstPtr& msg)
{
    //打印msg
   ROS_INFO("Turtle pose: x:%0.6f,y:%0.6f",msg->x,msg->y);
}

int main(int argc,char **argv)
{
   //初始化ROS节点
    ros::init(argc,argv,"pose_subscriber");

   //创建节点句柄
    ros::NodeHandle n;

   //创建一个Subscriber
    ros::Subscriber turtle_pose_sub = n.subscribe("/turtle1/pose",20,poseCallback);

   //循环等待回调函数
     ros::spin();

     return 0;
}
