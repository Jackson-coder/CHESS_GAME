# cmake_minimum_required(VERSION 3.0.0)
# project(chessboard VERSION 0.1.0)

# add_library(chessboard SHARED chessboard.cpp)

# include_directories("${PROJECT_SOURCE_DIR}/chessboard/")

# install(TARGETS chessboard LIBRARY DESTINATION lib)

# target_include_directories(chessboard PUBLIC include)

# cmake_minimum_required(VERSION 3.0.0)
# project(chessboard VERSION 0.1.0)
# set(CMAKE_BUILD_TYPE "Debug")

# include(CTest)
# enable_testing()

include_directories("/home/lin/catkin_ws/src/using_markers/src/chessboard")

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

add_library(chessboard SHARED chessboard.cpp)

# set("/home/lin/catkin_ws/build/using_markers/src/chessboard" ${CMAKE_SOURCE_DIR}/lib)