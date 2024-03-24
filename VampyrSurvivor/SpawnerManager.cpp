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
	ActorManager::GetInstance().GetPlayer()->GetStat()->SetStringWaveTimer(betweenWaveCurrentTime);
	if (betweenWaveCurrentTime == 0)
	{
		betweenWaveCurrentTime = BEETWEEN_WAVE_TIMER;
		StartWave();
		betweenWaveTimer->Pause();
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
	spawners[0]->StartAssault();
	//vector<int> _retryRandValues = vector<int>();
	//for (size_t i = 0; i < _activeSpawner; i++)
	//{
	//	int _size = (int)spawners.size()-1;
	//	int _rand = RandomInt(_size);
	//	while (Contains(_rand, _retryRandValues))
	//		_rand = RandomInt(_size);
	//	spawners[_rand]->StartAssault();
	//	_retryRandValues.push_back(_rand);
	//}
}

void SpawnerManager::EndWave()
{
	wavesLevel++;
}
