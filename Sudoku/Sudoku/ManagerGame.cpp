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
	cout << "Спасибо, что играли в нашу игру\n";
}
ManagerGame::~ManagerGame()
{

}
void ManagerGame::lvlSelect()
{
	int lvl;
	choiseLevel:
	system("cls");
	cout << "Выберите уровень сложности\n1 - Легко\n2 - Средний\n3 - Сложный\n4 - Выйти из игры\nВыбор: ";
	cin >> lvl;
	if (lvl == 1 || lvl == 2 || lvl == 3)
		level = lvl;
	else if (lvl == 4)
		finish = false;
	else
	{
		system("cls");
		cout << "Некорректный выбор...Попробуйте еще раз\n";
		Sleep(1500);
		goto choiseLevel;
	}
	system("cls");
}
