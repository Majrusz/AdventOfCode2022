#include "day02.h"

int main() {
	using namespace day02;

	const Rounds& rounds = util::read< Round >( "days/day02/main.txt" );

	std::cout << "Task 1 output is: " << rounds.calculatePoints() << std::endl;
	
	return 0;
}