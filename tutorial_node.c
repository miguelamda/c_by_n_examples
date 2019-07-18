// This is a simple ROS node
// For more information: http://wiki.ros.org/

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>


// Based on http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29


void laserReceived(const sensor_msgs::LaserScan::ConstPtr& scan)
{
	double minDistance=99999;
	for (unsigned i=0; i<scan->ranges.size();i++) {
		if (!std::isnan(scan->ranges[i]) && scan->ranges[i]<minDistance) {
			minDistance = scan->ranges[i];
		}
	}
	ROS_INFO("Distance to nearest obstacle: %f meters",minDistance);
}


int main(int argc, char** argv)
{
	ros::init(argc, argv, "tutorial_node");
	ros::NodeHandle n;
	ros::NodeHandle pn("~");

	ros::Subscriber laser_sub = n.subscribe<sensor_msgs::LaserScan>("/scan", 1, laserReceived);

	ros::spin();

	return 0;
}

