#include "pch.h"
#include "FSearch.h"


void FSearch::Find(int St, int _X, int _Y)
{
	Map Map;
	if (Map.GetMap(St, _X, _Y) >= One && Map.GetMap(St, _X, _Y) <= Nine)
	{
		Map.DData[St][_Y][_X] = Map.GetMap(St, _X, _Y);
	}
	if (Map.GetMap(St, _X, _Y) == ' ')
	{
		Map.DData[St][_Y][_X] = ' ';
		while (1)
		{
			if (Map.GetMap(St, _X + X, _Y) >= One && Map.GetMap(St, _X + X, _Y) <= Nine || Map.GetMap(St, _X + X, _Y) == '|')
			{
				Map.DData[St][_Y][_X + X] = Map.GetMap(St,_X + X, _Y);
				X = 0;
				Y = 0;
				Y1 = 0;
				break;
			}
			if (Map.GetMap(St, _X + X, _Y + Y) != ' ' && Map.GetMap(St, _X + X, _Y + Y1) != ' ')
			{
				Map.DData[St][_Y + Y][_X + X] = Map.GetMap(St, _X + X, _Y + Y);
				Map.DData[St][_Y + Y1][_X + X] = Map.GetMap(St, _X + X, _Y + Y1);
				Y = 0;
				Y1 = 0;
				--X;
			}
			if (Map.GetMap(St, _X + X, _Y + Y1) == ' ')
			{
				Map.DData[St][_Y + Y1][_X + X] = ' ';
				for (int r = -1; r < 2; ++r)
				{
					for (int c = -1; c < 2; ++c)
					{
						if (!(r | c))continue;
						if (Map.GetMap(St, _X + X + c, _Y + Y1 + r) == ' ')
							Map.DData[St][_Y + Y1 + r][_X + X + c] = ' ';
						else
							Map.DData[St][_Y + Y1 + r][_X + X + c] = Map.GetMap(St, _X + X + c, _Y + Y1 + r);
					}
					++Y1;
				}
			}
			while (1)
				if (Map.GetMap(St, _X + X, _Y) >= One && Map.GetMap(St, _X + X, _Y) <= Nine || Map.GetMap(St, _X + X, _Y) == '|')
				{
					Map.DData[St][_Y][_X + X] = Map.GetMap(St, _X + X, _Y);
					X = 0;
					Y = 0;
					Y1 = 0;
					break;
				}
			if (Map.GetMap(St, _X + X, _Y + Y) != ' ' && Map.GetMap(St, _X + X, _Y + Y1) != ' ')
			{
				Map.DData[St][_Y + Y][_X + X] = Map.GetMap(St, _X + X, _Y + Y);
				Map.DData[St][_Y + Y1][_X + X] = Map.GetMap(St, _X + X, _Y + Y1);
				Y = 0;
				Y1 = 0;
				--X;
			}
			if (Map.GetMap(St, _X + X, _Y + Y1) == ' ')
			{
				Map.DData[St][_Y + Y1][_X + X] = ' ';
				for (int r = -1; r < 2; ++r)
				{
					for (int c = -1; c < 2; ++c)
					{
						if (!(r | c))continue;
						if (Map.GetMap(St, _X + X + c, _Y + Y1 + r) == ' ')
							Map.DData[St][_Y + Y1 + r][_X + X + c] = ' ';
						else
							Map.DData[St][_Y + Y1 + r][_X + X + c] = Map.GetMap(St, _X + X + c, _Y + Y1 + r);
					}
					++Y1;
				}
			}
		}
	}

}
