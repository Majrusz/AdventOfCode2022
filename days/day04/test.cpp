#include <catch2/catch_all.hpp>

#include "day04.h"

TEST_CASE( "Example input data is handled correctly", "[day04 example]" ) {
	using namespace day04;

	const std::vector< Pair >& container{ util::read< Pair >( "days/day04/test.txt", &Pair::deserialize ) };
	const Pairs& pairs{ container };

	SECTION( "Loaded structure is valid" ) {
		REQUIRE( container.size() == 6 );
		CHECK( container[ 0 ].elf1 == Range{ 2, 4 } );
		CHECK( container[ 0 ].elf2 == Range{ 6, 8 } );
		CHECK( container[ 1 ].elf1 == Range{ 2, 3 } );
		CHECK( container[ 1 ].elf2 == Range{ 4, 5 } );
		CHECK( container[ 2 ].elf1 == Range{ 5, 7 } );
		CHECK( container[ 2 ].elf2 == Range{ 7, 9 } );
		CHECK( container[ 3 ].elf1 == Range{ 2, 8 } );
		CHECK( container[ 3 ].elf2 == Range{ 3, 7 } );
		CHECK( container[ 4 ].elf1 == Range{ 6, 6 } );
		CHECK( container[ 4 ].elf2 == Range{ 4, 6 } );
		CHECK( container[ 5 ].elf1 == Range{ 2, 6 } );
		CHECK( container[ 5 ].elf2 == Range{ 4, 8 } );
	}
	SECTION( "Task 1 returns proper output" ) {
		CHECK( pairs.countInsideRanges() == 2 );
	}
}
