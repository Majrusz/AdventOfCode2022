#include <deque>
#include <fstream>

#include "file_loader.h"

namespace day05 {
	using Crates = std::deque< char >;

	struct Operation {
		bool operator==( const Operation& operation ) const;

		unsigned count;
		unsigned from;
		unsigned to;
	};
	
	class Structure {
	public:
		Structure( const std::vector< Crates >& stacks, const std::vector< Operation >& operations ) : stacks{ stacks }, operations{ operations } {}

		std::vector< Crates > applyOperations() const;

		std::vector< Crates > applyOperations2() const;

		std::string determineTopCrates( std::vector< Crates >( Structure::*method )() const ) const;

	private:
		std::vector< Crates > stacks;
		std::vector< Operation > operations;
	};

	std::vector< Crates > deserializeStacks( std::istream& input );

	std::vector< Operation > deserializeOperations( std::istream& input );

	std::pair< std::vector< Crates >, std::vector< Operation > > read( std::string_view filename );
}