#pragma once
#include "Actor.h"
#include <map>
#include "Assault.h"
#include "Macro.h"

class Mob;
class ActorSpawner;

class Spawner : public Actor
{
	int spawnerLevel;
	int spawnerAssaultIndex;
	ActorSpawner* actorSpawner;
	map <int, vector<Assault*>> allAssaults;
public:
	Spawner(const vector<vector<Assault*>>& _assaults , const Vector2f& _pos,
		const string& _name = STRING_ID("Spawner"), const ActorType& _type = ActorType::SPAWNER, const CollisionType& _collisionType = CT_NONE);
public:
	inline ActorSpawner* GetActorSpawner()const { return actorSpawner; }
	inline void StartAssault() { allAssaults[spawnerAssaultIndex][0]->Start(); }
};

