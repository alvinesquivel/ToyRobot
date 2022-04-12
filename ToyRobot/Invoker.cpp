#pragma once
#include "Invoker.h"

void Invoker::setCommand( Command* command )
{
	this->concreteCmd = command;
}


void Invoker::executeCommand()
{
	if( this->concreteCmd )
		this->concreteCmd->execute();
}