#include <fstream>
#include <memory>
#include <string>
#include <unordered_map>

#include "file_loader.h"

namespace day07 {
    struct Command {
        std::string input;
        std::vector< std::string > output;
    };

    struct FileBase {
        virtual size_t getSize() const = 0;
    };

    struct File : FileBase {
        explicit File( size_t size )
            : size{ size } {}

        virtual size_t getSize() const override;

        size_t size = 0;
    };

    struct Directory : FileBase {
        explicit Directory( std::shared_ptr< Directory > parent )
            : parent{ parent } {}

        Directory() = default;

        virtual size_t getSize() const override;

        std::unordered_map< std::string, std::shared_ptr< FileBase > > files;
        std::weak_ptr< Directory > parent;
    };

    class Filesystem {
    public:
        explicit Filesystem( std::shared_ptr< Directory > root )
            : root{ root } {};

        std::vector< std::shared_ptr< Directory > > findAllDirectories() const;

        size_t sumDirectoriesSmallerThan( size_t size ) const;

        std::shared_ptr< Directory > findDirectoryToRemove( size_t minUnusedSize ) const;

    private:
        std::shared_ptr< Directory > root;
    };

    class Commands {
    public:
        explicit Commands( const std::vector< Command >& commands )
            : commands{ commands } {};

        Filesystem toFilesystem() const;

    private:
        std::vector< Command > commands;
    };

    std::vector< Command > read( std::string_view filename );
}