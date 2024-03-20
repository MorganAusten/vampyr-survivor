#pragma once
#include "Actor.h"
#include "ProgressLabel.h"

class ProgressBar;
class Entity : public Actor
{
protected:
	float maxHp= 0;
	float hp = 0;
	ProgressBar* lifeBar;
public:
	Entity() = default;
	Entity(const string& _name, const ShapeData& _data, const CollisionType& _collisionType);
public:
	inline ProgressBar* GetLifeBar()const { return lifeBar; }
	inline float GetHP()const { return hp; }
	inline void SetHP(float _hp);
	inline float GetMaxHp()const { return hp; }
	inline void SetMaxHp(float _maxHP) { hp = _maxHP; }
};

