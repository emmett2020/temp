cmake_minimum_required(VERSION 3.13)
project(test)

set(CMAKE_CXX_STANDARD 23)
set(CXX_STANDARD_REQUIRED true)

OPTION (ENABLE_COVERAGE "Enable coverage" ON)
IF(ENABLE_COVERAGE)
  message(STATUS ENABLE_COVERAGE=${ENABLE_COVERAGE})
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage ")
  set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} --coverage ")
ENDIF()

set(SRC_FILE main.cpp)
add_executable(main ${SRC_FILE})
