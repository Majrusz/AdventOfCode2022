#include <algorithm>
#include <fstream>
#include <numeric>
#include <string_view>
#include <vector>

#include "file_loader.h"

namespace day01 {
	struct Elf {
		static Elf deserialize( std::istream& input );

		bool operator<( const Elf& elf ) const;
		
		int calories = 0;
	};

	class Elves {
	public:
		Elves( const std::vector< Elf >& elves ) : elves{ elves } {}
	
		int getMaxCalories() const;

		int getMaxCalories( int elvesCount ) const;

	private:
		const std::vector< Elf >& elves;
	};
}