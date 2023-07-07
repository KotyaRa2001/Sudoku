#pragma once
#define row 9
#define column 9
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

class Field
{
	private:
		int gameField[row][column];
		void transposing();
		void swap_rows_small();
		void swap_colums_small();
		void swap_rows_area();
		void swap_colums_area();
		friend class Game;
	public:
		Field();
		~Field();
		void ShowField();
};

