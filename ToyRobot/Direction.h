#pragma once
#include <string>
#include <list>

enum directions { NORTH, EAST, SOUTH, WEST };

class Direction {
public:
	
	std::list <std::string> knownDirections{ "NORTH", "EAST", "SOUTH", "WEST" };

};