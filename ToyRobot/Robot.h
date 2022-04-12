#pragma once
#include <iostream>
#include <string>
#include "Table.h"
#include "Directions.h"

// Receiver
class Robot {
private:

	std::pair<int, int> position;
	bool placed = false;
	Directions direction;
	Table table;

public:
	bool place( int _X, int _Y, std::string _Face );
	bool move();
	bool right();
	bool left();
	void report();
};
