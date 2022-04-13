#pragma once
#include <iostream>
#include "Concrete.h"
#include "Invoker.h"
#include "Robot.h"
#include "Table.h"
#include "Direction.h"
#include "helpers.h"


int main()
{
	Invoker* invoker = new Invoker;
	Robot* robot = new Robot;
	Table table;
	Direction direction;
	

	std::string input;
	std::smatch matches;

	std::unordered_map<std::string, Command*> cmdMap;
	cmdMap.emplace( std::make_pair( std::string( "MOVE" ), new Move( robot ) ) );
	cmdMap.emplace( std::make_pair( std::string( "RIGHT" ), new Right( robot ) ) );
	cmdMap.emplace( std::make_pair( std::string( "LEFT" ), new Left( robot ) ) );

	std::regex placeRgx( "(PLACE)\\s+(.*\\d+,\\s*\\d+,\\s*\\w+).*" );

	while( std::getline( std::cin, input ) )
	{
		// Input is empty. Prompt user if needed.
		if( input == "" )
			continue;


		if( std::regex_match( input, matches, placeRgx ) )
		{
			// placeArgs_tmp holds the arguments for PLACE command
			std::string placeArgsTmp = std::move( matches[2].str() );	
			// remove whitespace, if there is any
			clean( placeArgsTmp );
			
			auto placeArgs = finalizePlaceArgs( placeArgsTmp );
			auto pArg0 = std::get<0>( placeArgs );
			auto pArg1 = std::get<1>( placeArgs );
			auto pArg2 = std::get<2>( placeArgs );

			// Invalid placement position. Prompt user if needed.
			if( !table.isValidPosition( pArg0, pArg1 ) )
				continue;

			// Invalid placement facing direction. Promp user if needed.
			if( direction.knownDirections.find( pArg2 ) == direction.knownDirections.end() )
				continue;

			invoker->setCommand( new Place( robot, pArg0, pArg1, pArg2 ) );
			invoker->executeCommand();
			
			continue;
		}
		
		clean( input );

		if( input == "MOVE" )
		{
			if( !table.isValidPosition( robot->getPosition() ) )
				continue;
		}

		auto search = cmdMap.find( input );
		
		if( search != cmdMap.end() )
		{
			invoker->setCommand( search->second );
			invoker->executeCommand();
		}

		if( input == "REPORT" )
			
			// Ignore if robot is not placed. Promp user if needed.
			if( !robot->isPlaced() )
				break;
			else
			{
				std::cout << "Output: " << robot->getPosition().first << "," << robot->getPosition().second
					<< "," << robot->getFacingDirection() << std::endl;
				break;
			}
			
	
	} // end while


	delete invoker;
	delete robot;

	
	system( "pause" );
	return 0;
}
