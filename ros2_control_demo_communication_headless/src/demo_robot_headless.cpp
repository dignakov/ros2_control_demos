// Copyright 2020 ROS2-Control Development Team
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "ros2_control_demo_communication_headless/demo_robot_headless.hpp"

using namespace ros2_control_demo_communication_headless;

ros2_control_types::return_type DemoRobotHeadless::configure(const std::string parameters_path, const rclcpp::node_interfaces::NodeLoggingInterface::SharedPtr logging_interface,  const rclcpp::node_interfaces::NodeParametersInterface::SharedPtr parameters_interface, const rclcpp::node_interfaces::NodeServicesInterface::SharedPtr services_interface)
{
  ros2_control_types::return_type ret;
  ret = HardwareCommunicationInterface::configure(parameters_path, logging_interface, parameters_interface, services_interface);

  RCLCPP_INFO(logging_interface_->get_logger(), "Configuring DemoRobotHeadless communication ...");

  return ret;
}

ros2_control_types::return_type DemoRobotHeadless::init()
{
  RCLCPP_INFO(logging_interface_->get_logger(), "Initalizing DemoRobotHeadless communication ...please wait...");

  for (int i=0; i < 2; i++)
  {
    rclcpp::sleep_for(std::chrono::milliseconds(1*1000/2));
    RCLCPP_INFO(logging_interface_->get_logger(), "%f seconds left...", 1-(i/2.0));
  }

  RCLCPP_INFO(logging_interface_->get_logger(), "DemoRobotHeadless communication sucessfully initalized!");

  return ros2_control_types::ROS2C_RETURN_OK;
}

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(
  ros2_control_demo_communication_headless::DemoRobotHeadless, ros2_control_core_communication_interface::HardwareCommunicationInterface)