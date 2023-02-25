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

