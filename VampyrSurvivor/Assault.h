#pragma once
#include <iostream>
#include <map>
#include "ActorSpawner.h"
#include <vector>

using namespace std;

class Mob;
class Spawner;
class Timer;
class Player;

enum SpawnType
{
	S_MOB,
	S_BUILDING
};

class Assault
{
	int mobIndex;
	int spawnIndex;
	float timeBetweenSpawns;
	Spawner* spawnerOwner;
	Player* playerOwner;
	Timer* spawningTimer;
	vector<MobID> mobs;
	vector<BuildingID> buildings;
	vector<int> numbersOfActor;
	SpawnType type;

public:
	Assault() = default;
	/// <summary>
	/// 
	/// </summary>
	/// <param name="_mobs"></param>
	/// Nombres
	/// <param name="_number"></param>
	/// <param name="_timeBetweenSpawns"></param>
	Assault(const vector<MobID>& _mobs, const vector<int>& _number, const float& _timeBetweenSpawns = 2.f);
	Assault(const vector<BuildingID>& _building, const vector<int>& _number, const float& _timeBetweenSpawns = 2.f);
public:
	inline void SetOwner(Spawner* _owner) { spawnerOwner = _owner; }
	inline void SetOwner(Player* _owner) { playerOwner = _owner; }
	inline void Start() { spawningTimer->Start(); }
	void Spawn();
};

