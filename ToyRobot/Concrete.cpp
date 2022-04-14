#include "Concrete.h"

void Place::execute()
{
	this->robot->place( this->x, this->y, this->facingDirection );
}

void Move::execute()
{
	this->robot->move();
}

void Rotate::execute()
{
	this->robot->rotate( this->rotation );
}
