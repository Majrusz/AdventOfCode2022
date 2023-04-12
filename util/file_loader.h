#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

namespace util {
    std::ifstream getFile( std::string_view filename );

    template< typename Type >
    std::vector< Type > read( std::string_view filename, Type ( *deserializer )( std::istream& ) );

    std::string read( std::string_view filename );

    size_t countLines( std::istream& stream );
}

#include "file_loader.inl"