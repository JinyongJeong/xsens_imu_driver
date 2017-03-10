cmake_minimum_required(VERSION 2.8.3)
project(xsens_imu_driver)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  sensor_msgs
)

###################################
## catkin specific configuration ##
###################################

catkin_package(
  CATKIN_DEPENDS
  roscpp
  std_msgs
  sensor_msgs
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  /usr/local/include # Location when using 'make system_install'
  /usr/include       # More usual location (e.g. when installing using a package)
)

## Specify additional locations for the xsens library
link_directories(
  lib/xcommunication
  lib/xstypes
  /usr/local/lib # Location when using 'make system_install'
  /usr/lib       # More usual location (e.g. when installing using a package)
)

## Declare executables
add_executable(xsens_imu_driver src/main.cpp src/conio.c src/deviceclass.cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(xsens_imu_driver
  xcommunication
  xstypes
  ${catkin_LIBRARIES}
)
