#pragma once
#include "Actor.h"


class Barrier : public Actor
{
	int hp;
public:
	Barrier(const string& _name, const int _hp, const Vector2f& _pos);
};

