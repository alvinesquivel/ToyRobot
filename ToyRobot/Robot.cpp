#include "Robot.h"
#include <map>

bool Robot::is_valid_position( int& _pos_x, int& _pos_y )
{
	int x_maxBoundary = table.get_X();
	int y_maxBoundary = table.get_Y();
	
	if( _pos_x < 0 || _pos_x > x_maxBoundary || _pos_y < 0 || _pos_y > y_maxBoundary )
		return false;
	else
		return true;
}

bool Robot::place( int& _x, int& _y, std::string& _face )
{
	if( !is_valid_position( _x, _y ) ) // ignore
		return false;
	
	std::unordered_set<std::string> validFaceDir = { "NORTH","EAST","SOUTH","WEST" };
	if( validFaceDir.count( _face ) == 0 )
		return false;

	if( !placed )
		placed = true;
	
	x = _x;
	y = _y;
	face = _face;
	
	return true;
}

bool Robot::rotate( std::string direction  )
{	
	if( !placed ) // robot not placed.
		return false;

	std::string curr_face = face;

	std::map<std::string, std::string> turn_right{ {"NORTH", "EAST"}, {"EAST", "SOUTH"},
			{"SOUTH", "WEST"}, {"WEST", "NORTH"} };

	std::map<std::string, std::string> turn_left{ {"NORTH", "WEST"}, {"WEST", "SOUTH"},
			{"SOUTH", "EAST"}, {"EAST", "NORTH"} };

	if( direction == "RIGHT" )
		curr_face = turn_right[curr_face];
	else if( direction == "LEFT" )
		curr_face = turn_left[curr_face];
	else
		return false; // invalid direction

	face = curr_face;
	return true;
}

bool Robot::move()
{
	if( !placed ) // robot not placed.
		return false;

	int tmp_x = x;
	int tmp_y = y;

	if( face == "NORTH" )
		tmp_y += 1;
	else if( face == "SOUTH" )
		tmp_y -= 1;
	else if( face == "EAST" )
		tmp_x += 1;
	else if( face == "WEST" )
		tmp_x -= 1;
	
	if( is_valid_position( tmp_x, tmp_y ) )
	{
		x = tmp_x;
		y = tmp_y;
		return true;
	}
	else // ignore, not valid x,y position.
		return false;
}

void Robot::report()
{
	if( placed )
		std::cout << "Output: " << x << "," << y << "," << face << "\n";
	else // ignore
		std::cout << "Robot is not placed!\n";
}