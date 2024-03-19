#pragma once
#include "Actor.h"

class Entity : public Actor
{
protected:
	float hp = 0;
public:
	Entity() = default;
public:
	inline float GetHP()const { return hp; }
	inline void SetHP(float _hp) { hp = _hp; }
};

