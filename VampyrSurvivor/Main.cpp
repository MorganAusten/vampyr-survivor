#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"

int main()
{
	Menu* _menu = new Menu("Menu");
	Game _game;
	_game.Launch();
	return 0;
}