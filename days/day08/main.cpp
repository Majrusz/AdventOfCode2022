#include "day08.h"

int main() {
	using namespace day08;

	const Forest& forest = read( "days/day08/main.txt" );

    std::cout << "Task 1 output is: " << forest.countVisibleTrees() << std::endl;
    std::cout << "Task 2 output is: " << forest.determineScenicScore() << std::endl;

	return 0;
}