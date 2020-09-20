#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <tuple>
class Math
{

public:
	enum Operation
	{
		MULTIPLICATION,
		DIVISION,
		SUMMATION,
		SUBSTRACTION,
		REPEAT,
		RETURN,
		FIRST_OPERATION
	};
	

	std::tuple<bool, std::string> Calculate(Operation op);
	
private:
	double a;
	double b;
	double c;
	char sign;
	Operation lastOperation = FIRST_OPERATION;

};