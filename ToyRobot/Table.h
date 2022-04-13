#pragma once
#include <utility>

constexpr int xBound = 4;
constexpr int yBound = 4;

class Table {
private:
	std::pair<int, int> coordinates { xBound, yBound };

public:
	inline std::pair<int, int>& getCoordinates() { return coordinates; }

};
