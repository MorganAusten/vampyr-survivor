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
	FMobSettings settings;
public:
	Mob() = default;
	Mob(const string& _name, const ShapeData& _data, const CollisionType& _collisionType ,const float _maxHp,float _speed, const float _damages);
public:
	FMobSettings& GetSettings() { return settings; }
	virtual void Update(const float _deltaTime) override;
	void TakeDamages(const float& _damages);
	void ComputeNewPath();
	void PassedThePortal();
private:
	void Dies();
};

