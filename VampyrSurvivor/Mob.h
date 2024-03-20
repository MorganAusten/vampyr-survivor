#pragma once
#include "Entity.h"

struct FMobSettings
{
	int dropCount ;
};

class PathfindingComponent;
class MovementComponent;

class Mob : public Entity
{
	//FSM
	//AttackComponent
public:
	FMobSettings settings;
public:
	Mob() = default;
	Mob(const string& _name, const ShapeData& _data, const CollisionType& _collisionType = CT_NONE);
	Mob(const string& _name, const ShapeData& _data, const CollisionType& _collisionType ,const float _maxHp, const float _damages);
	virtual void Update(const float _deltaTime) override;
	void ComputeNewPath();
};

