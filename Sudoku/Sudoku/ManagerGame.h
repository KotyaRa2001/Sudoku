#pragma once
#include <iostream>
#include "windows.h"
#include "Field.h"
#include "Game.h"
using namespace std;

class ManagerGame
{
	private:
		int level;
		bool finish;
	public:
		ManagerGame();
		~ManagerGame();
		void lvlSelect();
};

