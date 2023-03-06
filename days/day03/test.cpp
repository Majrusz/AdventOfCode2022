#include <catch2/catch_all.hpp>

#include "day03.h"

TEST_CASE( "Example input data is handled correctly", "[day03 example]" ) {
	using namespace day03;
	
	const std::vector< Rucksack >& container{ util::read< Rucksack >( "days/day03/test.txt", &day03::deserialize ) };
	const Rucksacks& rucksacks{ container };

	SECTION( "Loaded structure is valid" ) {
		REQUIRE( container.size() == 6 );
		CHECK( container[ 0 ].compartment1 == "vJrwpWtwJgWr" );
		CHECK( container[ 0 ].compartment2 == "hcsFMMfFFhFp" );
		CHECK( container[ 1 ].compartment1 == "jqHRNqRjqzjGDLGL" );
		CHECK( container[ 1 ].compartment2 == "rsFMfFZSrLrFZsSL" );
		CHECK( container[ 2 ].compartment1 == "PmmdzqPrV" );
		CHECK( container[ 2 ].compartment2 == "vPwwTWBwg" );
		CHECK( container[ 3 ].compartment1 == "wMqvLMZHhHMvwLH" );
		CHECK( container[ 3 ].compartment2 == "jbvcjnnSBnvTQFn" );
		CHECK( container[ 4 ].compartment1 == "ttgJtRGJ" );
		CHECK( container[ 4 ].compartment2 == "QctTZtZT" );
		CHECK( container[ 5 ].compartment1 == "CrZsJsPPZsGz" );
		CHECK( container[ 5 ].compartment2 == "wwsLwLmpwMDw" );
	}
	SECTION( "Task 1 returns proper output" ) {
		const std::vector< char >& common = rucksacks.findCommonCharacters();
		REQUIRE( common.size() == 6 );
		CHECK( common[ 0 ] == 'p' );
		CHECK( common[ 1 ] == 'L' );
		CHECK( common[ 2 ] == 'P' );
		CHECK( common[ 3 ] == 'v' );
		CHECK( common[ 4 ] == 't' );
		CHECK( common[ 5 ] == 's' );
		CHECK( Rucksacks::calculatePriority( common ) == 157 );
	}
	SECTION( "Task 2 returns proper output" ) {
		const std::vector< char >& group = rucksacks.findGroupCharacters();
		REQUIRE( group.size() == 2 );
		CHECK( group[ 0 ] == 'r' );
		CHECK( group[ 1 ] == 'Z' );
		CHECK( Rucksacks::calculatePriority( group ) == 70 );
	}
}
