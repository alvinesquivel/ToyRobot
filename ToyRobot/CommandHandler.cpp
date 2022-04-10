#include "CommandHandler.h"


std::vector<std::string> CommandHandler::split( std::string& _input, const std::string& _delim )
{
    using std::string;
    using std::vector;

    string::size_type start = _input.find_first_not_of( _delim ), end = 0;

    vector<string> out;
    while( start != _input.npos )
    {
        end = _input.find_first_of( _delim, start );
        if( end == _input.npos )
        {
            out.push_back( _input.substr( start ) );
            break;
        }
        else
        {
            out.push_back( _input.substr( start, end - start ) );
        }
        start = _input.find_first_not_of( _delim, end );
    }
    return out;
}

bool CommandHandler::command( Robot& r, std::string& _inst )
{
    std::istringstream iss( _inst );
    std::vector<std::string> inst_vec{ std::istream_iterator<std::string>{iss},
        std::istream_iterator<std::string>{} };

    if( validCommands.count( inst_vec[0] ) > 0 )
    {
        if( inst_vec[0] == "PLACE" )
        {
            if( inst_vec.size() < 2 )
            {
                std::cout << "No valid arguments for PLACE command\n";
                std::cout << "Syntax: PLACE X,Y,F. Ex: PLACE 2,3,EAST\n";
                return false;
            }
            else
            {
                int p_arg1 = std::stoi( split( inst_vec[1], "," )[0] );
                int p_arg2 = std::stoi( split( inst_vec[1], "," )[1] );
                std::string p_arg3 = split( inst_vec[1], "," )[2];
                r.place( p_arg1, p_arg2, p_arg3 );
                
                return true;
            }
        }
        else if( inst_vec[0] == "MOVE" )
            r.move();
        
        else if( inst_vec[0] == "RIGHT" || inst_vec[0] == "LEFT" )
            r.rotate( inst_vec[0] );

        else if( inst_vec[0] == "REPORT" )
            r.report();

        return true;
    }
    else
        return false;
}