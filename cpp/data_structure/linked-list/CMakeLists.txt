cmake_minimum_required(VERSION 3.10)

project("LinkedList")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

add_library(linked_list_lib STATIC
  ./LinkedList.cc
  ./LinkedList.h
)

add_executable(main
  main.cc
)
target_link_libraries(
  main
  linked_list_lib
)
