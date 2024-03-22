#pragma once
#include "Actor.h"
#include <map>
#include "Assault.h"

class Mob;
class ActorSpawner;

class Spawner : public Actor
{
	int spawnerLevel;
	int spawnerAssaultIndex;
	ActorSpawner* actorSpawner;
	map <int, vector<Assault*>> allAssaults;
public:
	Spawner(const vector<vector<Assault*>>& _assaults);
public:
	inline ActorSpawner* GetActorSpawner()const { return actorSpawner; }
	inline void StartAssault() { allAssaults[spawnerAssaultIndex][0]->Start(); }
};

