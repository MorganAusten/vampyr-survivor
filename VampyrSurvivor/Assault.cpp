#include "Assault.h"
#include "Timer.h"
#include "Spawner.h"


Assault::Assault( const vector<MobID>& _mobs, const vector<int>& _number, const float& _timeBetweenSpawns)
{
	playerOwner = nullptr;
	spawnerOwner = nullptr;
	mobIndex = 0;
	spawnIndex = 0;
	timeBetweenSpawns = _timeBetweenSpawns;
	spawningTimer = new Timer([this]() {Spawn(); }, seconds(timeBetweenSpawns), false, true);
	type = SpawnType::S_MOB;
	for (MobID _mob : _mobs)
		mobs.push_back(_mob);
	for (int _n : _number)
		numbersOfActor.push_back(_n);
}

Assault::Assault( const vector<BuildingID>& _building, const vector<int>& _number, const float& _timeBetweenSpawns)
{
	playerOwner = nullptr;
	spawnerOwner = nullptr;
	mobIndex = 0;
	spawnIndex = 0;
	spawningTimer = new Timer([this]() {Spawn(); }, seconds(timeBetweenSpawns), false, true);
	timeBetweenSpawns = _timeBetweenSpawns;
	type = SpawnType::S_BUILDING;
	for (BuildingID _building : _building)
		buildings.push_back(_building);
	for (int _n : _number)
		numbersOfActor.push_back(_n);
}

void Assault::Spawn()
{
	/*if toute la liste est parcourue, arreter le spawning*/
	switch (type)
	{
		case S_MOB:
			if (spawnIndex <= mobs.size() - 1)
			{

				spawnerOwner->GetActorSpawner()->SpawnActor(mobs[spawnIndex], spawnerOwner->GetShapePosition());
				mobIndex++;
			}
			else
			{
				spawningTimer->Stop();
				return;
			}
			break;
		case S_BUILDING:
			//actorSpawner->SpawnActor(MobID::M_WOLF, owner->GetShapePosition());
			break;
		default:
			break;
	}
	if (mobIndex >= numbersOfActor[spawnIndex] - 1)
	{
		spawnIndex++;
		mobIndex = 0;
	}
}
