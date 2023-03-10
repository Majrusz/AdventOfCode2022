#include "file_loader.h"

std::ifstream util::getFile( std::string_view filename ) {
	using namespace std::literals;

	return std::ifstream{ "../../"s + filename.data() }; // to go outside build directory
}

std::string util::read( std::string_view filename ) {
	std::ifstream stream = util::getFile( filename );
	std::string output, line;
	std::getline( stream, output );
	while( std::getline( stream, line ) ) {
		output += '\n' + line;
	}

	return output;
}
