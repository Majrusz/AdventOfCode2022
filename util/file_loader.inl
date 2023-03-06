template< typename Type >
std::vector< Type > util::read( std::string_view filename, Type( *deserializer )( std::istream& ) ) {
	std::ifstream stream = getFile( filename );
	std::vector< Type > objects{};

	while( stream && stream.peek() != EOF ) {
		objects.push_back( deserializer( stream ) );
	}

	return objects;
}