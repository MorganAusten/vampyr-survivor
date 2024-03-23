#include "Spawner.h"
#include "ActorSpawner.h"
#include "SpawnerManager.h"
#include "Macro.h"
#include "Assault.h"

Spawner::Spawner(const vector<vector<Assault*>>& _allAssaults, const Vector2f& _pos,
	const string& _name, const ActorType& _type, const CollisionType& _collisionType) : Actor(_name, ShapeData(Vector2f(_pos.x + 25,_pos.y + 25), Vector2f(0,0), ""), _type, _collisionType)
{
	spawnerLevel = 0;
	spawnerAssaultIndex = 0;
	actorSpawner = new ActorSpawner(this);
	int _index = 0;
	for (vector<Assault*> _assaults : _allAssaults)
	{
		for (int i = 0; i <= _assaults.size()-1; i++)
			_assaults[i]->SetOwner(this);
		allAssaults.insert(std::pair<int, vector<Assault*>>(_index, _assaults));
		_index++;
	}
	SpawnerManager::GetInstance().Register(this);
}
