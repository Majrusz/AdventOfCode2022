#include <numeric>
#include <unordered_set>

#include "day03.h"

day03::Rucksack day03::Rucksack::deserialize( std::istream& input ) {
	std::string compartments;
	input >> compartments;
	size_t mid = compartments.size() / 2;

	return Rucksack{ compartments.substr( 0, mid ), compartments.substr( mid ) };
}

std::vector< char > day03::Rucksacks::findCommonCharacters() const {
	std::vector< char > common;
	common.reserve( this->rucksacks.size() );
	for( const Rucksack& rucksack : this->rucksacks ) {
		std::unordered_set< char > unique;
		unique.reserve( rucksack.compartment1.size() );
		for( char c : rucksack.compartment1 ) {
			unique.insert( c );
		}

		for( char c : rucksack.compartment2 ) {
			if( unique.find( c ) != std::end( unique ) ) {
				common.push_back( c );
				break;
			}
		}
	}

	return common;
}

size_t day03::Rucksacks::calculatePriority() const {
	const std::vector< char >& common = this->findCommonCharacters();

	return std::accumulate( std::begin( common ), std::end( common ), 0, []( size_t sum, char character ){
		return sum + ( character <= 'Z' ? 27 + character - 'A' : 1 + character - 'a' );
	} );
}
