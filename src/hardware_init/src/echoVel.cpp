#include<iostream>
#include<cstring>
#include<string>
#include<ros/ros.h>
#include<geometry_msgs/Twist.h>
#include "fcntl.h"
#include "termios.h"
#include "unistd.h"
#include "errno.h"
using namespace std;

static struct termios SerialPortSettings;
static float vel_forward = 0.f, vel_offset = 0.f, vel_rotate = 0.f;
static int fd;

char topic1[] = "vel_forward";
char topic2[] = "vel_offset";
char topic3[] = "vel_rotate";

void MQUEUE_Publish(char* topic, uint32_t* from) {
    
    uint8_t head = '@';
    uint8_t div  = '#';
    uint8_t end  = '$';

    uint8_t cx = 0;
    uint8_t* p = (uint8_t*)from;

    write(fd, &head, 1);
    write(fd, topic, strlen(topic));
    write(fd, &div, 1);
    write(fd, from, 4);

    for (uint8_t i = 0; i < strlen(topic); i++) cx += topic[i];
    for (uint8_t i = 0; i < 4; i++) cx += p[i];

    printf("%x\r\n", cx);

    write(fd, &cx, 1);
    write(fd, &end, 1);
}

void subCallback(const geometry_msgs::Twist::ConstPtr& msg) {

    vel_forward = (float)msg->linear.x;
    vel_offset  = (float)msg->linear.y;
    vel_rotate  = (float)msg->angular.z;

    MQUEUE_Publish(topic1, (uint32_t*)&vel_forward);
    MQUEUE_Publish(topic2, (uint32_t*)&vel_offset);
    MQUEUE_Publish(topic3, (uint32_t*)&vel_rotate);

    ROS_INFO("echo 1 msg: %.2f", vel_forward);
}

int main(int argc, char *argv[])
{

    /* init the tty dev */
    fd = open("/dev/ttyUSB0", O_RDWR|O_NOCTTY);
    if (fd == -1) cout << "error " << strerror(errno) << endl;
    else cout << "success " << fd << endl;
    tcgetattr(fd, &SerialPortSettings);
    cfsetispeed(&SerialPortSettings, B115200);
    cfsetospeed(&SerialPortSettings, B115200);
    SerialPortSettings.c_cflag &= ~PARENB;
    SerialPortSettings.c_cflag &= ~CSTOPB;
    SerialPortSettings.c_cflag &= ~CSIZE;
    SerialPortSettings.c_cflag |= CS8;
    SerialPortSettings.c_cflag &= ~CRTSCTS;
    SerialPortSettings.c_cflag |= CREAD | CLOCAL;
    SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY);
    SerialPortSettings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    tcsetattr(fd, TCSANOW, &SerialPortSettings);

    /* code for main function */
    ros::init(argc, argv, "echoVel");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("cmd_vel", 10, subCallback);
    ros::spin();

    close(fd);
    return 0;
}