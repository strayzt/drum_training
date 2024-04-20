cmake_minimum_required(VERSION 3.0)
project(drum_training)


find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(reaction ./src/reaction.cc)
target_link_libraries(reaction ${OpenCV_LIBS})
