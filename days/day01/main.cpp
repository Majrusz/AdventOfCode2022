#include "day01.h"

int main() {
    using namespace day01;

    const Elves& elves{ util::read< Elf >( "days/day01/main.txt", &day01::deserialize ) };

    std::cout << "Task 1 output is: " << elves.getMaxCalories() << std::endl;
    std::cout << "Task 2 output is: " << elves.getMaxCalories( 3 ) << std::endl;

    return 0;
}