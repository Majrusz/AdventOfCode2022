#include <functional>
#include <numeric>
#include <regex>

#include "day07.h"

std::vector< day07::Command > day07::read( std::string_view filename ) {
    std::ifstream stream = util::getFile( filename );
    std::vector< Command > commands;
    std::string line;
    while( std::getline( stream, line ) ) {
        if( line[ 0 ] == '$' ) {
            commands.emplace_back( Command{ line.substr( 2 ), {} } );
        } else {
            commands.back().output.push_back( line );
        }
    }

    return commands;
}

day07::Filesystem day07::Commands::toFilesystem() const {
    static const std::regex DIR_PATTERN{ R"(dir (.*))" }, FILE_PATTERN{ R"(([0-9]+) (.*))" }, CD_PATTERN{ R"(cd (.*))" };
    std::shared_ptr< Directory > root = std::make_shared< Directory >();
    std::shared_ptr< Directory > current = root;
    for( const Command& command : this->commands ) {
        if( command.input == "ls" ) {
            for( const std::string& line : command.output ) {
                std::smatch match;
                if( std::regex_match( line, match, DIR_PATTERN ) ) {
                    current->files.emplace( match[ 1 ], std::make_shared< Directory >( current ) );
                } else if( std::regex_match( line, match, FILE_PATTERN ) ) {
                    current->files.emplace( match[ 2 ], std::make_shared< File >( std::stoul( match[ 1 ] ) ) );
                }
            }
        } else if( command.input.substr( 0, 2 ) == "cd" ) {
            std::smatch match;
            if( std::regex_match( command.input, match, CD_PATTERN ) ) {
                if( match[ 1 ] == "/" ) {
                    current = root;
                } else if( match[ 1 ] == ".." ) {
                    current = current->parent.lock();
                } else {
                    current = std::dynamic_pointer_cast< Directory >( current->files[ match[ 1 ] ] );
                }
            }
        }
    }

    return Filesystem{ root };
}

size_t day07::File::getSize() const {
    return this->size;
}

size_t day07::Directory::getSize() const {
    return std::accumulate( std::begin( this->files ), std::end( this->files ), 0, []( size_t sum, const auto& file ) {
        return sum + file.second->getSize();
    } );
}

std::vector< std::shared_ptr< day07::Directory > > day07::Filesystem::findAllDirectories() const {
    std::vector< std::shared_ptr< Directory > > directories;
    std::function< void( const std::shared_ptr< Directory >& ) > addAllSubdirectories = [ &directories, &addAllSubdirectories ]( const std::shared_ptr< Directory >& directory ) {
        directories.push_back( directory );

        for( const auto& [ name, file ] : directory->files ) {
            if( std::shared_ptr< Directory > subdirectory = std::dynamic_pointer_cast< Directory >( file ) ) {
                addAllSubdirectories( subdirectory );
            }
        }
    };
    addAllSubdirectories( this->root );

    return directories;
}

size_t day07::Filesystem::sumDirectoriesSmallerThan( size_t size ) const {
    auto predicate = [ &size ]( const std::shared_ptr< Directory >& directory ) {
        return directory->getSize() > size;
    };
    std::vector< std::shared_ptr< Directory > > directories = this->findAllDirectories();
    directories.erase( std::remove_if( std::begin( directories ), std::end( directories ), predicate ), std::end( directories ) );

    return std::accumulate( std::begin( directories ), std::end( directories ), 0, []( size_t sum, const auto& directory ) {
        return sum + directory->getSize();
    } );
}

std::shared_ptr< day07::Directory > day07::Filesystem::findDirectoryToRemove( size_t minUnusedSize ) const {
    std::vector< std::shared_ptr< Directory > > directories = this->findAllDirectories();
    std::sort( std::begin( directories ), std::end( directories ), []( const auto& lhs, const auto& rhs ) {
        return lhs->getSize() < rhs->getSize();
    } );

    size_t requiredSpaceToRemove = minUnusedSize + this->root->getSize() - 70'000'000;
    return *std::find_if( std::begin( directories ), std::end( directories ), [ &requiredSpaceToRemove ]( const std::shared_ptr< Directory >& directory ) {
        return directory->getSize() >= requiredSpaceToRemove;
    } );
}
