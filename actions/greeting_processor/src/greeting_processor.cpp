// Copyright 2019 Geoffrey Biggs
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

#include <rclcpp/rclcpp.hpp>
#include <memory>

#include "greeting_processor/greeting_processor_component.hpp"

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::NodeOptions options;
  auto node = std::make_shared<greeting_processor::GreetingProcessor>(options);
  node->make_action_server();
  rclcpp::spin(node);
  rclcpp::shutdown();
}