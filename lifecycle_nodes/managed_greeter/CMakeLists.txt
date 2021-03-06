cmake_minimum_required(VERSION 3.5)
project(managed_greeter)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(greeting_msg REQUIRED)
find_package(class_loader REQUIRED)
find_package(lifecycle_msgs REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)

include_directories(include)

add_library(managed_greeter_component SHARED src/managed_greeter_component.cpp)
target_compile_definitions(managed_greeter_component PRIVATE "GREETER_BUILDING_DLL")
ament_target_dependencies(managed_greeter_component
  rclcpp
  greeting_msg
  class_loader
  lifecycle_msgs
  rclcpp_lifecycle
  )
rclcpp_register_node_plugins(managed_greeter_component "managed_greeter::Greeter")

add_executable(managed_greeter src/managed_greeter.cpp)
target_link_libraries(managed_greeter managed_greeter_component)
ament_target_dependencies(managed_greeter
  rclcpp
  greeting_msg
  lifecycle_msgs
  rclcpp_lifecycle
  )

ament_export_dependencies(ament_cmake)
ament_export_dependencies(rclcpp)
ament_export_dependencies(class_loader)
ament_export_dependencies(greeting_msg)
ament_export_dependencies(lifecycle_msgs)
ament_export_dependencies(rclcpp_lifecycle)

ament_export_include_directories(include)

ament_export_libraries(greeter_component)

install(DIRECTORY
  include/managed_greeter
  DESTINATION include
  )

install(TARGETS
  managed_greeter_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  )

install(TARGETS
  managed_greeter
  DESTINATION lib/${PROJECT_NAME}
  )

ament_package()
