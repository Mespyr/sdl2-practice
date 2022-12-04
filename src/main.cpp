#include "include/game.h"

int main()
{
	Game game("Epic Game", 500, 500);
	if (game.init() != 0)
		return 1;

	return 0;
}
