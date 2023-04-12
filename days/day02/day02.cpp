#include <unordered_map>

#include "day02.h"

size_t day02::Round::calculatePoints() const {
    return static_cast< size_t >( this->player ) + static_cast< size_t >( determineResult( this->player, this->opponent ) );
}

size_t day02::Rounds::calculatePoints() const {
    return std::accumulate( std::begin( this->rounds ), std::end( this->rounds ), 0, []( size_t sum, const Round& round ) {
        return sum + round.calculatePoints();
    } );
}

day02::Result day02::determineResult( Shape player, Shape opponent ) {
    static const std::unordered_map< Shape, Shape > BEATS_SYMBOL{
        { Shape::ROCK, Shape::SCISSORS },
        { Shape::PAPER, Shape::ROCK },
        { Shape::SCISSORS, Shape::PAPER },
    };

    if( BEATS_SYMBOL.at( player ) == opponent ) {
        return Result::WIN;
    } else if( player == opponent ) {
        return Result::DRAW;
    } else {
        return Result::LOSE;
    }
}

day02::Shape day02::determinePlayer( Shape opponent, Result result ) {
    for( Shape player : { Shape::ROCK, Shape::PAPER, Shape::SCISSORS } ) {
        if( determineResult( player, opponent ) == result )
            return player;
    }
}

day02::Round day02::deserialize( std::istream& input ) {
    static const std::unordered_map< char, Shape > SHAPES_OPPONENT{
        { 'A', Shape::ROCK },
        { 'B', Shape::PAPER },
        { 'C', Shape::SCISSORS },
    };
    static const std::unordered_map< char, Shape > SHAPES_PLAYER{
        { 'X', Shape::ROCK },
        { 'Y', Shape::PAPER },
        { 'Z', Shape::SCISSORS },
    };

    char charOpponent, charPlayer;
    input >> charOpponent >> charPlayer;

    return Round{ SHAPES_OPPONENT.at( charOpponent ), SHAPES_PLAYER.at( charPlayer ) };
}

day02::Round day02::deserialize2( std::istream& input ) {
    static const std::unordered_map< char, Shape > SHAPES_OPPONENT{
        { 'A', Shape::ROCK },
        { 'B', Shape::PAPER },
        { 'C', Shape::SCISSORS },
    };
    static const std::unordered_map< char, Result > RESULTS_PLAYER{
        { 'X', Result::LOSE },
        { 'Y', Result::DRAW },
        { 'Z', Result::WIN },
    };

    char charOpponent, charPlayer;
    input >> charOpponent >> charPlayer;

    return Round{ SHAPES_OPPONENT.at( charOpponent ), determinePlayer( SHAPES_OPPONENT.at( charOpponent ), RESULTS_PLAYER.at( charPlayer ) ) };
}
