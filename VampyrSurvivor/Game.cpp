#include "Game.h"
#include "Player.h"

RenderWindow Game::window;
Brightness* Game::brightness;

Game::Game()
{
}

Game::~Game()
{
}

void Game::Start()
{
	window.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Click Dungeon");
	new Player();
}

void Game::Init()
{
}

void Game::Update()
{
	while (window.isOpen())
	{
		window.clear();
		//window.draw();
		window.display();
	}
		
}

void Game::UpdateWindow()
{
}

void Game::DrawWorldUIs()
{
}

void Game::DrawMap()
{
}

void Game::DrawActors()
{
}

void Game::DrawUIs()
{
}

void Game::Stop()
{
}

void Game::Launch()
{
	Start();
	Update();
	Stop();
}

void Game::Close()
{
}
