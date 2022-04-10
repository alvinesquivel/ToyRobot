#pragma once
#include "Robot.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <istream>

class CommandHandler
{

private:
	const std::unordered_set<std::string> validCommands = { "PLACE","MOVE","LEFT","RIGHT","REPORT" };


public:
	std::vector<std::string> split( std::string& _input, const std::string& _delim );
	bool command( Robot& r, std::string& _inst );
	
};

