#include "Game.h"
#include "ActorManager.h"
#include "InputManager.h"
#include "TimerManager.h"
#include "TextureManager.h"
#include "SpawnerManager.h"
#include "MenuManager.h"
#include "PathfindingComponent.h"
#include "Mob.h"
#include "SpriteUtils.h"
#include "HUD.h"

RenderWindow Game::window;
Brightness* Game::brightness;
Map* Game::map;

Game::Game()
{
}

Game::~Game()
{
}

void Game::Start()
{
	mainMenu = true;
	window.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Vampyr Survivor");
	if (mainMenu)
		UpdateMenu();
	player = new Player("Player", ShapeData());
	InitMouseSprite();
	Game::map = new Map();
	window.setMouseCursorGrabbed(true);
	window.setMouseCursorVisible(false);
	new ActionMap("Game",
		{
			ActionData("CloseWindow", [this]() { window.close(); }, {Event::KeyPressed,Keyboard::Escape}),
		});
	SpawnerManager::GetInstance().StartBeetwenWaveTimer();
}

void Game::InitMouseSprite()
{
	mouse = new ShapeObject(ShapeData({}, { 100.f,100.f }, "cursor.png"));
}

void Game::Update()
{
}

void Game::UpdateMenu()
{
	new Menu("MainMenu", this);
	while (window.isOpen() && mainMenu)
	{
		InputManager::GetInstance().Update(window);
		window.clear();
		DrawUIs();
		window.display();
	}
}

void Game::UpdateGame()
{
	while (window.isOpen())
	{
		ActorManager::GetInstance().Update();
		TimerManager::GetInstance().Update();
		InputManager::GetInstance().Update(window);
		Vector2f _a = InputManager::GetInstance().GetWorldPosition();
		Vector2f _b = Vector2f(mouse->GetShapeSize().x / 2.5f, mouse->GetShapeSize().y / 3.f);
		Vector2f _result = Vector2f((_a.x - _b.x), (_a.y - _b.y));
		mouse->SetShapePosition(_result);
		window.clear();
		//Mode world
		window.setView(*player->GetView());
		for (Actor* _actor : ActorManager::GetInstance().GetAllValues())
		{
			window.draw(*_actor->GetShape());
		}
		DrawWorldUIs();
		// Mode Canva
		window.setView(window.getDefaultView());
		DrawUIs();
		window.draw(*mouse->GetShape());
		window.display();
	}

}


void Game::DrawWorldUIs()
{
	for (Canvas* _canvas : HUD::GetInstance().GetAllValues())
	{
		if (!_canvas->IsVisible()) continue;
		for (Widget* _widget : _canvas->GetWorldWidgets())
		{
			if (!_widget || !_widget->IsVisible()) continue;
			window.draw(*_widget->GetDrawable());
		}
	}
}

void Game::DrawUIs()
{
	for (Canvas* _canvas : HUD::GetInstance().GetAllValues())
	{
		if (!_canvas->IsVisible()) continue;
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
	UpdateGame();
	Stop();
}

void Game::Close()
{
}
