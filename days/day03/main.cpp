#include "day03.h"

int main() {
	using namespace day03;

	const Rucksacks& rucksacks = util::read< Rucksack >( "days/day03/main.txt", &Rucksack::deserialize );

	std::cout << "Task 1 output is: " << rucksacks.calculatePriority() << std::endl;

	return 0;
}