cmake_minimum_required(VERSION 2.8.3)
project(dji_sdk_read_cam)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)

## is used, also find other catkin packages
catkin_package()
find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  #opencv2
  roscpp
  sensor_msgs
  std_msgs
)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
# include opencv headers
  ${OpenCV_INCLUDE_DIRS}
)

###########
## Build ##
###########

add_library(apriltags
  STATIC
  CameraUtil.cpp
  DebugImage.cpp
  Geometry.cpp
  GrayModel.cpp
  MathUtil.cpp
  Refine.cpp
  TagDetector.cpp
  TagFamily.cpp
  TagFamilies.cpp
  UnionFindSimple.cpp
)

set(AT_LIBS apriltags ${OPENCV_LDFLAGS})
target_link_libraries(apriltags ${AT_LIBS})

add_executable(dji_sdk_read_cam src/nv_cam.cpp)

link_directories(/usr/local/lib /usr/lib/arm-linux-gnueabihf /usr/lib)
target_link_libraries(
  dji_sdk_read_cam
  dcam
  ${AT_LIBS}
  ${catkin_LIBRARIES}
# link opencv libraries
  ${OpenCV_LIBRARIES}
)

