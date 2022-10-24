cmake_minimum_required(VERSION 3.10)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

add_library(BST STATIC
  ./BinarySearchTreeSimple.h
  ./BinarySearchTreeSimple.cc
)

add_executable(main
  main.cc
)

target_link_libraries(main
  BST
)
