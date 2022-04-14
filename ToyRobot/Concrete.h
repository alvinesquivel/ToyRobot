#pragma once
#include "Command.h"
#include "Robot.h"
#include <string>

// Concrete commands

class Place : public Command {
private:
	Robot* robot;
	int x;
	int y;
	std::string facingDirection;

public:
	Place( Robot* _robot, int _x, int _y, std::string _facingDirection ) : robot( _robot ), x( _x ), y( _y ), facingDirection( _facingDirection ) {}
	void execute();
};


class Move : public Command {
private:
	Robot* robot;

public:
	Move( Robot* _robot ) : robot( _robot ) {}
	void execute();
};


class Rotate : public Command {
private:
	Robot* robot;
	std::string rotation;

public:
	Rotate( Robot* _robot, std::string _rotation ) : robot( _robot ), rotation( _rotation ) {}
	void execute();
};

