#pragma once
#define row 9
#define column 9
#include <iostream>
#include <ctime>
#include<conio.h>
#include "windows.h"
#include "Field.h"
using namespace std;

class Game
{
	private:
		int VisiableGameField[row][column];
		int level;
		int currentMistake;
		int mistake;
		int countDeletedElements;
	public:
		Game();
		Game(Field field,int lvl);
		~Game();
		void VisiableField(Field field);
		void ShowGameField();
		void Suboku(Field field);
		void getLevel();
		void getMistake();
		void showElement();
		void enterNumber(Field field);
};

