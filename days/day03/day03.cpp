#include <numeric>
#include <unordered_set>

#include "day03.h"

day03::Rucksack day03::Rucksack::deserialize( std::istream& input ) {
	std::string compartments;
	input >> compartments;
	size_t mid = compartments.size() / 2;

	return Rucksack{ compartments.substr( 0, mid ), compartments.substr( mid ) };
}

std::string day03::Rucksack::merge() const {
	return this->compartment1 + this->compartment2;
}

size_t day03::Rucksacks::calculatePriority( const std::vector< char >& characters ) {
	return std::accumulate( std::begin( characters ), std::end( characters ), 0, []( size_t sum, char character ){
		return sum + ( character <= 'Z' ? 27 + character - 'A' : 1 + character - 'a' );
	} );
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

std::vector< char > day03::Rucksacks::findGroupCharacters() const {
	std::vector< char > group;
	group.reserve( this->rucksacks.size() / 3 );
	for( auto it = std::begin( this->rucksacks ); it != std::end( this->rucksacks ); it += 3 ) {
		std::unordered_set< char > unique1, unique2;
		for( char c : it->merge() ) {
			unique1.insert( c );
		}
		for( char c : ( it + 1 )->merge() ) {
			unique2.insert( c );
		}
		for( char c : ( it + 2 )->merge() ) {
			if( unique1.find( c ) != std::end( unique1 ) && unique2.find( c ) != std::end( unique2 ) ) {
				group.push_back( c );
				break;
			}
		}
	}

	return group;
}