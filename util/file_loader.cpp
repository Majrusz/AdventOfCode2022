#include "file_loader.h"

std::ifstream util::getFile( std::string_view filename ) {
	using namespace std::literals;

	return std::ifstream{ "../../"s + filename.data() }; // to go outside build directory
}