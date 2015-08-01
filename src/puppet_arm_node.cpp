#include<ros/ros.h>
#include<sensor_msgs/JointState.h>
#include "baxter_core_msgs/JointCommand.h"

#include<stdio.h>
#include<iostream>
#include<string.h>
#include <algorithm>
#include <vector>

using namespace std ;
using namespace ros ;
Publisher joint_command_pub;
Subscriber joint_states;

//string joint_name;
float current_pose_opp,current_velocity_opp;
//vector<int>::iterator i;
void statecallback(sensor_msgs::JointState state){
baxter_core_msgs::JointCommand cmd_msg;
	cmd_msg.mode = 1;

	
for(int i=9; i<16; i++)
{	cmd_msg.names.push_back(state.name[i-7]);
	if(state.name[i]=="right_e0" || state.name[i]=="right_s0"|| state.name[i]=="right_w0"|| state.name[i]=="right_w2")
			current_pose_opp = -state.position[i];
	else
			current_pose_opp = state.position[i];
			
		  cmd_msg.command.push_back(current_pose_opp);
		  
		  joint_command_pub.publish(cmd_msg);
}
}
	
	/* //generic way of coding
 	for(int i = 0; i < state.name.size() ; i++ )
	{
		if(state.name[i].substr(0,5)=="right")
		{
		  if(state.name[i]=="right_e0" || state.name[i]=="right_s0"|| state.name[i]=="right_w0"|| state.name[i]=="right_w2")
			current_pose_opp = -state.position[i];
		  else
			current_pose_opp = state.position[i];
			//current_velocity_opp = state.velocity[i];
		  cmd_msg.command.push_back(current_pose_opp);
		  if(state>name[i].substr(0,4)=="left")
		{
		  cmd_msg.names.push_back(state.name[i]);
		}
		  joint_command_pub.publish(cmd_msg);
		}
	}
}*/

int main(int argc , char **argv)
{
	init(argc,argv, "puppet_arm_node");
	NodeHandle nh("~");

	// SUbscribing
	ROS_INFO("SUBSCRIBING TO TOPICS \n");
	 joint_states = nh.subscribe<sensor_msgs::JointState>("/robot/joint_states",1,statecallback);

	 //publishing
		joint_command_pub=nh.advertise<baxter_core_msgs::JointCommand>("/joint_command",1);

	Rate loop_rate(1000);


while(ok()){



	spinOnce();
	loop_rate.sleep();

}

	return 0;
}
