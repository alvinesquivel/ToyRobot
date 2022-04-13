#pragma once
#include <utility>
#include <string>

// Receiver
class Robot {
private:

	std::pair<int, int> position;
	std::string facingDirection;
	bool placed = false;


public:
	void place( int _X, int _Y, std::string _Face );
	void move();
	void right();
	void left();

	inline std::pair<int, int>& getPosition() { return position; }
	inline std::string& getFacingDirection() { return facingDirection; }
	inline bool isPlaced() { return placed; }
};
