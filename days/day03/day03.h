#include <fstream>
#include <string>

#include "file_loader.h"

namespace day03 {
	struct Rucksack {
		static Rucksack deserialize( std::istream& input );

		std::string compartment1;
		std::string compartment2;
	};
	
	class Rucksacks {
	public:
		Rucksacks( const std::vector< Rucksack >& rucksacks ) : rucksacks{ rucksacks } {}

		std::vector< char > findCommonCharacters() const;

		size_t calculatePriority() const;

	private:
		std::vector< Rucksack > rucksacks;
	};
}