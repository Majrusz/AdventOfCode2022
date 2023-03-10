#include <unordered_map>

#include "day06.h"

size_t day06::Signal::findMarkerIdx( size_t uniqueCharacters ) const {
	size_t idx = 0;
	std::unordered_map< char, size_t > counters;
	while( idx < this->input.size() ) {
		char next = this->input[ idx ];
		counters[ next ] = 1 + ( counters.contains( next ) ? counters[ next ] : 0 );
		if( idx >= uniqueCharacters - 1 ) {
			if( counters.size() == uniqueCharacters ) {
				return idx + 1;
			}

			char old = this->input[ idx - uniqueCharacters + 1 ];
			if( counters[ old ] == 1 ) {
				counters.erase( old );
			} else {
				counters[ old ] -= 1;
			}
		}
		++idx;
	}

	return std::numeric_limits< size_t >::max();
}
