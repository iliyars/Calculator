#include "History.h"

History::History() {
	fs.open(path, std::fstream::in | std::fstream::out | std::fstream::app);
	if (!fs.is_open())
	{
		std::cout << "������ �������� �����" << std::endl;
	}
}


void History::AddToHistory(std::string eq)
{
	if(eq != "")
	historyOperations.push_back(eq);
 }

void History::DeleteHistory()
{
	historyOperations.clear();
	std::cout << "������� �������� ������� ������ �������" << std::endl;
	system("pause");
}

void History::ShowHistory()
{
	system("cmd /c cls");
	fs.clear();
	fs.seekg(0);

	
	
	std::string line;
	while (!fs.eof())
	{
		std::getline(fs, line);
		std::cout << line << std::endl;
	}
	

}

void History::SafeToFile()
{
	fs.clear();
	for (int i = 0; i < historyOperations.size(); i++)
	{
		fs << historyOperations[i] << std::endl;
	}
	std::cout << "������� �������� ������� ������ ���������" << std::endl;
	system("pause");
}

