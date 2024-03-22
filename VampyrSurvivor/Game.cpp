#include "Game.h"
#include "ActorManager.h"
#include "InputManager.h"
#include "TimerManager.h"
#include "TextureManager.h"
#include "MenuManager.h"
#include "PathfindingComponent.h"
#include "Mob.h"
#include "SpriteUtils.h"
#include "HUD.h"

RenderWindow Game::window;
Brightness* Game::brightness;
Map* Game::map;


Game::~Game()
{
}

void Game::Start()
{
	player = new Player("Player", ShapeData());
	InitMouseSprite();
	Game::map = new Map();
	window.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Vampyr Survivor");
	window.setMouseCursorGrabbed(true);
	window.setMouseCursorVisible(false);
	MULTI_MOB(MOB_WOLF(RANDOM_POS,Random(10,2)), 15);
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
	mouse = new ShapeObject(ShapeData({}, { 100,100 }, "cursor.png"));
}

void Game::Update()
{
	UpdateWindow();
}

void Game::UpdateWindow()
{
	while (window.isOpen())
	{
		ActorManager::GetInstance().Update();
		InputManager::GetInstance().Update(window);

		TimerManager::GetInstance().Update();
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
	Update();
	Stop();
}

void Game::Close()
{
}
