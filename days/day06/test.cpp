#include <catch2/catch_all.hpp>

#include "day06.h"

TEST_CASE( "Example input data is handled correctly", "[day06 example]" ) {
    using namespace day06;

    const std::string& input = util::read( "days/day06/test.txt" );
    Signal signal{ input };

    SECTION( "Loaded structure is valid" ) {
        CHECK( input == "mjqjpqmgbljsphdztnvjfqwrcgsmlb" );
    }
    SECTION( "Task 1 returns proper output" ) {
        CHECK( signal.findMarkerIdx() == 7 );
    }
    SECTION( "Task 2 returns proper output" ) {
        CHECK( signal.findMarkerIdx( 14 ) == 19 );
    }
}
