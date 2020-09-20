#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include "Math.h"
#include "History.h"
using namespace std;


vector< vector<string>> mainMenu = {
	{"�����/�����"},
	{"�������������� ��������","���������","�������", "��������", "���������", "����������� ��� ���", "�����" },
	{ "�������", "��������� � ����", "�� ���������", "������� ��� ������� �� �����", "�����"},

};

void ShowHeaders() {
	system("cmd /c cls");
	for (int i = 0; i < mainMenu.size(); i++) {
		cout << i << ". " << mainMenu[i][0] << endl;
	}
}

void ShowSubMenu(int n)
{
	
	

		system("cmd /c cls");
		vector<string> subMenu = mainMenu[n];
		for (int i = 1; i < subMenu.size(); i++) {
			cout << n << "." << i - 1 << ". " << subMenu[i] << endl;

		}
		switch (n)
		{
		case 1:
		default:
			break;
		}
	
}


int main()
{
	shared_ptr<Math> math_ptr(new Math());
	shared_ptr<History> histiory_ptr(new History());
	int menuItem;
	int subMenuItem;
	bool subMenuCycle = false;
	string equation;
	setlocale(LC_ALL, "ru");
	while (true) {
		ShowHeaders();
		menuItem = ReadInt();
		if (menuItem == 0)
		{
			return 0;
		}
		if (menuItem < 3 && menuItem > 0)
		{
			subMenuCycle = true;

		}
		
		while (subMenuCycle) {
			ShowSubMenu(menuItem);
			switch (menuItem) {
			case 1:
				cout << equation << endl;
				subMenuItem = ReadInt();
				if (subMenuItem > 5) continue;

				tie(subMenuCycle, equation) =  math_ptr->Calculate((Math::Operation)subMenuItem);
				histiory_ptr->AddToHistory(equation);
				break;
			case 2:
				cin >> subMenuItem;
				switch (subMenuItem)
				{
				case 0:
					histiory_ptr->SafeToFile();
					break;
				case 1: 
					histiory_ptr->DeleteHistory();
					break;
				case 2:
					histiory_ptr->ShowHistory();

					system("pause");
					break;
				case 3:
					subMenuCycle = false;
					break;
				default:
					cout << "�� ������ ������� ��������" << endl;
					break;
				}
			default:
				cout << "������� ������ ����� ����";
				break;
			}
	

				
			
			
		}
	}

	return 0;
}