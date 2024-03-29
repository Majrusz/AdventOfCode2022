#include <fstream>
#include <string>

#include "file_loader.h"

namespace day03 {
    struct Rucksack {
        std::string merge() const;

        std::string compartment1;
        std::string compartment2;
    };

    class Rucksacks {
    public:
        static size_t calculatePriority( const std::vector< char >& characters );

        Rucksacks( const std::vector< Rucksack >& rucksacks )
            : rucksacks{ rucksacks } {}

        std::vector< char > findCommonCharacters() const;

        std::vector< char > findGroupCharacters() const;

    private:
        std::vector< Rucksack > rucksacks;
    };

    Rucksack deserialize( std::istream& input );
}