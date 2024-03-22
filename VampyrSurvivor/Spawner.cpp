#include "Spawner.h"
#include "ActorSpawner.h"
#include "Assault.h"

Spawner::Spawner(const vector<vector<Assault*>>& _allAssaults)
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
}
