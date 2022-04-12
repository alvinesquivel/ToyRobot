#include "Concrete.h"

void Place::execute()
{
	this->robot->place( this->_x, this->_y, this->_face );
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
