#include <algorithm>
#include <fstream>
#include <numeric>
#include <string_view>
#include <vector>

#include "file_loader.h"

namespace day02 {
	enum class Shape : uint8_t {
		ROCK = 1, PAPER = 2, SCISSORS = 3
	};

	enum class Result : uint8_t {
		WIN = 6, DRAW = 3, LOSE = 0
	};
	
	struct Round {
		static Round deserialize( std::istream& input );

		static Round deserialize2( std::istream& input );

		size_t calculatePoints() const;
		
		Shape opponent;
		Shape player;
	};

	class Rounds {
	public:
		Rounds( const std::vector< Round >& rounds ) : rounds{ rounds } {}
	
		size_t calculatePoints() const;

	private:
		std::vector< Round > rounds;
	};

	Result determineResult( Shape player, Shape opponent );

	Shape determinePlayer( Shape opponent, Result result );
}