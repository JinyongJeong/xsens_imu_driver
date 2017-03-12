cmake_minimum_required(VERSION 2.8.3)
project(xsens_imu_driver)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  geometry_msgs
  message_generation
)

add_message_files(
  DIRECTORY msg
)

generate_messages(
  DEPENDENCIES
   std_msgs
   geometry_msgs
)

catkin_package(
  CATKIN_DEPENDS
    std_msgs
    geometry_msgs
    message_runtime
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
link_directories(xsens_imu_lib
  lib/xcommunication
  lib/xstypes
  /usr/local/lib # Location when using 'make system_install'
  /usr/lib       # More usual location (e.g. when installing using a package)
)

add_definitions(-std=c++11)
## Declare executables
add_executable(xsens_imu_driver src/main.cpp src/conio.c src/deviceclass.cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(xsens_imu_driver
  ${catkin_LIBRARIES}
  xcommunication
  xstypes

)
add_dependencies(xsens_imu_driver ${PROJECT_NAME}_generate_messages_cpp)
#add_dependencies(xsens_imu_driver ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
