#include <fstream>
#include <string>

#include "file_loader.h"

namespace day06 {
	class Signal {
	public:
		Signal( const std::string& input ) : input{ input } {}

		size_t findMarkerIdx() const;

	private:
		std::string input;
	};
}