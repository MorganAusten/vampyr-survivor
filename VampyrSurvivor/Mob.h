#pragma once
#include "Entity.h"

struct FMobSettings
{
	int dropCount ;
	Tile* currentTile;
	bool attackMode;

	FMobSettings()
	{
		dropCount = 2;
		currentTile = nullptr;
		attackMode = false;
	}
};

class PathfindingComponent;
class MovementComponent;

class Mob : public Entity
{
	//FSM
	//AttackComponent
	Timer* attackTimer;
	FMobSettings settings;
public:
	Mob() = default;
	Mob(const string& _name, const ShapeData& _data, const CollisionType& _collisionType ,const float _maxHp,float _speed, const float _damages, const ActorType& _type = ActorType::MOB);
public:
	FMobSettings& GetSettings() { return settings; }
	virtual void Update(const float _deltaTime) override;
	void AttackBuilding();
	void TakeDamages(const float& _damages) override;
	void ComputeNewPath();
	void PassedThePortal();
private:
	void InitAnims();
	void Dies();
};

