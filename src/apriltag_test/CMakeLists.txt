cmake_minimum_required(VERSION 2.8.3)
project(apriltag_test)

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

add_library(apriltag_tests
  STATIC
  src/CameraUtil.cpp
  src/DebugImage.cpp
  src/Geometry.cpp
  src/GrayModel.cpp
  src/MathUtil.cpp
  src/Refine.cpp
  src/TagDetector.cpp
  src/TagFamily.cpp
  src/TagFamilies.cpp
  src/UnionFindSimple.cpp
)

set(AT_LIBS apriltag_tests ${OPENCV_LDFLAGS})
target_link_libraries(apriltag_tests ${AT_LIBS})

add_executable(apriltag_test src/nv_cam.cpp)

link_directories(/usr/local/lib /usr/lib/arm-linux-gnueabihf /usr/lib)
target_link_libraries(
  apriltag_test
  dcam
  ${AT_LIBS}
  ${catkin_LIBRARIES}
# link opencv libraries
  ${OpenCV_LIBRARIES}
)

