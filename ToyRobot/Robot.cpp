#pragma once
#include "Robot.h"

bool Robot::place( int _X, int _Y, std::string _Face )
{
	if( !this->placed )
		this->placed = true;

	if( !this->table.isValidPosition( _X, _Y ) )
	{
		std::cout << "INVALID X or Y POSITION. (MUST NOT BE GREATER THAN 4 OR LESS THAN 0)\n";
		return false;
	}

	if( !this->direction.isValidDirection( _Face ) )
	{
		std::cout << "INVALID FACING DIRECTION. (NORTH,EAST,WEST,SOUTH)\n";
		return false;
	}

	this->position.first = _X;
	this->position.second = _Y;
	this->direction.facingDirection = _Face;
	return true;
}

bool Robot::move()
{
	if( !this->placed )
		return false;

	int tmp_X = this->position.first;
	int tmp_Y = this->position.second;

	if( this->direction.facingDirection == "NORTH" )
		tmp_Y += 1;
	else if( this->direction.facingDirection == "SOUTH" )
		tmp_Y -= 1;
	else if( this->direction.facingDirection == "EAST" )
		tmp_X += 1;
	else if( this->direction.facingDirection == "WEST" )
		tmp_X -= 1;

	if( this->table.isValidPosition( tmp_X, tmp_Y ) )
	{
		this->position.first = std::move( tmp_X );
		this->position.second = std::move( tmp_Y );
		
		return true;
	}
	else
		return false;
}

bool Robot::right()
{
	if( !this->placed )
		return false;

	this->direction.turnRight();
	return true;
}

bool Robot::left()
{
	if( !this->placed )
		return false;

	this->direction.turnLeft();
	return true;
}

void Robot::report()
{
	if( !this->placed )
	{
		std::cout << "Robot is not placed!\n";
		return;
	}
		

	std::cout << "Output: " << this->position.first << "," << this->position.second << "," << this->direction.facingDirection << std::endl;
}