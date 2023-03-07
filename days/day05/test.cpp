#include <catch2/catch_all.hpp>

#include "day05.h"

TEST_CASE( "Example input data is handled correctly", "[day05 example]" ) {
	using namespace day05;

	const auto& [ container1, container2 ] = read( "days/day05/test.txt" );
	const Structure& structure{ container1, container2 };

	SECTION( "Loaded structure is valid" ) {
		REQUIRE( container1.size() == 3 );
		CHECK( container1[ 0 ] == Crates{ 'Z', 'N' } );
		CHECK( container1[ 1 ] == Crates{ 'M', 'C', 'D' } );
		CHECK( container1[ 2 ] == Crates{ 'P' } );
		
		REQUIRE( container2.size() == 4 );
		CHECK( container2[ 0 ] == Operation{ 1, 2, 1 } );
		CHECK( container2[ 1 ] == Operation{ 3, 1, 3 } );
		CHECK( container2[ 2 ] == Operation{ 2, 2, 1 } );
		CHECK( container2[ 3 ] == Operation{ 1, 1, 2 } );
	}
	SECTION( "Task 1 returns proper output" ) {
		CHECK( structure.determineTopCrates( &Structure::applyOperations ) == "CMZ" );
	}
	SECTION( "Task 2 returns proper output" ) {
		CHECK( structure.determineTopCrates( &Structure::applyOperations2 ) == "MCD" );
	}
}
