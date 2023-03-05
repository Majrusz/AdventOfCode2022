#include <fstream>

#include "file_loader.h"

namespace day04 {
	struct Range {
		int from, to;

		bool operator==( const Range& range ) const;
	};

	struct Pair {
		static Pair deserialize( std::istream& input );

		Range elf1;
		Range elf2;
	};
	
	class Pairs {
	public:
		Pairs( const std::vector< Pair >& pairs ) : pairs{ pairs } {}

		size_t countInsideRanges() const;

	private:
		std::vector< Pair > pairs;
	};
}