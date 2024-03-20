#include "Mob.h"
#include "MovementComponent.h"
#include "pathFindingComponent.h"

//Useless
Mob::Mob(const string& _name, const ShapeData& _data, const CollisionType& _collisionType) :
	Entity(_name, _data, _collisionType)
{
	components.push_back(new MovementComponent(this));
	components.push_back(new PathfindingComponent(this));
	GetComponent<PathfindingComponent>()->ComputeNewPath();
}

Mob::Mob(const string& _name, const ShapeData& _data, const CollisionType& _collisionType, const float _maxHp, const float _damages):
	Entity(_name,_data,_collisionType,_maxHp,_damages)
{
	components.push_back(new MovementComponent(this));
	components.push_back(new PathfindingComponent(this));
	GetComponent<PathfindingComponent>()->ComputeNewPath();
}

void Mob::Update(const float _deltaTime)
{
	//GetCompon
	//GetComponent<MovementComponent>()->SetDirection()
}