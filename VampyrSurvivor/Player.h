#pragma once
#include "Actor.h"


class Player : public Actor
{
public:
	Player();

private:
	virtual void Register() override;
};

