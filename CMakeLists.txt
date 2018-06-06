set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
cmake_minimum_required(VERSION 2.8.3)
project(cnbiros_joystick)
find_package(catkin REQUIRED COMPONENTS roscpp message_generation std_msgs geometry_msgs)


SET(CMAKE_BUILD_TYPE RelWithDebInfo)

include_directories(${catkin_INCLUDE_DIRS} 
		    include)

catkin_package(
  INCLUDE_DIRS 
	include
  LIBRARIES 
	${PROJECT_NAME}
  CATKIN_DEPENDS
  	roscpp
	message_runtime
)


add_executable(joy_filter_control src/joy_filter_control.cpp)
add_dependencies(joy_filter_control cnbiros_wheelchair_generate_messages_cpp)
target_link_libraries(joy_filter_control ${catkin_LIBRARIES})
		

