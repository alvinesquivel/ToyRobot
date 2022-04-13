#pragma once
#include <unordered_map>

class Directions {
private:
	std::unordered_map<std::string, std::string> turnRightDirs{ 
		{"NORTH", "EAST"}, {"EAST", "SOUTH"}, {"SOUTH", "WEST"}, {"WEST", "NORTH"} };

	std::unordered_map<std::string, std::string> turnLeftDirs{ {"NORTH", "WEST"}, {"WEST", "SOUTH"},
			{"SOUTH", "EAST"}, {"EAST", "NORTH"} };


public:
	std::string facingDirection;


public:

	bool isValidDirection( std::string& _direction ) {
		if( turnRightDirs.count( _direction ) == 0 )
			return false;
		return true;
	}

	void turnRight()
	{
		this->facingDirection = turnRightDirs[this->facingDirection];
	}
	
	void turnLeft()
	{
		this->facingDirection = turnLeftDirs[this->facingDirection];
	}
};