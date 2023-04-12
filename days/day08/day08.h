#include <fstream>
#include <memory>

#include "file_loader.h"
#include "vector2d.h"

namespace day08 {
    class Forest {
    public:
        Forest( std::unique_ptr< uint8_t[] > heights, size_t size )
            : heights{ std::move( heights ) }
            , size{ size } {}

        size_t countVisibleTrees() const;

        size_t determineScenicScore() const;

        uint8_t getTreeHeight( util::Vec2< size_t > position ) const;

    private:
        size_t toIndex( util::Vec2< size_t > position ) const;

        size_t getSizeSquared() const;

        const std::unique_ptr< uint8_t[] > heights;
        const size_t size;
    };

    Forest read( std::string_view filename );
}