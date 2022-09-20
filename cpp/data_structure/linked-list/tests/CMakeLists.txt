cmake_minimum_required(VERSION 3.13)

project("LinkedList test")
enable_testing()

set(CMAKE_CXX_STANDARD 17)

set(TEST_CASES
  test_reverse
)

add_library(linked_list_lib STATIC
  ../LinkedList.cc
  ../LinkedList.h
)

foreach(TEST ${TEST_CASES})
  # target executable
  add_executable(${TEST} ${TEST}.cc)
  # target link to library
  target_link_libraries(${TEST} linked_list_lib)
  # now register the executable with CTest
  add_test(NAME ${TEST} COMMAND ${TEST})
endforeach()
