cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(opencv_traj)

find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem)

include_directories(opencv_traj ${EIGEN3_INCLUDE_DIR})
add_executable (opencv_traj 
  opencv_traj.cpp
#  lkdemo.cpp
)
target_link_libraries(opencv_traj ${OpenCV_LIBS} ${Boost_LIBRARIES})
