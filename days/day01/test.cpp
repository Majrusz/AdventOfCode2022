#include <catch2/catch_all.hpp>

#include "day01.h"

TEST_CASE( "Example input data is handled correctly", "[day01 example]" ) {
    using namespace day01;

    const std::vector< Elf >& container{ util::read< Elf >( "days/day01/test.txt", day01::deserialize ) };
    const Elves& elves{ container };

    SECTION( "Loaded structure is valid" ) {
        REQUIRE( container.size() == 5 );
        CHECK( container[ 0 ].calories == 6'000 );
        CHECK( container[ 1 ].calories == 4'000 );
        CHECK( container[ 2 ].calories == 11'000 );
        CHECK( container[ 3 ].calories == 24'000 );
        CHECK( container[ 4 ].calories == 10'000 );
    }
    SECTION( "Task 1 returns proper output" ) {
        CHECK( elves.getMaxCalories() == 24'000 );
    }
    SECTION( "Task 2 returns proper output" ) {
        CHECK( elves.getMaxCalories( 3 ) == 45'000 );
    }
}