#pragma once
class FControle
{
	TCHAR C;
	int32 X = 1;
	int32 Y = 1;
	Map Map;

public:
	void Move(int32 x, int32 y);
	void Select(int32 x, int32 y);

	void Flag();
};

