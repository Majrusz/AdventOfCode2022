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

### All Units Tests (utility + all days)
project( AllUnitTests )
add_executable( AllUnitTests
	"days/day01/test.cpp" "days/day01/day01.cpp" "days/day01/day01.h"
	"days/day02/test.cpp" "days/day02/day02.cpp" "days/day02/day02.h"
	"days/day03/test.cpp" "days/day03/day03.cpp" "days/day03/day03.h"
	"days/day04/test.cpp" "days/day04/day04.cpp" "days/day04/day04.h"
)
target_link_libraries( AllUnitTests PUBLIC Utility PRIVATE Catch2::Catch2WithMain )

### Day 1
project( Day01 )
add_executable( Day01 "days/day01/main.cpp" "days/day01/day01.cpp" "days/day01/day01.h" )
target_link_libraries( Day01 Utility )

project( Day01_Tests )
add_executable( Day01_Tests "days/day01/test.cpp" "days/day01/day01.cpp" "days/day01/day01.h" )
target_link_libraries( Day01_Tests PUBLIC Utility PRIVATE Catch2::Catch2WithMain )

### Day 2
project( Day02 )
add_executable( Day02 "days/day02/main.cpp" "days/day02/day02.cpp" "days/day02/day02.h" )
target_link_libraries( Day02 Utility )

project( Day02_Tests )
add_executable( Day02_Tests "days/day02/test.cpp" "days/day02/day02.cpp" "days/day02/day02.h" )
target_link_libraries( Day02_Tests PUBLIC Utility PRIVATE Catch2::Catch2WithMain )

### Day 3
project( Day03 )
add_executable( Day03 "days/day03/main.cpp" "days/day03/day03.cpp" "days/day03/day03.h" )
target_link_libraries( Day03 Utility )

project( Day03_Tests )
add_executable( Day03_Tests "days/day03/test.cpp" "days/day03/day03.cpp" "days/day03/day03.h" )
target_link_libraries( Day03_Tests PUBLIC Utility PRIVATE Catch2::Catch2WithMain )

### Day 4
project( Day04 )
add_executable( Day04 "days/day04/main.cpp" "days/day04/day04.cpp" "days/day04/day04.h" )
target_link_libraries( Day04 Utility )

project( Day04_Tests )
add_executable( Day04_Tests "days/day04/test.cpp" "days/day04/day04.cpp" "days/day04/day04.h" )
target_link_libraries( Day04_Tests PUBLIC Utility PRIVATE Catch2::Catch2WithMain )