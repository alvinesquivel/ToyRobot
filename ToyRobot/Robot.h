#pragma once
#include <iostream>
#include <string>
#include <unordered_set>
#include "Table.h"


class Robot
{

private:
	int x;
	int y;

	Table table;
	std::string face;
	bool placed = false;

public:

	bool is_valid_position( int& _pos_x, int& _pos_y );
	bool place( int& _x, int& _y, std::string& _face );
	bool rotate( std::string direction );
	bool move();

	void report();
};