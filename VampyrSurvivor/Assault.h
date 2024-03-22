#pragma once
#include <iostream>
#include <map>
#include "ActorSpawner.h"
#include <vector>

using namespace std;

class Mob;
class ActorSpawner;
class Spawner;
class Timer;

enum SpawnType
{
	S_MOB,
	S_BUILDING
};

class Assault
{
	Spawner* owner;
	float timeBetweenSpawns;
	vector<MobID> mobs;
	vector<BuildingID> buildings;
	Timer* spawningTimer;
	ActorSpawner* actorSpawner;
	SpawnType type;

public:
	Assault() = default;
	Assault( Spawner* _owner,const vector<MobID>& _mobs, const vector<int>& _number, const float& _timeBetweenSpawns = 2.f);
	Assault(Spawner* _owner,const vector<BuildingID>& _building, const vector<int>& _number, const float& _timeBetweenSpawns = 2.f);
public:
	void Start();
	void Spawn();
};

