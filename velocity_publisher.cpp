/*
发布turtle1/cmd_vel话题，消息类型geometry_msgs::Twist
*/
#include <ros/ros.h>
#include<geometry_msgs/Twist.h>
 int main(int argc,char **argv)
 {
 	//初始化ROS节点
	 ros::int(argc,argv,"velocity_publisher");
	 
	 //创建节点句柄
	 ros::NodeHandle n; 
	 
	 //创建Publisher并发布Topic,确定队列长度 
	 ros::Publisher turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",20) ；
	 
	 //设置循环频率为10HZ 
	 ros::Rate loop_rate(10) ；
	 
	 //计数变量 
	 int count = 0; 
	 while(ros::ok())
	 {
	 	//消息对象初始化
		 geometry_msgs::Twist vel_msg;
		 wel_msg.linear.x = 0.5;
		 vel_msg.angular.z = 0.2;
		 
		//发布消息
		turtle_vel_pub.publish(vel_msg);
		ROS_INFO("Publish turtle velocity command[%0.2f m/s,%0.2f rad/s]",vel_msg.linear.x,vel_msg.anghular.z);
		loop_rate.sleep();
		count++;  
	 }
	 return 0;
  } 
