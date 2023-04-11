#include "day07.h"

int main() {
	using namespace day07;

	const auto& filesystem = Commands{ read( "days/day07/main.txt" ) }.toFilesystem();

	std::cout << "Task 1 output is: " << filesystem.sumDirectoriesSmallerThan( 100'000 ) << std::endl;

	return 0;
}