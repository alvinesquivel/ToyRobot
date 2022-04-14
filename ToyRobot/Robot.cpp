#pragma once
#include <iostream>
#include <unordered_map>
#include "Robot.h"


void Robot::place( int _X, int _Y, std::string _FacingDirection )
{
	if( !placed )
		placed = true;

	position.first = _X;
	position.second = _Y;

	if( _FacingDirection == "NORTH" )
		facingDirection = NORTH;
	else if( _FacingDirection == "EAST" )
		facingDirection = EAST;
	else if( _FacingDirection == "SOUTH" )
		facingDirection = SOUTH;
	else if( _FacingDirection == "WEST" )
		facingDirection = WEST;
}

void Robot::move()
{
	if( !placed )
		return;

	switch( facingDirection )
	{
	case NORTH:
		position.second += 1;
		break;
	case EAST:
		position.first += 1;
		break;
	case SOUTH:
		position.second -= 1;
		break;
	case WEST:
		position.first -= 1;
		break;
	default:
		break;
	}
}

void Robot::rotate( std::string _toWhat )
{
	if( !placed )
		return;

	if( _toWhat == "RIGHT" )
		facingDirection = (facingDirection + 1) % 4;
	else if( _toWhat == "LEFT" )
		facingDirection = (facingDirection + 3) % 4;
}
