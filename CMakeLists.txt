cmake_minimum_required(VERSION 3.25)
project(login_register_system)

set(CMAKE_CXX_STANDARD 23)

add_executable(login_register_system main.cpp LoginException.cpp LoginException.h)
