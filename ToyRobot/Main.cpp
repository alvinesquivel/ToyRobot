#include "CommandHandler.h"


int main()
{
	CommandHandler cmd;
	Robot rob;
	std::string comm;

	while( std::getline( std::cin, comm ) )
	{
		if( comm == "" )
		{
			std::cout << "Command cannot be empty.\n";
			continue;
		}
		
		cmd.command( rob, comm );
		
		if( comm == "REPORT" )
			break;
	}

	system( "pause" );
	return 0;
}