#include "Assault.h"
#include "Timer.h"
#include "Spawner.h"


Assault::Assault(Spawner* _owner, const vector<MobID>& _mobs, const vector<int>& _number, const float& _timeBetweenSpawns)
{
	owner = _owner;
	actorSpawner = new ActorSpawner(owner);
	spawningTimer = new Timer([&]() {Spawn(); }, seconds(timeBetweenSpawns), false, true);
	timeBetweenSpawns = _timeBetweenSpawns;
	type = SpawnType::S_MOB;
	for (MobID _mob : _mobs)
		mobs.push_back(_mob);
}

Assault::Assault(Spawner* _owner, const vector<BuildingID>& _building, const vector<int>& _number, const float& _timeBetweenSpawns)
{
	owner = _owner;
	actorSpawner = new ActorSpawner(owner);
	spawningTimer = new Timer([&]() {Spawn(); }, seconds(timeBetweenSpawns), false, true);
	timeBetweenSpawns = _timeBetweenSpawns;
	type = SpawnType::S_BUILDING;
	for (BuildingID _building : _building)
		buildings.push_back(_building);
}

void Assault::Start()
{
	spawningTimer->Start();
}

void Assault::Spawn()
{
	/*if toute la liste est parcourue, arreter le spawning*/
	cout << "spawn" << endl;
	switch (type)
	{
		case S_MOB:
			actorSpawner->SpawnActor(MobID::M_WOLF, owner->GetShapePosition());
			break;
		case S_BUILDING:
			//actorSpawner->SpawnActor(MobID::M_WOLF, owner->GetShapePosition());
			break;
		default:
			break;

	}

}
