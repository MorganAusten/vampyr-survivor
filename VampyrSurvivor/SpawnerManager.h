#pragma once
#include "Singleton.h"
#include "Spawner.h"
#include "IManager.h"

class SpawnerManager :Singleton<SpawnerManager> , IManager<string,Spawner>
{
	int wavesLevel;
	int betweenWaveTimer;
	
public:
	SpawnerManager() = default;
	SpawnerManager(const float& _beetwenWaveTimer);
public:
	void EndWave();
private:
	void StartWave();
};

