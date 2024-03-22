#pragma once
#include "Actor.h"

class Actor;

enum MobID
{
	M_WOLF
};

enum BuildingID
{
	B_BARRIER
};

class ActorSpawner
{
	Actor* owner;
public:
	ActorSpawner(Actor* _owner);
public:
	void SpawnActor(const MobID& _mob,const Vector2f& _pos);
	void SpawnActor(const BuildingID& _building,const Vector2f& _pos);
};

