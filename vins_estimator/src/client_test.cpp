#include "ros/ros.h"
#include <vins_estimator/GetVinsPose.h>
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "get_vins_pose_client");

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<vins_estimator::GetVinsPose>("get_vins_pose");
  vins_estimator::GetVinsPose srv;
  srv.request.start = true;
  if (client.call(srv))
  {
    ROS_INFO("x: %lf", srv.response.x);
    ROS_INFO("y: %lf", srv.response.y);
    ROS_INFO("z: %lf", srv.response.z);
    ROS_INFO("rx: %lf", srv.response.rx);
    ROS_INFO("ry: %lf", srv.response.ry);
    ROS_INFO("rz: %lf", srv.response.rz);
    ROS_INFO("w: %lf", srv.response.w);
  }
  else
  {
    ROS_ERROR("Failed to call service get_vins_pose");
    return 1;
  }

  return 0;
}