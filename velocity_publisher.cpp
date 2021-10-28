/*
����turtle1/cmd_vel���⣬��Ϣ����geometry_msgs::Twist
*/
#include <ros/ros.h>
#include<geometry_msgs/Twist.h>
 int main(int argc,char **argv)
 {
 	//��ʼ��ROS�ڵ�
	 ros::int(argc,argv,"velocity_publisher");
	 
	 //�����ڵ���
	 ros::NodeHandle n; 
	 
	 //����Publisher������Topic,ȷ�����г��� 
	 ros::Publisher turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",20) ��
	 
	 //����ѭ��Ƶ��Ϊ10HZ 
	 ros::Rate loop_rate(10) ��
	 
	 //�������� 
	 int count = 0; 
	 while(ros::ok())
	 {
	 	//��Ϣ�����ʼ��
		 geometry_msgs::Twist vel_msg;
		 wel_msg.linear.x = 0.5;
		 vel_msg.angular.z = 0.2;
		 
		//������Ϣ
		turtle_vel_pub.publish(vel_msg);
		ROS_INFO("Publish turtle velocity command[%0.2f m/s,%0.2f rad/s]",vel_msg.linear.x,vel_msg.anghular.z);
		loop_rate.sleep();
		count++;  
	 }
	 return 0;
  } 
