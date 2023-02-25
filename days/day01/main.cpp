#include "day01.h"

int main() {
	using namespace day01;

	std::vector< Elf > elves = util::read< Elf >( "days/day01/main.txt" );

	std::cout << "Task 1 output is: " << getMaxCalories( elves ) << std::endl;
	
	return 0;
}