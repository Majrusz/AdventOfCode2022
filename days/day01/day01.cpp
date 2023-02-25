#include "day01.h"

day01::Elf day01::Elf::deserialize( std::istream& input ) {
	Elf elf{};
	int calories = 0;
	while( input >> calories ) {
		elf.calories += calories;
			
		input.get();
		int peek = input.peek();
		if( peek == '\n' || peek == EOF )
			break;
	}

	return elf;
}

bool day01::Elf::operator<( const day01::Elf& elf ) const {
	return this->calories < elf.calories;
}

int day01::Elves::getMaxCalories() const {
	return std::max_element( std::begin( elves ), std::end( elves ) )->calories;
}

int day01::Elves::getMaxCalories( int elvesCount ) const {
	std::vector< Elf > copy = this->elves;
	std::sort( std::begin( copy ), std::end( copy ) );

	return std::accumulate( std::rbegin( copy ), std::rbegin( copy ) + elvesCount, 0, []( int sum, const Elf& elf ) {
		return sum + elf.calories;
	} );
}
