#include "pch.h"
#include "FIntro.h"
#include "FControle.h"

int main()
{
	srand(time(0));

	FIntro Intro;
	FControle Move;

	Intro.GetIntro();
	Intro.Level();
	while (true)
	{
		Move.move(Intro._X, Intro._Y);
	}

	return 0;
}