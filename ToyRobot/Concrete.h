#pragma once
#include "Command.h"
#include "Robot.h"
#include <string>


class Place : public Command {
private:

	Robot* robot;
	int _x;
	int _y;
	std::string _face;

public:
	Place( Robot* r, int x, int y, std::string face ) : robot( r ), _x( x ), _y( y ), _face( face ) {}

	void execute();
};


class Move : public Command {
private:

	Robot* robot;


public:
	Move( Robot* r ) : robot( r ) {}

	void execute();
};


class Right : public Command {
private:

	Robot* robot;

public:
	Right( Robot* r ) : robot( r ) {}

	void execute();
};


class Left : public Command {
private:
	Robot* robot;

public:
	Left( Robot* r ) : robot( r ) {}

	void execute();
};


class Report : public Command {
private:
	Robot* robot;

public:
	Report( Robot* r ) : robot( r ) {}

	void execute();
};