#include "Game.h"
#include "ActorManager.h"
#include "InputManager.h"
#include "TimerManager.h"
#include "TextureManager.h"
#include "MenuManager.h"
#include "PathfindingComponent.h"
#include "HUD.h"

RenderWindow Game::window;
Brightness* Game::brightness;
Map* Game::map;


Game::~Game()
{
}

void Game::Start()
{
	player = new Player("Player",ShapeData());
	Game::map = new Map();
	//TODO remove(test)
	player->pathComp = new PathfindingComponent(player);
	player->pathComp->ComputeNewPath();
	//
	window.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Vampyr Survivor");
	window.setMouseCursorGrabbed(true);
	window.setMouseCursorVisible(false);
	InitMouseSprite();

	new ActionMap("Game",
		{
			ActionData("CloseWindow", [this]() { window.close(); }, {Event::KeyPressed,Keyboard::Escape}),
		});
}

void Game::Init()
{
}

void Game::InitMouseSprite()
{
	mouse = new ShapeObject(ShapeData({},{50,50},"cursor.png"));
	//mouse->SetOriginAtMiddle();
}

void Game::Update()
{
	while (window.isOpen())
	{
		ActorManager::GetInstance().Update();
		InputManager::GetInstance().Update(window);
		
		TimerManager::GetInstance().Update();

		mouse->SetShapePosition(InputManager::GetInstance().GetWorldPosition() - Vector2f(mouse->GetShapeSize().x / 2.5f,mouse->GetShapeSize().y / 3.f));
		window.clear();
		window.setView(*player->GetView());
		for (Actor* _actor : ActorManager::GetInstance().GetAllValues())
		{
			window.draw(*_actor->GetShape());
		}
		DrawWorldUIs();
		window.setView(window.getDefaultView());
		DrawUIs();
		window.draw(*mouse->GetShape());
		window.display();
	}
}

void Game::UpdateWindow()
{

}

void Game::DrawWorldUIs()
{
	for (Canvas* _canvas : HUD::GetInstance().GetAllValues())
	{
		for (Widget* _widget : _canvas->GetWorldWidgets())
		{
			if (!_widget->IsVisible()) continue;
			window.draw(*_widget->GetDrawable());
		}
	}
}

void Game::DrawMap()
{

}

void Game::DrawActors()
{
}

void Game::DrawUIs()
{
	for (Canvas* _canvas : HUD::GetInstance().GetAllValues())
	{
		for (Widget* _widget : _canvas->GetUiWidgets())
		{
			if (!_widget->IsVisible()) continue;
			window.draw(*_widget->GetDrawable());
		}
	}
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
