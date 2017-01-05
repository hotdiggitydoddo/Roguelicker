#include "Game.h"

int main(int argc, char** argv)
{
	Game rogueLicker;

	if (!rogueLicker.init())
		return -1;

	rogueLicker.start();

	return 0;
}