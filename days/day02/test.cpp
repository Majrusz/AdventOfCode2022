#include <catch2/catch_all.hpp>

#include "day02.h"

TEST_CASE( "Example input data is handled correctly" ) {
	using namespace day02;

	const std::vector< Round >& container{ util::read< Round >( "days/day02/test.txt" ) };
	const Rounds& rounds{ container };

	SECTION( "Loaded structure is valid" ) {
		REQUIRE( container.size() == 3 );
		CHECK( container[ 0 ].player == Shape::PAPER );
		CHECK( container[ 0 ].opponent == Shape::ROCK );
		CHECK( container[ 1 ].player == Shape::ROCK );
		CHECK( container[ 1 ].opponent == Shape::PAPER );
		CHECK( container[ 2 ].player == Shape::SCISSORS );
		CHECK( container[ 2 ].opponent == Shape::SCISSORS );
	}
	SECTION( "Task 1 returns proper output" ) {
		CHECK( rounds.calculatePoints() == 15 );
	}
}