#pragma once
class Table
{
private:
	int max_X = 4;
	int max_Y = 4;


public:

	inline unsigned int get_X() { return max_X; }
	inline unsigned int get_Y() { return max_Y; }
};

