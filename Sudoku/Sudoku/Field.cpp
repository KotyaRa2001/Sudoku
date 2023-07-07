#include "Field.h"

Field::Field()
{
	srand(time(nullptr));
	int genStep;
	int generateField[9][9] =
	{
		{1,2,3,4,5,6,7,8,9},
		{4,5,6,7,8,9,1,2,3},
		{7,8,9,1,2,3,4,5,6},
		{2,3,4,5,6,7,8,9,1},
		{5,6,7,8,9,1,2,3,4},
		{8,9,1,2,3,4,5,6,7},
		{3,4,5,6,7,8,9,1,2},
		{6,7,8,9,1,2,3,4,5},
		{9,1,2,3,4,5,6,7,8},
	};
	for (int i{0}; i < row; i++)
	{
		for (int j{ 0 }; j < column; j++)
		{
			gameField[i][j] = generateField[i][j];
		}
	}	
	for (int i{ 0 }; i < 5; i++)
	{
		genStep = rand() % 6;
		if (genStep == 0)
			transposing();
		if (genStep == 1)
			swap_rows_small();
		if (genStep == 2)
			swap_colums_small();
		if (genStep == 3)
			swap_rows_area();
		if (genStep == 4)
			swap_colums_area();
	}
}
Field::~Field()
{

}
void Field::transposing()
{
	int newGameField[9][9];
	for (int i{ 0 }; i < row; i++)
	{
		for (int j{ 0 }; j < column; j++)
		{
			newGameField[j][i] = gameField[i][j];
		}
	}
	for (int i{ 0 }; i < row; i++)
	{
		for (int j{ 0 }; j < column; j++)
		{
			gameField[i][j] = newGameField[i][j];
		}
	}
}
void Field::swap_rows_small()
{
	int container;
	int sRow1 = rand() % 3;
	int sRow2 = rand() % 3;
	for (int j{ 0 }; j < column; j++)
	{
			container = gameField[sRow1][j];
			gameField[sRow1][j] = gameField[sRow2][j];
			gameField[sRow2][j] = container;
	}
	sRow1 = rand() % 3 + 3;
	sRow2 = rand() % 3 + 3;
	for (int j{ 0 }; j < column; j++)
	{
		container = gameField[sRow1][j];
		gameField[sRow1][j] = gameField[sRow2][j];
		gameField[sRow2][j] = container;
	}
	sRow1 = rand() % 3 + 6;
	sRow2 = rand() % 3 + 6;
	for (int j{ 0 }; j < column; j++)
	{
		container = gameField[sRow1][j];
		gameField[sRow1][j] = gameField[sRow2][j];
		gameField[sRow2][j] = container;
	}
}
void Field::swap_colums_small()
{
	int container;
	int sColumn1 = rand() % 3;
	int sColumn2 = rand() % 3;
	for (int i{ 0 }; i < row; i++)
	{
		for (int j{ 0 }; j < 3; j++)
		{
			container = gameField[i][sColumn1];
			gameField[i][sColumn1] = gameField[i][sColumn2];
			gameField[i][sColumn2] = container;
		}
	}
	sColumn1 = rand() % 3 + 3;
	sColumn2 = rand() % 3 + 3;
	for (int i{ 0 }; i < row; i++)
	{
		for (int j{ 3 }; j < 6; j++)
		{
			container = gameField[i][sColumn1];
			gameField[i][sColumn1] = gameField[i][sColumn2];
			gameField[i][sColumn2] = container;
		}
	}
	sColumn1 = rand() % 3 + 6;
	sColumn2 = rand() % 3 + 6;
	for (int i{ 0 }; i < row; i++)
	{
		for (int j{ 6 }; j < 9; j++)
		{
			container = gameField[i][sColumn1];
			gameField[i][sColumn1] = gameField[i][sColumn2];
			gameField[i][sColumn2] = container;
		}
	}
}
void Field::swap_rows_area()
{
	transposing();
	swap_rows_small();
	transposing();
}
void Field::swap_colums_area()
{
	transposing();
	swap_colums_small();
	transposing();
}
void Field::ShowField()
{
	for (int i{ 0 }; i < row; i++)
	{
		if (i % 3 == 0)
			cout << endl;
		for (int j{ 0 }; j < column; j++)
		{
			if (j % 3 == 0)
				cout << " ";
			cout << gameField[i][j] << " ";
		}
		cout << endl;
	}
}