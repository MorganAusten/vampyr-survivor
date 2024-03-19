#pragma once
#include "Actor.h"


class Barrier : public Actor
{
	int hp;
public:
	Barrier(const Vector2f& _pos);
};

