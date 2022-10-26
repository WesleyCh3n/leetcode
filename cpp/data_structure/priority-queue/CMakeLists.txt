cmake_minimum_required(VERSION 3.10)

project(priority_queue)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

add_library(priority_queue STATIC
  ./PriorityQueue.h
  ./PriorityQueue.cc
)

add_executable(main
  main.cc
)

target_link_libraries(main
  priority_queue
)
