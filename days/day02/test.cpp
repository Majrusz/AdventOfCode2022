#include <catch2/catch_all.hpp>

#include "day02.h"

TEST_CASE( "Example input data is handled correctly", "[day02 example]" ) {
    using namespace day02;

    SECTION( "Task1" ) {
        const std::vector< Round >& container{ util::read< Round >( "days/day02/test.txt", &day02::deserialize ) };
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

    SECTION( "Task2" ) {
        const std::vector< Round >& container{ util::read< Round >( "days/day02/test.txt", &day02::deserialize2 ) };
        const Rounds& rounds{ container };

        SECTION( "Loaded structure is valid" ) {
            REQUIRE( container.size() == 3 );
            CHECK( container[ 0 ].player == Shape::ROCK );
            CHECK( container[ 0 ].opponent == Shape::ROCK );
            CHECK( container[ 1 ].player == Shape::ROCK );
            CHECK( container[ 1 ].opponent == Shape::PAPER );
            CHECK( container[ 2 ].player == Shape::ROCK );
            CHECK( container[ 2 ].opponent == Shape::SCISSORS );
        }
        SECTION( "Task 2 returns proper output" ) {
            CHECK( rounds.calculatePoints() == 12 );
        }
    }
}

TEST_CASE( "Function determineResult() determines proper output", "[day02 result]" ) {
    using namespace day02;

    CHECK( determineResult( Shape::ROCK, Shape::ROCK ) == Result::DRAW );
    CHECK( determineResult( Shape::ROCK, Shape::PAPER ) == Result::LOSE );
    CHECK( determineResult( Shape::ROCK, Shape::SCISSORS ) == Result::WIN );
    CHECK( determineResult( Shape::PAPER, Shape::ROCK ) == Result::WIN );
    CHECK( determineResult( Shape::PAPER, Shape::PAPER ) == Result::DRAW );
    CHECK( determineResult( Shape::PAPER, Shape::SCISSORS ) == Result::LOSE );
    CHECK( determineResult( Shape::SCISSORS, Shape::ROCK ) == Result::LOSE );
    CHECK( determineResult( Shape::SCISSORS, Shape::PAPER ) == Result::WIN );
    CHECK( determineResult( Shape::SCISSORS, Shape::SCISSORS ) == Result::DRAW );
}

TEST_CASE( "Function determinePlayer() determines proper output", "[day02 shape]" ) {
    using namespace day02;

    CHECK( determinePlayer( Shape::ROCK, Result::WIN ) == Shape::PAPER );
    CHECK( determinePlayer( Shape::ROCK, Result::DRAW ) == Shape::ROCK );
    CHECK( determinePlayer( Shape::ROCK, Result::LOSE ) == Shape::SCISSORS );
    CHECK( determinePlayer( Shape::PAPER, Result::WIN ) == Shape::SCISSORS );
    CHECK( determinePlayer( Shape::PAPER, Result::DRAW ) == Shape::PAPER );
    CHECK( determinePlayer( Shape::PAPER, Result::LOSE ) == Shape::ROCK );
    CHECK( determinePlayer( Shape::SCISSORS, Result::WIN ) == Shape::ROCK );
    CHECK( determinePlayer( Shape::SCISSORS, Result::DRAW ) == Shape::SCISSORS );
    CHECK( determinePlayer( Shape::SCISSORS, Result::LOSE ) == Shape::PAPER );
}