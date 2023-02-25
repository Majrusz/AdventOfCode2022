#include <iostream>
#include <string_view>
#include <vector>

namespace util {
	template< typename Type >
	std::vector< Type > read( std::string_view filename ) {
		using namespace std::literals;

		std::ifstream stream{ "../../"s + filename.data() }; // to go outside build directory
		std::vector< Type > objects{};

		while( stream && !stream.eof() ) {
			Type object{};
			stream >> object;

			objects.push_back( object );
		}

		return objects;
	}
}