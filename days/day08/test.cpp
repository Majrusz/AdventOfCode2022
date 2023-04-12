#include <catch2/catch_all.hpp>

#include "day08.h"

TEST_CASE( "Example input data is handled correctly", "[day08 example]" ) {
	using namespace day08;

	const auto& forest = read( "days/day08/test.txt" );

	SECTION( "Loaded structure is valid" ) {
		CHECK( forest.getTreeHeight( { 0, 0 } ) == '3' );
		CHECK( forest.getTreeHeight( { 1, 0 } ) == '0' );
		CHECK( forest.getTreeHeight( { 2, 0 } ) == '3' );
		CHECK( forest.getTreeHeight( { 3, 0 } ) == '7' );
		CHECK( forest.getTreeHeight( { 4, 0 } ) == '3' );

		CHECK( forest.getTreeHeight( { 0, 1 } ) == '2' );
		CHECK( forest.getTreeHeight( { 1, 1 } ) == '5' );
		CHECK( forest.getTreeHeight( { 2, 1 } ) == '5' );
		CHECK( forest.getTreeHeight( { 3, 1 } ) == '1' );
		CHECK( forest.getTreeHeight( { 4, 1 } ) == '2' );

		CHECK( forest.getTreeHeight( { 0, 2 } ) == '6' );
		CHECK( forest.getTreeHeight( { 1, 2 } ) == '5' );
		CHECK( forest.getTreeHeight( { 2, 2 } ) == '3' );
		CHECK( forest.getTreeHeight( { 3, 2 } ) == '3' );
		CHECK( forest.getTreeHeight( { 4, 2 } ) == '2' );

		CHECK( forest.getTreeHeight( { 0, 3 } ) == '3' );
		CHECK( forest.getTreeHeight( { 1, 3 } ) == '3' );
		CHECK( forest.getTreeHeight( { 2, 3 } ) == '5' );
		CHECK( forest.getTreeHeight( { 3, 3 } ) == '4' );
		CHECK( forest.getTreeHeight( { 4, 3 } ) == '9' );

		CHECK( forest.getTreeHeight( { 0, 4 } ) == '3' );
		CHECK( forest.getTreeHeight( { 1, 4 } ) == '5' );
		CHECK( forest.getTreeHeight( { 2, 4 } ) == '3' );
		CHECK( forest.getTreeHeight( { 3, 4 } ) == '9' );
		CHECK( forest.getTreeHeight( { 4, 4 } ) == '0' );
	}
	SECTION( "Task 1 returns proper output" ) {
		CHECK( forest.countVisibleTrees() == 21 );
	}
	SECTION( "Task 2 returns proper output" ) {
		CHECK( forest.determineScenicScore() == 8 );
	}
}
