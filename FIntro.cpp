#include "pch.h"
#include "FIntro.h"


void FIntro::GetIntro()
{
	for (int32 y = 0; y < Y; ++y)
	{
		for (int32 x = 0; x < X; ++x)
		{
			int32 Index = X * y + x;
			cout << Intro[Index];
		}
		cout << endl;
	}
}

void FIntro::Level()
{
	Map Map;

	while (true)
	{
		TCHAR C = _getch();
		switch (C)
		{
		case 72:
			if (Stage != 0)
			{
				Gotoxy(7, 4 + Stage);
				cout << ' ';
				--Stage;
				Gotoxy(7, 4 + Stage);
				cout << ">";
			}
			break;
		case 80:
			if (Stage != 2)
			{
				Gotoxy(7, 4 + Stage);
				cout << ' ';
				--Stage;
				Gotoxy(7, 4 + Stage);
				cout << ">";
			}
			break;
		}
		if (C == ' ')
		{
			switch (Stage)
			{
			case 0:
				_X = Map.Lv1_x;
				_Y = Map.Lv1_y;
				break;
			case 1:
				_X = Map.Lv2_x;
				_Y = Map.Lv2_y;
				break;
			case 2:
				_X = Map.Lv3_x;
				_Y = Map.Lv3_y;
				break;
			}
			break;
		}

	}
	Map.Stage = Stage;
	Map.Draw(Stage, _X, _Y);
	system("cls");
	Map.DrawMap(Stage, _X, _Y);
	Gotoxy(1, 1);
	cout << "@";
}