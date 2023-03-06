#include "day04.h"

int main() {
	using namespace day04;

	const Pairs& pairs{ util::read< Pair >( "days/day04/main.txt", &day04::deserialize ) };

	std::cout << "Task 1 output is: " << pairs.countInsideRanges() << std::endl;
	std::cout << "Task 2 output is: " << pairs.countOverlapRanges() << std::endl;

	return 0;
}