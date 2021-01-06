#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include "stdlib.h"
#include "std_msgs/String.h"
//#include "miniprojectsubscriber.h"

// Our moveToGoal function, which is what makes our robot move
bool moveToGoal(double xGoal, double yGoal){

   //define a client for to send goal requests to the move_base server through a SimpleActionClient
   actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> ac("move_base", true);

   //waiting for the action server to come up
   while(!ac.waitForServer(ros::Duration(5.0))){
      ROS_INFO("Waiting for the move_base action server to come up");
   }

   move_base_msgs::MoveBaseGoal goal;

   //Here we set up the frame parameters
   goal.target_pose.header.frame_id = "base_link";
   goal.target_pose.header.stamp = ros::Time::now();

   // We move towards our goal
   goal.target_pose.pose.position.x =  xGoal;
   goal.target_pose.pose.position.y =  yGoal;
   goal.target_pose.pose.position.z =  0.0;
   goal.target_pose.pose.orientation.x = 0.0;
   goal.target_pose.pose.orientation.y = 0.0;
   goal.target_pose.pose.orientation.z = 0.0;
   goal.target_pose.pose.orientation.w = 1.0;

   // Here we send the goal location to the move_base action server.
   ROS_INFO("Sending goal location ...");
   ac.sendGoal(goal);

   // Here we wait for the execution and for the result to be sent back to the requesting client. This request is
   // sychrounous which means it will block until the result is back.
   ac.waitForResult();

   //we chech if the goal succeded or not and display relevent messages.
   if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
      ROS_INFO("You have reached the destination");
      return true;
   }
   else{
      ROS_INFO("The robot failed to reach the destination");
      return false;
   }

}



// Coordinates for the Sqaure
double xSquare1 = 0.3;
double ySqaure1 = 0;

double xSquare2 = 0;
double ySqaure2 = 0.3;

double xSquare3 = -0.3;
double ySqaure3 = 0;

double xSquare4 = 0;
double ySqaure4 = -0.3;


// Using namespace std, to make it easier to use cout, cin etc.
using namespace std;


bool goalReached = false;

//ChatterCallBack Function which prints a string that says the areal of our square
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("[%s]", msg->data.c_str());
  return;
}

//This is where our code starts, with our main function
int main(int argc, char** argv){ //

   int input;
   cout << "Sqaure generator, press 1 to begin program: ";
   cin >> input;

// subscriber 
/**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "miniproject");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   */
  ros::NodeHandle n;

  /**
   * The subscribe() call is how you tell ROS that you want to receive messages
   * on a given topic. 
   *
   * The second parameter to the subscribe() function is the size of the message
   * queue.
   */
   ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

   ros::init(argc, argv, "miniproject");

         if(input = 1){
         goalReached = moveToGoal(xSquare1, ySqaure1);
         }
         if(input = 1){
         goalReached = moveToGoal(xSquare2, ySqaure2);
         }
         if(input = 1){
         goalReached = moveToGoal(xSquare3, ySqaure3);
         }
         if(input = 1){
         goalReached = moveToGoal(xSquare4, ySqaure4);
         }
            if(goalReached){
               ROS_INFO("Location has been reached");
               ros::spinOnce();
               //return 0;
            }
      return 0; // By defualt a main function will return zero, so can be left out
   
      }
