#include "SpawnerManager.h"
#include "Macro.h"
#include "Spawner.h"

SpawnerManager::SpawnerManager() : IManager()
{
	betweenWaveDuration = BEETWEEN_WAVE_TIMER;
	betweenWaveCurrentTime = BEETWEEN_WAVE_TIMER;
	wavesLevel = 0;
	betweenWaveTimer = new Timer([this]() {UpdateTimer(); }, seconds(1), false,true);
}

void SpawnerManager::UpdateTimer()
{
	betweenWaveCurrentTime--;
	cout << betweenWaveCurrentTime << endl;
	ActorManager::GetInstance().GetPlayer()->GetStat()->waveTimer = betweenWaveCurrentTime;
	if (betweenWaveCurrentTime == 0)
	{
		betweenWaveCurrentTime = BEETWEEN_WAVE_TIMER;
		StartWave();
		betweenWaveTimer->Stop();
	}
}

void SpawnerManager::StartWave()
{
	switch (wavesLevel)
	{
	case 0:
		StartAssaults(1);
	}
}

void SpawnerManager::StartAssaults(const int& _activeSpawner)
{
	vector<int*> _retryRandValues = vector<int*>();
	for (size_t i = 0; i < _activeSpawner; i++)
	{
		int _size = spawners.size();
		int _rand = Random(_size);
		while (Contains(&_rand, _retryRandValues))
			_rand = Random(_size);
		spawners[_rand]->StartAssault();
		_retryRandValues.push_back(&_rand);
	}
}

void SpawnerManager::EndWave()
{
	wavesLevel++;
}
