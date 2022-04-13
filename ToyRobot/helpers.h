#pragma once
#include <string>
#include <regex>
#include <unordered_map>
#include <utility>
#include <tuple>




// Functions
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
