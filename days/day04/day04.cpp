#include <regex>

#include "day04.h"

day04::Pair day04::Pair::deserialize( std::istream& input ) {
	static const std::regex PATTERN{ "^([0-9]+)-([0-9]+),([0-9]+)-([0-9]+)$" };

	std::string value;
	std::smatch match;
	if( input >> value && std::regex_match( value, match, PATTERN ) ) {
		return Pair{
			Range{ std::stoi( match[ 1 ] ), std::stoi( match[ 2 ] ) },
			Range{ std::stoi( match[ 3 ] ), std::stoi( match[ 4 ] ) }
		};
	}

	throw std::logic_error( "Invalid input data" );
}

bool day04::Range::operator==( const Range& range ) const {
	return this->from == range.from && this->to == range.to;
}

size_t day04::Pairs::countInsideRanges() const {
	return std::count_if( std::begin( this->pairs ), std::end( this->pairs ), []( const Pair& pair ) {
		const auto& [ elf1, elf2 ] = pair;

		if( ( elf1.to - elf1.from ) >= ( elf2.to - elf2.from ) ) {
			return elf1.to >= elf2.to && elf1.from <= elf2.from;
		} else {
			return elf2.to >= elf1.to && elf2.from <= elf1.from;
		} 
	} );
}
