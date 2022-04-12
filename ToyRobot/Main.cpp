#pragma once
#include "Concrete.h"
#include "Invoker.h"
#include "helpers.h"



int main()
{
	Invoker* invoker = new Invoker;
	Robot* robot = new Robot;

	std::string input;
	std::smatch matches;

	std::unordered_map<std::string, Command*> cmdMap;
	cmdMap.emplace( std::make_pair( std::string( "MOVE" ), new Move( robot ) ) );
	cmdMap.emplace( std::make_pair( std::string( "RIGHT" ), new Right( robot ) ) );
	cmdMap.emplace( std::make_pair( std::string( "LEFT" ), new Left( robot ) ) );
	cmdMap.emplace( std::make_pair( std::string( "REPORT" ), new Report( robot ) ) );

	
	while( std::getline( std::cin, input ) )
	{
		if( input == "" )
		{
			std::cout << "INPUT MUST NOT BE EMPTY\n";
			continue;
		}


		if( std::regex_match( input, matches, std::regex( "(PLACE)\\s+(\\d+,\\s*\\d+,\\s*\\w+).*" ) ) )
		{
			// placeArgs_tmp holds the arguments for PLACE command
			std::string placeArgsTmp = std::move( matches[2].str() );	
			// remove whitespace, if there is any
			clean( placeArgsTmp );
			
			auto placeArgs = finalizePlaceArgs( placeArgsTmp );
			auto pArg0 = std::get<0>( placeArgs );
			auto pArg1 = std::get<1>( placeArgs );
			auto pArg2 = std::get<2>( placeArgs );

			invoker->setCommand( new Place( robot, pArg0, pArg1, pArg2 ) );
			invoker->executeCommand();
			
			continue;
		}

		clean( input );
		auto search = cmdMap.find( input );
		
		if( search != cmdMap.end() )
		{
			invoker->setCommand( search->second );
			invoker->executeCommand();
		}

		if( input == "REPORT" )
			break;

	} // end while

	delete invoker;
	delete robot;

	
	system( "pause" );
	return 0;

}
