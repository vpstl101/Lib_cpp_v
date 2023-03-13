cmake_minimum_required(VERSION 3.24)
project(LibProject1)

set(CMAKE_CXX_STANDARD 17)

add_executable(LibProject1 main.cpp Member.h Member.h Member.cpp LoginException.h LibManager.cpp LibManager.h Container.h AdminMode.cpp AdminMode.h)
