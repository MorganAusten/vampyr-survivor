#include "Game.h"
#include "ActorManager.h"
#include "InputManager.h"
#include "TimerManager.h"

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
	new Player();
	window.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Vampyr Survivor");
}

void Game::Init()
{
}

void Game::Update()
{
	while (window.isOpen())
	{
		ActorManager::GetInstance().Update();
		InputManager::GetInstance().Update(window);
		TimerManager::GetInstance().Update();

		window.clear();
		for (Actor* _actor : ActorManager::GetInstance().GetAllValues())
		{
			window.draw(*_actor->GetShape());
		}
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
