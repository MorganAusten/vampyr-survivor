#pragma once
#include "Actor.h"
#include "Label.h"
#include "Canvas.h"

struct PlayerStat
{
	int dammage;
	int money;
	Label* moneyText;
	Canvas* canvas;

public:
	PlayerStat() 
	{
		dammage = 0;
		money = 0;

		canvas = new Canvas("PlayerStat");
		const Vector2f& _positon = Vector2f(1280 * 90 / 100, 720 * 5 / 100);
		moneyText = new Label(TextData(to_string(money), _positon, "Font.ttf", 30, Color::Red));
		canvas->AddWidget(moneyText);
	}
	PlayerStat(int _dammage, int _money, int _level)
	{
		dammage = _dammage;
		money = _money;

		canvas = new Canvas("PlayerStat");
		const Vector2f& _positon = Vector2f(1280 * 90 / 100, 720 * 5 / 100);
		moneyText = new Label(TextData(to_string(money), _positon, "Font.ttf", 30, Color::Red));
		canvas->AddWidget(moneyText);
	}

	void SetString(const string& _value)
	{
		moneyText->SetString(_value);
	}
};


class Player : public Actor
{
	View* view;
	Vector2f direction;
	PlayerStat* stat;
	int dammage;

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

