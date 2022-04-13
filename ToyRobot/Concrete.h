#pragma once
#include "Command.h"
#include "Robot.h"
#include <string>


class Place : public Command {
private:
	Robot* robot;
	int x;
	int y;
	std::string face;

public:
	Place( Robot* _robot, int _x, int _y, std::string _face ) : robot( _robot ), x( _x ), y( _y ), face( _face ) {}
	void execute();
};


class Move : public Command {
private:
	Robot* robot;

public:
	Move( Robot* _robot ) : robot( _robot ) {}
	void execute();
};


class Right : public Command {
private:
	Robot* robot;

public:
	Right( Robot* _robot ) : robot( _robot ) {}
	void execute();
};


class Left : public Command {
private:
	Robot* robot;

public:
	Left( Robot* _robot ) : robot( _robot ) {}
	void execute();
};


class Report : public Command {
private:
	Robot* robot;

public:
	Report( Robot* _robot ) : robot( _robot ) {}
	void execute();
};