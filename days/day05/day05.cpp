#include <regex>

#include "day05.h"

bool day05::Operation::operator==( const Operation& operation ) const {
    return this->count == operation.count
        && this->from == operation.from
        && this->to == operation.to;
}

std::vector< day05::Crates > day05::deserializeStacks( std::istream& input ) {
    static const std::regex PATTERN{ R"([\s]{3,4}|([A-Z]))" };
    static const std::sregex_token_iterator END;

    std::vector< Crates > stacks;
    std::string line;
    std::smatch match;
    while( std::getline( input, line ) ) {
        if( line.substr( 0, 2 ) == " 1" ) {
            std::getline( input, line );
            break;
        }

        size_t idx = 0;
        for( std::sregex_token_iterator it( std::begin( line ), std::end( line ), PATTERN ); it != END; ++it, ++idx ) {
            if( const std::string& value = it->str(); value != "   " && value != "    " ) {
                while( stacks.size() <= idx ) {
                    stacks.push_back( Crates{} );
                }
                stacks[ idx ].push_front( value[ 0 ] );
            }
        }
    }

    return stacks;
}

std::vector< day05::Operation > day05::deserializeOperations( std::istream& input ) {
    static const std::regex PATTERN{ R"(move ([0-9]+) from ([0-9]+) to ([0-9]+))" };

    std::string line;
    std::smatch match;
    std::vector< Operation > operations;
    while( input && input.peek() != EOF ) {
        if( std::getline( input, line ) && std::regex_match( line, match, PATTERN ) ) {
            operations.emplace_back( Operation{ std::stoul( match[ 1 ] ), std::stoul( match[ 2 ] ), std::stoul( match[ 3 ] ) } );
        }
    }

    return operations;
}

std::pair< std::vector< day05::Crates >, std::vector< day05::Operation > > day05::read( std::string_view filename ) {
    std::ifstream stream = util::getFile( filename );

    return std::pair{ deserializeStacks( stream ), deserializeOperations( stream ) };
}

std::vector< day05::Crates > day05::Structure::applyOperations() const {
    std::vector< Crates > output = this->stacks;
    for( const Operation& operation : this->operations ) {
        for( int i = 0; i < operation.count; ++i ) {
            char c = output[ operation.from - 1 ].back();
            output[ operation.from - 1 ].pop_back();
            output[ operation.to - 1 ].push_back( c );
        }
    }

    return output;
}

std::vector< day05::Crates > day05::Structure::applyOperations2() const {
    std::vector< Crates > output = this->stacks;
    for( const Operation& operation : this->operations ) {
        for( int i = 0; i < operation.count; ++i ) {
            char c = *( output[ operation.from - 1 ].rbegin() + ( operation.count - i - 1 ) );
            output[ operation.to - 1 ].push_back( c );
        }

        for( int i = 0; i < operation.count; ++i ) {
            output[ operation.from - 1 ].pop_back();
        }
    }

    return output;
}

std::string day05::Structure::determineTopCrates( std::vector< Crates > ( Structure::*method )() const ) const {
    std::string output;
    for( const Crates& crates : ( *this.*method )() ) {
        output += crates.back();
    }

    return output;
}
