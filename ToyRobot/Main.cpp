#include "CommandHandler.h"


int main()
{
	CommandHandler cmdHandler;
	Robot robot;
	std::string comm;

	while( std::getline( std::cin, comm ) )
	{
		if( comm == "" )
		{
			std::cout << "Command cannot be empty.\n";
			continue;
		}
		
		cmdHandler.command( robot, comm );
		
		if( comm == "REPORT" )
			break;
	}

	system( "pause" );
	return 0;
}