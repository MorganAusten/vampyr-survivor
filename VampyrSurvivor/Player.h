#pragma once
#include "Actor.h"
#include "Label.h"
#include "Canvas.h"
#include "SpriteUtils.h"
#include "Shop.h"

struct PlayerStat
{
	int dammage;
	int money;
	int score;
	int waveTimer;
	Label* moneyText;
	Label* scoreText;
	Label* waveTimerText;
	Canvas* canvas;
public:

	PlayerStat(const int& _dammage,const int& _money, const int& _level,const int& _waveTimer ,const Vector2f& _pos )
	{
		dammage = _dammage;
		money = _money;
		score = _money;
		waveTimer = _waveTimer;
		canvas = new Canvas("PlayerStat");
		const Vector2f& _position = _pos ;
		moneyText = new Label(TextData(to_string(money), _position, "Font.ttf", 30, Color::Red));
		scoreText = new Label(TextData(to_string(score), Vector2f(_position.x, _position.y + 20), "Font.ttf", 30, Color::White));
		waveTimerText = new Label(TextData(to_string(waveTimer), Vector2f(20, _position.y), "Font.ttf", 30, Color::White));
		canvas->AddWidget(moneyText);
		canvas->AddWidget(scoreText);
		canvas->AddWidget(waveTimerText);
	}

	void SetString(const string& _value)
	{
		moneyText->SetString(_value);
	}
};

class PathfindingComponent;

class Player : public Actor
{
	float viewZoom;
	View* view;
	Vector2f viewOffset;
	Vector2f direction;
	PlayerStat* stat;
	Shop* shop;
	int dammage;

public:
	//TODO Remove(Test)
	PathfindingComponent* pathComp;
	PlayerStat* GetStat() { return stat; }


public:
	Player();
	Player(const string& _name ,const ShapeData& _data);
	~Player();

public:
	View* GetView() { return view; }

public:
	virtual void Update(const float _deltaTime) override;

private:
	void InitInput();
	void InitView();
	void OnClick();
	virtual void Register() override;
};

