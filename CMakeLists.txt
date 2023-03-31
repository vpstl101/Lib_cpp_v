cmake_minimum_required(VERSION 3.24)
project(LibProject1)

set(CMAKE_CXX_STANDARD 17)

add_executable(main.cpp Member.h Member.cpp LoginException.h LibManager.cpp LibManager.h CreatArray.h AdminMode.cpp AdminMode.h BookInfo.cpp BookInfo.h GeneralMode.cpp GeneralMode.h main.cpp)
