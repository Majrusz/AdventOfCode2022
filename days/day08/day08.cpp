#include <functional>

#include "day08.h"

size_t day08::Forest::countVisibleTrees() const {
	std::unique_ptr< bool[] > visibility{ new bool[ this->size * this->size ] };
	std::fill_n( visibility.get(), this->size * this->size, false );
	auto markVisibleTrees = [ &visibility, this ]( std::function< util::Vec2< size_t >( size_t ) > supplier ) {
		uint8_t height;
		for( size_t n = 0; n < this->size * this->size; ++n ) {
			if( n % this->size == 0 ) {
				height = 0;
			}

			util::Vec2< size_t > position = supplier( n );
			uint8_t newHeight = this->getTreeHeight( position );
			if( newHeight > height || n % this->size == 0 ) {
				height = newHeight;
				visibility.get()[ this->toIndex( position ) ] = true;
			}
		}
	};
	markVisibleTrees( [ this ]( size_t n ) { return util::Vec2< size_t >{ n % this->size, n / this->size }; } ); // left to right
	markVisibleTrees( [ this ]( size_t n ) { return util::Vec2< size_t >{ n / this->size, n % this->size }; } ); // top to bottom
	markVisibleTrees( [ this ]( size_t n ) { return util::Vec2< size_t >{ this->size - 1 - n % this->size, n / this->size }; } ); // right to left
	markVisibleTrees( [ this ]( size_t n ) { return util::Vec2< size_t >{ n / this->size, this->size - 1 - n % this->size }; } ); // bottom to top

	return std::count( visibility.get(), visibility.get() + this->size * this->size, true );
}

uint8_t day08::Forest::getTreeHeight( util::Vec2< size_t > position ) const {
	return this->heights.get()[ this->toIndex( position ) ];
}

size_t day08::Forest::toIndex( util::Vec2< size_t > position ) const {
    return position.x + position.y * this->size;
}

day08::Forest day08::read( std::string_view filename ) {
	std::ifstream stream = util::getFile( filename );
	size_t linesCount = util::countLines( stream );
	std::unique_ptr< uint8_t[] > heights{ new uint8_t[ linesCount * linesCount ] };
	size_t idx = 0;
	for( std::istreambuf_iterator< char > it{ stream }, end; it != end; ++it ) {
		if( *it == '\n' ) {
			continue;
		}

		heights.get()[ idx++ ] = static_cast< uint8_t >( *it );
	}

	return Forest{ std::move( heights ), linesCount };
}
