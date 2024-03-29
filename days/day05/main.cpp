#include "day05.h"

int main() {
    using namespace day05;

    const auto& [ container1, container2 ] = read( "days/day05/main.txt" );
    const Structure& structure{ container1, container2 };

    std::cout << "Task 1 output is: " << structure.determineTopCrates( &Structure::applyOperations ) << std::endl;
    std::cout << "Task 2 output is: " << structure.determineTopCrates( &Structure::applyOperations2 ) << std::endl;

    return 0;
}