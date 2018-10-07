cmake_minimum_required(VERSION 3.10)
project(ModernC__)

set(CMAKE_CXX_STANDARD 17)
include_directories("${PROJECT_SOURCE_DIR}")

add_executable(ModernC__ main.cpp Mother.h Child.h Mother.cpp Child.cpp)