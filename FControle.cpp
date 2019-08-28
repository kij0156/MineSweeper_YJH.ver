#include "pch.h"
#include "FControle.h"
#include "FSearch.h"

void FControle::Move(int x, int y)
{
	C = _getch();
	switch (C)
	{
	case 72:
		if (Map.GetMap(Map.Stage, X, Y - 1) != '-')
		{
			--Y;
		}
		break;
	case 80:
		if (Map.GetMap(Map.Stage, X, Y + 1) != '-')
		{
			++Y;
		}
		break;
	case 75:
		if (Map.GetMap(Map.Stage, X-1, Y) != '|')
		{
			--X;
		}
		break;
	case 77:
		if (Map.GetMap(Map.Stage, X + 1, Y) != '|')
		{
			++X;
		}
		break;
	}

	if (C == 'a')
	{
		Flag();
	}

	if (C == ' ')
	{
		if (Map.DData[Map.Stage][Y][X] != '!')
		{
			Select(x, y);
		}
	}
	Gotoxy(0, 0);
	Map.DrawMap(Map.Stage, x, y);
	Gotoxy(X, Y);
	cout << "@";
}

void FControle::Select(int x, int y)
{
	FSearch Search;

	if (Map.GetMap(Map.Stage, X, Y) == '*')
	{
		Map.DData[Map.Stage][y][x] = '*';
		for (int i = 0; i < y; ++i)
		{
			for (int j = 0; j < x; ++j)
			{
				if (Map.GetMap(Map.Stage, j, i) == '*')
				{
					Map.DData[Map.Stage][i][j] = '*';
				}
			}
		}
		Gotoxy(0, 0);
		Map.DrawMap(Map.Stage, x, y);
		exit(0);
	}
	else
	{
		Search.Find(Map.Stage, X, Y);
		Gotoxy(0, 0);
		Map.DrawMap(Map.Stage, x, y);
	}
}


void FControle::Flag()
{
	if (Map.DData[Map.Stage][Y][X] != '!')
	{
		Map.DData[Map.Stage][Y][X] = '!';
	}
	else
	{
		Map.DData[Map.Stage][Y][X] = '#';
	}
}