#pragma once
#include "Command.h"

// Invoker
class Invoker {
private:
	Command* concreteCmd;
	
public:
	~Invoker()
	{
		delete concreteCmd;
	}

	void setCommand( Command* _command );
	void executeCommand();
};
