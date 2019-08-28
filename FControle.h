#pragma once
class FControle
{
	TCHAR C;
	int32 X = 1;
	int32 Y = 1;
	Map Map;

public:
	void Move(int x, int y);
	void Select(int x, int y);

	void Flag();
};

