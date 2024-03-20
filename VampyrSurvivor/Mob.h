#pragma once
#include "Entity.h"

struct FMobSettings
{
	int dammages = 0;
	int dropCount = 0;
	int moveSpeed = 0;
};

class PathfindingComponent;
class MovementComponent;

class Mob : public Entity
{
	//FSM
	PathfindingComponent* pathComp;
	MovementComponent* movementComp;
	//AttackComponent
public:
	FMobSettings settings;
public:
	Mob() = default;
	Mob(const string& _name, const ShapeData& _data, const CollisionType& _collisionType = CT_NONE);
	MovementComponent* GetMovementComp()const { return movementComp; }
	PathfindingComponent* GetPathComp()const { return pathComp; }
};

