#pragma once
#include <string>

class Error
{
protected:
	std::string msg;

public:
	Error(std::string const& am);
	~Error();

	const std::string& mensaje()const {return msg;};

};