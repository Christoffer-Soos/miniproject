cmake_minimum_required(VERSION 2.8.3)
project(project1)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS roslib roscpp geometry_msgs move_base_msgs actionlib genmsg)
find_package(std_msgs REQUIRED)

###################################
## catkin specific configuration ##
###################################
catkin_package(
)

###########
## Build ##
###########
include_directories(
  ${catkin_INCLUDE_DIRS}
  ${std_msgs_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_miniproject src/miniproject.cpp)
set_target_properties(${PROJECT_NAME}_miniproject PROPERTIES OUTPUT_NAME miniproject PREFIX "")
target_link_libraries(${PROJECT_NAME}_miniproject
  ${catkin_LIBRARIES}
  ${std_msgs_LIBRARIES}
)

add_executable(${PROJECT_NAME}_publishminiproject src/publishminiproject.cpp)
set_target_properties(${PROJECT_NAME}_publishminiproject PROPERTIES OUTPUT_NAME publishminiproject PREFIX "")
target_link_libraries(${PROJECT_NAME}_publishminiproject
  ${catkin_LIBRARIES}
  ${std_msgs_LIBRARIES}
)

#############
## Install ##
#############

# Mark executables for installation
install(TARGETS
  ${PROJECT_NAME}_miniproject
  ${PROJECT_NAME}_publishminiproject
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
