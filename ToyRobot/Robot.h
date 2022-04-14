#pragma once
#include <utility>
#include <string>
#include "Direction.h"


// Receiver
class Robot {
private:

	std::pair<int, int> position;
	int facingDirection;
	bool placed = false;


public:
	void place( int _X, int _Y, std::string _FacingDirection );
	void rotate( std::string _toWhat );
	void move();

	inline std::pair<int, int>& getPosition() { return position; }
	inline int& getFacingDirection() { return facingDirection; }
	inline bool isPlaced() { return placed; }
};
