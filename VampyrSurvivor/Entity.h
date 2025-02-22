#pragma once
#include "Actor.h"
#include "ProgressLabel.h"
#include "Canvas.h"

class ProgressBar;
class Entity : public Actor
{
protected:
	float maxHp;
	float hp;
	float damage;
	Canvas* canvas;
	ProgressBar* lifeBar;

public:
	Entity();
	Entity(const string& _name, const ShapeData& _data, const CollisionType& _collisionType, const float _maxHp, const float _damage,const ActorType& _type = ActorType::NONE);
public:
	inline ProgressBar* GetLifeBar()const { return lifeBar; }
	inline float GetHP()const { return hp; }
	inline void SetHP(float _hp);
	inline float GetMaxHp()const { return hp; }
	inline void SetMaxHp(float _maxHP) { hp = _maxHP; }
	virtual void TakeDamages(const float& _damages);
};

