#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>


int main(int argc, char **argv)
{
  /**
   The ros::init() function needs to see argc and argv so that it can perform
   any ROS arguments and name remapping that were provided at the command line.

   Must call one of the versions of ros::init() before using any other
   part of the ROS system.
   */
  ros::init(argc, argv, "publishminiproject");

  
  //NodeHandle is the main access point to communications with the ROS system.

  
  ros::NodeHandle n;

  /**
   * The advertise() function is how you tell ROS that you want to
   * publish on a given topic name. 
   * 
   * The second parameter to advertise() is the size of the message queue
   * used for publishing messages. 
   */
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate loop_rate(1);

 
  int count = 0;
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    std_msgs::String msg;

    std::stringstream ss;
    ss << "This square's areal is 0.09 " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    /**
     * The publish() function is how you send messages.
     */
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}