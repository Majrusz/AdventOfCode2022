#include <unordered_map>

#include "day02.h"

bool day02::Round::hasPlayerWon() const {
	return this->player == day02::Shape::ROCK && this->opponent == day02::Shape::SCISSORS
		|| this->player == day02::Shape::PAPER && this->opponent == day02::Shape::ROCK
		|| this->player == day02::Shape::SCISSORS && this->opponent == day02::Shape::PAPER;
}

bool day02::Round::isDraw() const {
	return this->player == this->opponent;
}

uint32_t day02::Round::getPointsForSymbol( Shape Round::* shape ) const {
	switch( this->*shape ) {
	case Shape::ROCK:
		return 1;
	case Shape::PAPER:
		return 2;
	case Shape::SCISSORS:
		return 3;
	default:
		throw std::logic_error( "Invalid shape" );
	}
}

uint32_t day02::Round::calculatePoints() const {
	uint32_t points = this->getPointsForSymbol( &Round::player );
	if( this->hasPlayerWon() ) {
		points += 6;
	} else if( this->isDraw() ) {
		points += 3;
	}

	return points;
}

size_t day02::Rounds::calculatePoints() const {
	return std::accumulate( std::begin( this->rounds ), std::end( this->rounds ), 0, []( size_t sum, const Round& round ){
		return sum + round.calculatePoints();
	} );
}

std::istream& day02::operator>>( std::istream& input, Round& round ) {
	static const std::unordered_map< char, day02::Shape > SHAPES_OPPONENT{
		{ 'A', day02::Shape::ROCK },
		{ 'B', day02::Shape::PAPER },
		{ 'C', day02::Shape::SCISSORS },
	};
	static const std::unordered_map< char, day02::Shape > SHAPES_PLAYER{
		{ 'X', day02::Shape::ROCK },
		{ 'Y', day02::Shape::PAPER },
		{ 'Z', day02::Shape::SCISSORS },
	};

	char charOpponent, charPlayer;
	input >> charOpponent >> charPlayer;
	
	round.opponent = SHAPES_OPPONENT.at( charOpponent );
	round.player = SHAPES_PLAYER.at( charPlayer );

	return input;
}
