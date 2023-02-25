#include <algorithm>
#include <fstream>
#include <numeric>
#include <string_view>
#include <vector>

#include "file_loader.h"

namespace day02 {
	enum class Shape : uint8_t {
		ROCK, PAPER, SCISSORS
	};
	
	struct Round {
		Shape opponent;
		Shape player;

		bool hasPlayerWon() const;

		bool isDraw() const;

		uint32_t getPointsForSymbol( Shape Round::* shape ) const;

		uint32_t calculatePoints() const;
	};

	class Rounds {
	public:
		Rounds( const std::vector< Round >& rounds ) : rounds{ rounds } {}
	
		size_t calculatePoints() const;

	private:
		std::vector< Round > rounds;
	};

	std::istream& operator>>( std::istream& input, Round& round );
}