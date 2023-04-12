#include "day06.h"

int main() {
    using namespace day06;

    const std::string& input = util::read( "days/day06/main.txt" );
    Signal signal{ input };

    std::cout << "Task 1 output is: " << signal.findMarkerIdx() << std::endl;
    std::cout << "Task 2 output is: " << signal.findMarkerIdx( 14 ) << std::endl;

    return 0;
}