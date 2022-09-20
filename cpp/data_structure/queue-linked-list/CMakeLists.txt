cmake_minimum_required(VERSION 3.10)

project("Queue LinkedList")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

add_library(queue_lib STATIC
  ./Queue.h
  ./Queue.cc
)

add_executable(main
  ./main.cc
)
target_link_libraries(
  main
  queue_lib
)
