cmake_minimum_required( VERSION 3.8 )
set( CMAKE_CXX_STANDARD 17 )

### Solutions
project( AdventOfCode2022 )

add_executable( AdventOfCode2022 "main.cpp" )

### Unit tests
project( AdventOfCode2022Tests )

include( FetchContent )

FetchContent_Declare( Catch2 GIT_REPOSITORY https://github.com/catchorg/Catch2.git GIT_TAG v3.0.1 )
FetchContent_MakeAvailable( Catch2 )

add_executable( AdventOfCode2022Tests "test.cpp" )
target_link_libraries( AdventOfCode2022Tests PRIVATE Catch2::Catch2WithMain )
