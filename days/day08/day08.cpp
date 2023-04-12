#include <algorithm>
#include <functional>

#include "day08.h"

size_t day08::Forest::countVisibleTrees() const {
    std::unique_ptr< bool[] > visibility{ new bool[ this->getSizeSquared() ] };
    std::fill_n( visibility.get(), this->getSizeSquared(), false );
    auto markVisibleTrees = [ &visibility, this ]( std::function< util::Vec2< size_t >( size_t ) > supplier ) {
        uint8_t height;
        for( size_t n = 0; n < this->getSizeSquared(); ++n ) {
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
    // left to right
    markVisibleTrees( [ this ]( size_t n ) {
        return util::Vec2< size_t >{ n % this->size, n / this->size };
    } );
    // top to bottom
    markVisibleTrees( [ this ]( size_t n ) {
        return util::Vec2< size_t >{ n / this->size, n % this->size };
    } );
    // right to left
    markVisibleTrees( [ this ]( size_t n ) {
        return util::Vec2< size_t >{ this->size - 1 - n % this->size, n / this->size };
    } );
    // bottom to top
    markVisibleTrees( [ this ]( size_t n ) {
        return util::Vec2< size_t >{ n / this->size, this->size - 1 - n % this->size };
    } );

    return std::count( visibility.get(), visibility.get() + this->getSizeSquared(), true );
}

size_t day08::Forest::determineScenicScore() const {
    std::unique_ptr< size_t[] > scores{ new size_t[ this->getSizeSquared() ] };
    for( size_t n = 0; n < this->getSizeSquared(); ++n ) {
        util::Vec2< size_t > position{ n % this->size, n / this->size };
        uint8_t height = this->getTreeHeight( position );

        size_t left = 0, right = 0, top = 0, bottom = 0;
        {
            size_t x = n % this->size;
            while( x > 0 ) {
                --x;
                ++left;
                if( this->getTreeHeight( { x, position.y } ) >= height ) {
                    break;
                }
            }
        }
        {
            size_t x = n % this->size;
            while( x < this->size - 1 ) {
                ++x;
                ++right;
                if( this->getTreeHeight( { x, position.y } ) >= height ) {
                    break;
                }
            }
        }
        {
            size_t y = n / this->size;
            while( y > 0 ) {
                --y;
                ++top;
                if( this->getTreeHeight( { position.x, y } ) >= height ) {
                    break;
                }
            }
        }
        {
            size_t y = n / this->size;
            while( y < this->size - 1 ) {
                ++y;
                ++bottom;
                if( this->getTreeHeight( { position.x, y } ) >= height ) {
                    break;
                }
            }
        }
        scores.get()[ n ] = left * right * top * bottom;
    }

    return *std::max_element( scores.get(), scores.get() + this->getSizeSquared() );
}

uint8_t day08::Forest::getTreeHeight( util::Vec2< size_t > position ) const {
    return this->heights.get()[ this->toIndex( position ) ];
}

size_t day08::Forest::toIndex( util::Vec2< size_t > position ) const {
    return position.x + position.y * this->size;
}

size_t day08::Forest::getSizeSquared() const {
    return this->size * this->size;
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
