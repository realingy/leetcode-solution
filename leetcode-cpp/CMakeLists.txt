cmake_minimum_required(VERSION 3.5)

# 设置C++标准为C++17
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 工程信息
project(LeetCodeSolutionCpp)

set(OPENCV_ROOT_DIR ${PROJECT_SOURCE_DIR}/thirdparty/opencv)
set(OPENCV_LIBRARIES_DIR ${OPENCV_ROOT_DIR}/lib)
find_library(OPENCV401_LIBRARIES NAMES opencv_world401 PATHS ${OPENCV_LIBRARIES_DIR})
set(OPENCV_INCLUDES_DIR ${OPENCV_ROOT_DIR}/include)
include_directories(${OPENCV_INCLUDES_DIR})

# include_directories(${CMAKE_SOURCE_DIR}/..)

# add_subdirectory(0_string)
# add_subdirectory(array)
# add_subdirectory(hash)

# 0_string
set(EXENAME Leetcode)
add_executable(${EXENAME} 
    LeetString.cpp 
    LeetString.h 
    LeetSort.cpp 
    LeetSort.h 
    LeetDP.cpp 
    LeetDP.h 
    LeetHash.cpp 
    LeetHash.h 
    LeetBTree.cpp 
    LeetBTree.h 
    LeetDFS.cpp 
    LeetDFS.h 
    LeetStack.cpp 
    LeetStack.h 
    LeetArray.cpp 
    LeetArray.h 
    LeetBit.cpp 
    LeetBit.h 
    LeetList.cpp 
    LeetList.h 
    main.cpp
    data.h
)

target_link_libraries (${EXENAME} ${OPENCV401_LIBRARIES})

