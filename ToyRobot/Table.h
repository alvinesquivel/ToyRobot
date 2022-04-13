#pragma once
#include <utility>

constexpr int xBound = 4;
constexpr int yBound = 4;

class Table {
private:
	std::pair<int, int> coordinates { xBound, yBound };

public:

	bool isValidPosition( int& _X, int& _Y )
	{
		if( _X < 0 || _X > coordinates.first || _Y < 0 || _Y > coordinates.second )
			return false;

		return true;
	}

	bool isValidPosition( std::pair<int, int> robotPos )
	{
		if( robotPos.first <= 0 || robotPos.first >= coordinates.first
			|| robotPos.second <= 0 || robotPos.second >= coordinates.second )
			return false;

		return true;
	}

	inline std::pair<int, int>& getCoordinates() { return coordinates; }
};



