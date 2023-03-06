#include "day02.h"

int main() {
	using namespace day02;

	{
		const Rounds& rounds{ util::read< Round >( "days/day02/main.txt", &day02::deserialize ) };

		std::cout << "Task 1 output is: " << rounds.calculatePoints() << std::endl;
	}
	{
		const Rounds& rounds{ util::read< Round >( "days/day02/main.txt", &day02::deserialize2 ) };

		std::cout << "Task 2 output is: " << rounds.calculatePoints() << std::endl;
	}
	
	return 0;
}