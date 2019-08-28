#pragma once
class FIntro
{
	int32 Stage = 0;
	int32 X = 22;
	int32 Y = 9;
public:
	int32 _X = 0;
	int32 _Y = 0;

	const char* Intro =
	{
		"----------------------"
		"|                    |"
		"|                    |"
		"|                    |"
		"|      >Easy         |"
		"|       Normal       |"
		"|       Hord         |"
		"|                    |"
		"----------------------"
	};

	void GetIntro();
	void Level();
};

