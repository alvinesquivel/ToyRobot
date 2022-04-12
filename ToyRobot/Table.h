#pragma once
#include <utility>


class Table
{
private:
	std::pair<int, int> coordinates{ 4, 4 };


public:

	bool isValidPosition( int _X, int _Y )
	{
		if( _X < 0 || _X > this->coordinates.first || _Y < 0 || _Y > this->coordinates.second )
			return false;

		return true;
	}
};
