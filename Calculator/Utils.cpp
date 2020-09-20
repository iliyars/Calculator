#include <iostream>


int ReadInt()
{
	while (true) 
	{
		
		int a;
		std::cin >> a;

		
		if (std::cin.fail())
		{
			std::cin.clear(); 
			std::cin.ignore(32767, '\n'); 

		}
		else
		{
			std::cin.ignore(32767, '\n');

			return a;
		}
	}
}