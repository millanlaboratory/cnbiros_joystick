#include <ros/ros.h>
#include <std_srvs/Empty.h>
#include <geometry_msgs/Twist.h>


geometry_msgs::Twist velocity;
bool is_joy_enabled = false;
bool is_data_available = false;

void on_received_joy_cmdvel(const geometry_msgs::Twist& data) {
	velocity = data;
	is_data_available = true;
}

bool on_requested_enable(std_srvs::Empty::Request& req, std_srvs::Empty::Response& res) {

	if(is_joy_enabled == false) {
		is_joy_enabled = true;
		ROS_WARN("[joy_filter_control] node has been enabled");
	}
	
	return true;
}

bool on_requested_disable(std_srvs::Empty::Request& req, std_srvs::Empty::Response& res) {

	if(is_joy_enabled == true) {
		is_joy_enabled = false;
		ROS_WARN("[joy_filter_control] node has been disabled");
	} 
	
	return true;
}

int main(int argc, char **argv) {
	ros::init(argc, argv, "joy_filter_control");
	

	ros::NodeHandle nh;
	ros::Subscriber sub;
	ros::Publisher  pub;
	ros::ServiceServer	srv_enable;
	ros::ServiceServer	srv_disable;
	ros::Rate		rate(10);


	sub = nh.subscribe("/joy_teleop/cmd_vel", 1, &on_received_joy_cmdvel);
	pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
	srv_enable = nh.advertiseService("/joy_filter_control/joystick_enable", &on_requested_enable);
	srv_disable = nh.advertiseService("/joy_filter_control/joystick_disable", &on_requested_disable);

	while(nh.ok()) {

		if(is_joy_enabled == true && is_data_available == true) {
			pub.publish(velocity);
			is_data_available = false;
		}

		ros::spinOnce();
		rate.sleep();
	}



	return 0;
}
