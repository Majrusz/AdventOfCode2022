#include "day01.h"

int main() {
	using namespace day01;

	const Elves& elves = util::read< Elf >( "days/day01/main.txt" );

	std::cout << "Task 1 output is: " << getMaxCalories( elves ) << std::endl;
	std::cout << "Task 2 output is: " << getMaxCalories( elves, 3 ) << std::endl;
	
	return 0;
}