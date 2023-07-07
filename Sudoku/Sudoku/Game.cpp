#include "Game.h"
Game::Game() : mistake{ 0 }, currentMistake{ 0 }, level{ 0 }, countDeletedElements{ 0 }
{
	for (int i{ 0 }; i < 9; i++)
	{
		for (int j{ 0 }; j < 9; j++)
		{
			VisiableGameField[i][j] = 0;
		}
	}
}
Game::Game(Field field,int lvl) : level{ lvl }, mistake{ 0 }, currentMistake{ 0 }, countDeletedElements{ 0 }
{
	srand(time(nullptr));
	VisiableField(field);
	Suboku(field);
	system("cls");
}
Game::~Game()
{

}
void Game::Suboku(Field field)
{
	int choise;
	while (countDeletedElements != 0)
	{
		
		system("cls");
		getLevel();
		getMistake();
		cout << endl;
		ShowGameField();
		cout << "\n1) �������� �����\n2) ���������� �����\n3) ����� � ����\n�����: ";
		cin >> choise;
		if (choise == 1)
			enterNumber(field);
		if (choise == 2)
			showElement();
		if (choise == 3)
			return;
	}
	cout << "�� �������! �� ������ ������. ���� ���-�� ������: " << mistake << endl;
}
void Game::enterNumber(Field field)
{
	int r, c, answer;
	system("cls");
	enterNumber:
	getLevel();
	getMistake();
	cout << endl;
	ShowGameField();
	cout << "\n\n������� ������: ";
	cin >> r;
	if (!(r >= 1 && r <= 9))
	{
		system("cls");
		cout << "������������ ������...\n";
		Sleep(2000);
		system("cls");
		goto enterNumber;

	}
	r--;
	cout << "\n������� �������: ";
	cin >> c;
	if (!(c >= 1 && c <= 9))
	{
		system("cls");
		cout << "������������ �������...\n";
		Sleep(2000);
		system("cls");
		goto enterNumber;
	}
	c--;
	if (VisiableGameField[r][c]>= 1 && VisiableGameField[r][c] <= 9)
	{
		system("cls");
		cout << "��� ��� ���� �����\n";
		Sleep(2000);
		system("cls");
		goto enterNumber;
	}
	else
	{
		enterValue:
		cout << "������� �����: ";
		cin >> answer;
		if (field.gameField[r][c] == answer)
		{
			system("cls");
			cout << "�������. ���������!\n";
			Sleep(2000);
			countDeletedElements--;
			VisiableGameField[r][c] = answer;
			system("cls");
		}
		else
		{
			system("cls");
			cout << "������...\n";
			Sleep(2000);
			system("cls");
			mistake++;
		}
	}
}
void Game::showElement()
{
	int element;
	system("cls");
	cout << "����� ������� ��������?\n1 2 3 4 5 6 7 8 9\n";
	cin >> element;
	system("cls");
	getLevel();
	getMistake();
	cout << endl;
	for (int i{ 0 }; i < row; i++)
	{
		//����� ��������� �������
		if (i == 0)
		{
			for (int j{ 0 }; j < column + 1; j++)
			{
				if (j == 0)
					cout << "    ";
				else
					cout << j << " ";
				if (j % 3 == 0 && j != 0)
					cout << " ";

			}
		}
		cout << endl;
		if (i % 3 == 0)
			cout << endl;
		for (int j{ 0 }; j < column; j++)
		{
			if (j == 0)//��������� �����
				cout << i + 1 << "  ";
			if (j % 3 == 0)
				cout << " ";
			if (VisiableGameField[i][j] == -858993460)
				cout << "  ";
			else
			{
				if(VisiableGameField[i][j] == element)
					cout << "* ";
				else
					cout << VisiableGameField[i][j] << " ";
			}
		}
	}
	cout << "\n\n��� ������ �� ������, ������� �� ����� �������\n";
	_getch();
}
void Game::getLevel()
{
	if (level == 1)
		cout << "�������: ������\t\t";
	if (level == 2)
		cout << "�������: �������\t\t";
	if (level == 3)
		cout << "�������: �������\t\t";
}
void Game::getMistake()
{
	if (level == 1)
	{
		mistake = 10;
		cout << "������: " << currentMistake << " / " << mistake;
	}
	if (level == 2)
	{
		mistake = 5;
		cout << "������: " << currentMistake << " / " << mistake;
	}
	if (level == 3)
	{
		mistake = 3;
		cout << "������: " << currentMistake << " / " << mistake;
	}
}
void Game::ShowGameField()
{
	cout << endl;
	for (int i{ 0 }; i < row; i++)
	{
		//����� ��������� �������
		if (i == 0)
		{
			for (int j{ 0 }; j < column + 1; j++)
			{
				if (j == 0)
					cout << "    ";
				else
					cout << j << " ";
				if (j % 3 == 0 && j != 0)
					cout << " ";

			}
		}
		cout << endl;
		if (i % 3 == 0)
			cout << endl;
		for (int j{ 0 }; j < column; j++)
		{
			if (j == 0)//��������� �����
				cout << i + 1 << "  ";
			if (j % 3 == 0)
				cout << " ";
			if (VisiableGameField[i][j] == -858993460)
				cout << "  ";
			else
			{
				cout << VisiableGameField[i][j] << " ";
			}
		}
	}
}
void Game::VisiableField(Field field)
{
	int deleteNumber;
	switch (level)
	{
	case 1:
		for (int i{ 0 }; i < 9; i++)
		{
			for (int j{ 0 }; j < 9; j++)
			{
				deleteNumber = rand() % 4 + 1;
				if (deleteNumber == 4)
				{
					countDeletedElements++;
					continue;
				}
				else
				{
					VisiableGameField[i][j] = field.gameField[i][j];
				}
			}
		}
		break;
	case 2:
		for (int i{ 0 }; i < 9; i++)
		{
			for (int j{ 0 }; j < 9; j++)
			{
				deleteNumber = rand() % 4 + 1;
				if (deleteNumber == 3 || deleteNumber == 4)
				{
					countDeletedElements++;
					continue;
				}
				else
				{
					VisiableGameField[i][j] = field.gameField[i][j];
				}
			}
		}
		break;
	case 3:
		for (int i{ 0 }; i < 9; i++)
		{
			for (int j{ 0 }; j < 9; j++)
			{
				deleteNumber = rand() % 4 + 1;
				if (deleteNumber >=2 && deleteNumber <= 4)
				{
					countDeletedElements++;
					continue;
				}
				else
				{
					VisiableGameField[i][j] = field.gameField[i][j];
				}
			}
		}
		break;
	}
}