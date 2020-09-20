#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Utils.h"
#include "Utils.h"
class History
{
public:
	History();
	void DeleteHistory();
	void SafeToFile();
	void AddToHistory(std::string);
	void ShowHistory();
	//~History();
private:
	std::vector<std::string> historyOperations;
	std::string path = "History.txt";
	std::fstream fs;

};