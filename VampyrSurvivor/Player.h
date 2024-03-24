#pragma once
#include "Actor.h"
#include "Label.h"
#include "Canvas.h"
#include "SpriteUtils.h"
#include "Shop.h"

struct PlayerStat
{
	int dammage;
	int life;
	int money;
	int score;
	int waveTimer;
	Label* moneyText;
	Label* scoreText;
	Label* waveTimerText;
	Label* lifeText;
	Canvas* canvas;
public:

	PlayerStat(const int& _dammage,const int& _life, const int& _money, const int& _level,const int& _waveTimer ,const Vector2f& _pos )
	{
		dammage = _dammage;
		life = _life;
		money = _money;
		score = _money;
		waveTimer = _waveTimer;
		canvas = new Canvas("PlayerStat");
		const Vector2f& _position = _pos ;
		moneyText = new Label(TextData(to_string(money), _position, "Font.ttf", 30, Color::Red));
		scoreText = new Label(TextData(to_string(score), Vector2f(_position.x, _position.y + 20), "Font.ttf", 30, Color::White));
		waveTimerText = new Label(TextData(to_string(waveTimer), Vector2f(20, _position.y), "Font.ttf", 30, Color::White));
		lifeText = new Label(TextData(to_string(life), Vector2f(500, _position.y), "Font.ttf", 30, Color::Green));
		canvas->AddWidget(moneyText);
		canvas->AddWidget(scoreText);
		canvas->AddWidget(waveTimerText);
		canvas->AddWidget(lifeText);
	}

	void SetStringMoney(const int& _value)
	{
		string _str = "gold: " + to_string(_value);
		moneyText->SetString(_str);
	}

	void SetStringScore(const int& _value)
	{
		string _str = "score: " + to_string(_value);
		scoreText->SetString(_str);
	}

	void SetStringWaveTimer(const int& _value)
	{
		waveTimerText->SetVisible(_value <= 0 ? false: true);
		string _str = to_string(_value);
		waveTimerText->SetString(_str);
	}

	void SetStringLife(const int& _value)
	{
		lifeText->SetVisible(_value <= 0 ? false : true);
		string _str = to_string(_value);
		lifeText->SetString(_str);
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
	void DecreaseLife() { stat->life--; stat->SetStringLife(stat->life); }
private:
	void InitInput();
	void InitView();
	void OnClick();
	void ApplyDammages();
	void GainMoney();
	virtual void Register() override;
};

