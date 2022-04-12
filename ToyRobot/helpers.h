#pragma once
#include <iostream>
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
	std::smatch sm;
	std::regex_match( _str, sm, std::regex( "(\\d+),(\\d+),(\\w+)" ) );
	int p1 = std::stoi( sm[1].str() );
	int p2 = std::stoi( sm[2].str() );
	std::string p3 = sm[3];

	return std::make_tuple( p1, p2, p3 );
}
