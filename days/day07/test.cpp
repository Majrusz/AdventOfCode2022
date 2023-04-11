#include <catch2/catch_all.hpp>

#include "day07.h"

TEST_CASE( "Example input data is handled correctly", "[day07 example]" ) {
	using namespace day07;

	const auto& container = read( "days/day07/test.txt" );
	const auto& filesystem = Commands{ container }.toFilesystem();

	SECTION( "Loaded structure is valid" ) {
		REQUIRE( container.size() == 10 );

		CHECK( container[ 0 ].input == "cd /" );
		CHECK( container[ 0 ].output == std::vector< std::string >{} );

		CHECK( container[ 1 ].input == "ls" );
		CHECK( container[ 1 ].output == std::vector< std::string >{ "dir a", "14848514 b.txt", "8504156 c.dat", "dir d" } );

		CHECK( container[ 2 ].input == "cd a" );
		CHECK( container[ 2 ].output == std::vector< std::string >{} );

		CHECK( container[ 3 ].input == "ls" );
		CHECK( container[ 3 ].output == std::vector< std::string >{ "dir e", "29116 f", "2557 g", "62596 h.lst" } );

		CHECK( container[ 4 ].input == "cd e" );
		CHECK( container[ 4 ].output == std::vector< std::string >{} );

		CHECK( container[ 5 ].input == "ls" );
		CHECK( container[ 5 ].output == std::vector< std::string >{ "584 i" } );

		CHECK( container[ 6 ].input == "cd .." );
		CHECK( container[ 6 ].output == std::vector< std::string >{} );

		CHECK( container[ 7 ].input == "cd .." );
		CHECK( container[ 7 ].output == std::vector< std::string >{} );

		CHECK( container[ 8 ].input == "cd d" );
		CHECK( container[ 8 ].output == std::vector< std::string >{} );

		CHECK( container[ 9 ].input == "ls" );
		CHECK( container[ 9 ].output == std::vector< std::string >{ "4060174 j", "8033020 d.log", "5626152 d.ext", "7214296 k" } );
	}
	SECTION( "Task 1 returns proper output" ) {
		const auto& directories = filesystem.findAllDirectories();
		CHECK( directories.size() == 4 );
		CHECK( filesystem.sumDirectoriesSmallerThan( 100'000 ) == 95'437 );
	}
}
