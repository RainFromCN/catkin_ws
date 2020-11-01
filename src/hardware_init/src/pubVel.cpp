#include<ros/ros.h>
#include<geometry_msgs/Twist.h>
using namespace std;

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "pubVel");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 10);

    ros::Rate loop_rate(100);

    ROS_INFO("Publishing vel msgs");

    while(ros::ok()) {
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.x = 2.;
        pub.publish(vel_msg);
        loop_rate.sleep();
    }

    return 0;
}