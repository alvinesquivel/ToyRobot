#pragma once
#include <string>
#include <regex>
#include <unordered_map>
#include <utility>
#include <tuple>




// Misc Functions
std::string toUpperCase( std::string& _str )
{
	for( int i = 0; i < strlen( _str.c_str() ); i++ )
	{
		_str[i] = (char)towupper( _str[i] );
	}

	return _str;
}

std::string clean( std::string& _str )
{
	_str.erase( std::remove( _str.begin(), _str.end(), ' ' ), _str.end() );
	return _str;
}

std::tuple<int, int, std::string> finalizePlaceArgs( std::string& _str )
{
	std::smatch matches;
	std::regex_match( _str, matches, std::regex( ".*(\\d+),(\\d+),(\\w+)" ) );
	int p1 = std::stoi( matches[1].str() );
	int p2 = std::stoi( matches[2].str() );
	std::string p3 = matches[3];

	return std::make_tuple( p1, p2, p3 );
}

bool isValidPosition( Table _table, int& _X, int& _Y )
{
	if( _X < 0 || _X > _table.getCoordinates().first || _Y < 0 || _Y > _table.getCoordinates().second )
		return false;

	return true;
}

bool isValidMove( Table _table, Robot* _robot )
{
	if( _robot->getFacingDirection() == "EAST" )
	{
		if( _robot->getPosition().first + 1 > _table.getCoordinates().first )
			return false;
	}
	else if( _robot->getFacingDirection() == "WEST" )
	{
		if( _robot->getPosition().first - 1 < 0 )
			return false;
	}
	else if( _robot->getFacingDirection() == "NORTH" )
	{
		if( _robot->getPosition().second + 1 > _table.getCoordinates().second )
			return false;
	}
	else if( _robot->getFacingDirection() == "SOUTH" )
	{
		if( _robot->getPosition().second - 1 < 0 )
			return false;
	}
	else
		return true;
}
