cmake_minimum_required(VERSION 3.5)

set( CMAKE_CXX_FLAGS "-std=c++11" )

set(CMAKE_CONFIGRATION_TYPES "Release" CACHE STRING "" FORCE)

# opencv库查询
set(OpenCV_DIR $ENV{OPENCV_DIR})
find_package(OpenCV REQUIRED)

# 包含目录
include_directories(${OpenCV_DIR}/install/include)
include_directories(${OpenCV_DIR}/install/include/opencv)
include_directories(${OpenCV_DIR}/install/include/opencv2)

# 查找源文件
aux_source_directory(. DIR_SRCS)

# 查找头文件
file(GLOB HEADER ./*.h)

# 生成目标信息
set(EXENAME 02_hash)
add_executable(${EXENAME} ${DIR_SRCS} ${HEADER})
target_link_libraries (${EXENAME} ${OpenCV_LIBS})
