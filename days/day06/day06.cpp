#include <unordered_map>

#include "day06.h"

size_t day06::Signal::findMarkerIdx() const {
	size_t idx = 0;
	std::unordered_map< char, size_t > counters;
	while( idx < this->input.size() ) {
		char next = this->input[ idx ];
		counters[ next ] = 1 + ( counters.contains( next ) ? counters[ next ] : 0 );
		if( idx >= 3 ) {
			if( counters.size() == 4 ) {
				return idx + 1;
			}

			char old = this->input[ idx - 3 ];
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
