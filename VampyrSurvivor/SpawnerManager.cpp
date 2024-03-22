#include "SpawnerManager.h"
#include "Spawner.h"

SpawnerManager::SpawnerManager(const float& _beetwenWaveTimer) : IManager()
{
	wavesLevel = 0;
	betweenWaveTimer = _beetwenWaveTimer;
}

void SpawnerManager::StartWave()
{
	for (std::pair<string, Spawner*> _spawner : allValues)
		_spawner.second->StartAssault();
}

void SpawnerManager::EndWave()
{

}
