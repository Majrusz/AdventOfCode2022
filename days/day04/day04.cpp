#include <regex>

#include "day04.h"

bool day04::Range::isInside( int value ) const {
    return this->from <= value && value <= this->to;
}

bool day04::Range::operator==( const Range& range ) const {
    return this->from == range.from && this->to == range.to;
}

size_t day04::Pairs::countInsideRanges() const {
    return std::count_if( std::begin( this->pairs ), std::end( this->pairs ), []( const Pair& pair ) {
        const auto& [ elf1, elf2 ] = pair;

        return elf1.isInside( elf2.from ) && elf1.isInside( elf2.to )
            || elf2.isInside( elf1.from ) && elf2.isInside( elf1.to );
    } );
}

size_t day04::Pairs::countOverlapRanges() const {
    return std::count_if( std::begin( this->pairs ), std::end( this->pairs ), []( const Pair& pair ) {
        const auto& [ elf1, elf2 ] = pair;

        return elf1.isInside( elf2.from )
            || elf1.isInside( elf2.to )
            || elf2.isInside( elf1.from )
            || elf2.isInside( elf1.to );
    } );
}

day04::Pair day04::deserialize( std::istream& input ) {
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