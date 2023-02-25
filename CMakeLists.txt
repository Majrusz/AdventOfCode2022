cmake_minimum_required( VERSION 3.8 )
set( CMAKE_CXX_STANDARD 20 )
include_directories( util )

### Catch2 - unit testing framework for C++
include( FetchContent )

FetchContent_Declare( Catch2 GIT_REPOSITORY https://github.com/catchorg/Catch2.git GIT_TAG v3.0.1 )
FetchContent_MakeAvailable( Catch2 )

### Utility
project( Utility )
add_library( Utility STATIC "util/util.cpp" "util/file_loader.h" )
set_target_properties( Utility PROPERTIES LINKER_LANGUAGE CXX )

### Day 1
project( Day01 )
add_executable( Day01 "days/day01/main.cpp" "days/day01/day01.cpp" "days/day01/day01.h" )
target_link_libraries( Day01 Utility )

project( Day01_Tests )
add_executable( Day01_Tests "days/day01/test.cpp" "days/day01/day01.cpp" "days/day01/day01.h" )
target_link_libraries( Day01_Tests PUBLIC Utility PRIVATE Catch2::Catch2WithMain )
