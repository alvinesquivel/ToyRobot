#pragma once
#include <iostream>
#include <unordered_map>
#include "Robot.h"


void Robot::place( int _X, int _Y, std::string _Face )
{
	if( !placed )
		placed = true;

	position.first = _X;
	position.second = _Y;
	facingDirection = _Face;
}

void Robot::move()
{
	if( !placed )
		return;

	if( facingDirection == "NORTH" )
		position.second += 1;
	else if( facingDirection == "SOUTH" )
		position.second -= 1;
	else if( facingDirection == "EAST" )
		position.first += 1;
	else if( facingDirection == "WEST" )
		position.first -= 1;
}

void Robot::right()
{
	if( !placed )
		return;

	std::unordered_map<std::string, std::string> turnRightDirs{
		{"NORTH", "EAST"}, {"EAST", "SOUTH"},
		{"SOUTH", "WEST"}, {"WEST", "NORTH"}
	};

	facingDirection = turnRightDirs[facingDirection];
}

void Robot::left()
{
	if( !placed )
		return;

	std::unordered_map<std::string, std::string> turnLeftDirs{
		{"NORTH", "WEST"}, {"WEST", "SOUTH"},
		{"SOUTH", "EAST"}, {"EAST", "NORTH"}
	};

	facingDirection = turnLeftDirs[facingDirection];
}