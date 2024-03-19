#pragma once
#include "Actor.h"


class Player : public Actor
{
	View* view;
public:
	Player();
	Player(const string& _name ,const ShapeData& _data);

private:
	virtual void Register() override;
};

