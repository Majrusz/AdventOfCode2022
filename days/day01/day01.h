#include <algorithm>
#include <fstream>
#include <numeric>
#include <string_view>
#include <vector>

#include "file_loader.h"

namespace day01 {
	using Elves = std::vector< struct Elf >;

	struct Elf {
		int calories = 0;

		bool operator<( const Elf& elf ) const {
			return this->calories < elf.calories;
		}
	};

	std::istream& operator>>( std::istream& input, Elf& elf ) {
		int calories = 0;
		while( input >> calories ) {
			elf.calories += calories;
			
			input.get();
			int peek = input.peek();
			if( peek == '\n' || peek == EOF )
				break;
		}

		return input;
	}

	int getMaxCalories( const Elves& elves ) {
		return std::max_element( std::begin( elves ), std::end( elves ) )->calories;
	}

	int getMaxCalories( const Elves& elves, int elvesCount ) {
		Elves copy = elves;
		std::sort( std::begin( copy ), std::end( copy ) );

		return std::accumulate( std::rbegin( copy ), std::rbegin( copy ) + elvesCount, 0, []( int sum, const Elf& elf ) { return sum + elf.calories; } );
	}
}