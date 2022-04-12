#include "Concrete.h"

void Place::execute()
{
	this->robot->place( this->x, this->y, this->face );
}

void Move::execute()
{
	this->robot->move();
}

void Right::execute()
{
	this->robot->right();
}

void Left::execute()
{
	this->robot->left();
}

void Report::execute()
{
	this->robot->report();
}
