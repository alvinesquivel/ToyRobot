#pragma once
#include "Table.h"
#include <unordered_set>
#include <string>
#include <iostream>


class Robot
{

private:
	int x;
	int y;

	Table table;
	std::string face;
	bool placed = false;
	std::unordered_set<std::string> validFaceDir = { "NORTH","EAST","SOUTH","WEST" };

public:

	bool is_valid_position( int& _pos_x, int& _pos_y );
	bool is_valid_position( int& _pos_x, int& _pos_y, std::string _face );
	bool place( int& _x, int& _y, std::string& _face );
	bool rotate( std::string& _direction );
	bool move();

	void report();
};