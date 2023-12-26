cmake_minimum_required(VERSION 3.10)

project(Exercise3)

set (CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_COMPILER "/opt/Homebrew/bin/g++-11")

add_executable(exercise3
    main.cpp
    state_machine.cpp
    stimuli.cpp
)

target_include_directories(exercise3
    PRIVATE $ENV{SYSTEMC_HOME}/include/
)

find_library(SYSTEMC_LIBRARY 
    NAMES systemc
    PATHS /opt/systemc/lib-macosxarm/
)

target_link_libraries(exercise3
    PRIVATE ${SYSTEMC_LIBRARY}
)
