#include <catch2/catch_all.hpp>

#include "day01.h"

TEST_CASE( "Example input data is handled correctly" ) {
	using namespace day01;

	const std::vector< Elf >& elves = util::read< Elf >( "days/day01/test.txt" );

	SECTION( "Loaded structure is valid" ) {
		REQUIRE( elves.size() == 5 );
		CHECK( elves[ 0 ].calories == 6'000 );
		CHECK( elves[ 1 ].calories == 4'000 );
		CHECK( elves[ 2 ].calories == 11'000 );
		CHECK( elves[ 3 ].calories == 24'000 );
		CHECK( elves[ 4 ].calories == 10'000 );
	}
	SECTION( "Task 1 returns proper output" ) {
		CHECK( getMaxCalories( elves ) == 24'000 );
	}
}