#include <algorithm>
#include <fstream>
#include <string_view>
#include <vector>

#include "file_loader.h"

namespace day01 {
	struct Elf {
		int calories = 0;
	};

	int getMaxCalories( const std::vector< Elf >& elves ) {
		return std::max_element( std::begin( elves ), std::end( elves ), []( const Elf& elf1, const Elf& elf2 ){
			return elf1.calories < elf2.calories;
		} )->calories;
	}

	std::istream &operator>>( std::istream &input, Elf &elf ) {
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
}