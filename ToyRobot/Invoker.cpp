#pragma once
#include "Invoker.h"

void Invoker::setCommand( Command* _command )
{
	this->concreteCmd = _command;
}


void Invoker::executeCommand()
{
	if( this->concreteCmd )
		this->concreteCmd->execute();
}