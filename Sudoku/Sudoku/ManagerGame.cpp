#include "ManagerGame.h"

ManagerGame::ManagerGame()
{
	while (finish)
	{
		lvlSelect();
		if (finish == false)
			break;
		Field field;
		Game sudoku(field, level);
	}
	cout << "�������, ��� ������ � ���� ����\n";
}
ManagerGame::~ManagerGame()
{

}
void ManagerGame::lvlSelect()
{
	int lvl;
	choiseLevel:
	system("cls");
	cout << "�������� ������� ���������\n1 - �����\n2 - �������\n3 - �������\n4 - ����� �� ����\n�����: ";
	cin >> lvl;
	if (lvl == 1 || lvl == 2 || lvl == 3)
		level = lvl;
	else if (lvl == 4)
		finish = false;
	else
	{
		system("cls");
		cout << "������������ �����...���������� ��� ���\n";
		Sleep(1500);
		goto choiseLevel;
	}
	system("cls");
}
