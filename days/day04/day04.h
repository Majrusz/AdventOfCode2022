#include <fstream>

#include "file_loader.h"

namespace day04 {
    struct Range {
        bool isInside( int value ) const;

        bool operator==( const Range& range ) const;

        int from, to;
    };

    struct Pair {
        Range elf1;
        Range elf2;
    };

    class Pairs {
    public:
        Pairs( const std::vector< Pair >& pairs )
            : pairs{ pairs } {}

        size_t countInsideRanges() const;

        size_t countOverlapRanges() const;

    private:
        std::vector< Pair > pairs;
    };

    Pair deserialize( std::istream& input );
}