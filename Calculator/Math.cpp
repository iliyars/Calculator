#include "Math.h"
#include "Utils.h"


std::tuple<bool, std::string> Math::Calculate(Operation op)
{
	
	
	system("cmd /c cls");
	switch (op)
	{
	case Math::MULTIPLICATION:
	    sign = '*';
		std::cout << "������� ����� ��� ������������: " << std::endl;
		a = ReadInt();
		b = ReadInt();
		
		c = a * b;
		break;

	case Math::DIVISION:
		sign = '/';
		std::cout << "������� ����� ��� �������: " << std::endl;
		a = ReadInt();
		b = ReadInt();
		c = a / b;
		break;

	case Math::SUMMATION:
		sign = '+';
		std::cout << "������� ����� ��� �����: " << std::endl;
		a = ReadInt();
		b = ReadInt();;
		c = a + b;
		break;

	case Math::SUBSTRACTION:
		sign = '-';
		std::cout << "������� ����� ��� ���������: " << std::endl;
		a = ReadInt();
		b = ReadInt();
		c = a - b;
		break;

	case Math::REPEAT:
		Calculate(lastOperation);
		break;
	case Math::RETURN:
		return{ false, "" };
	

	default:
		std::cout << "�� ����� ������� ��������";
		break;
	}
	lastOperation = op;
	std::ostringstream a_str, b_str, c_str;
	a_str << a;
	b_str << b;
	c_str << c;
	std::string equation = a_str.str() + " " + sign + " " + b_str.str() + " = " + c_str.str();
	std::cout << equation<<std::endl; 
	return { true, equation };

}