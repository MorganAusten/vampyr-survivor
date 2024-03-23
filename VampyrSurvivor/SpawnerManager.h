#pragma once
#include "Singleton.h"
#include "Spawner.h"
#include "IManager.h"

class SpawnerManager :public Singleton<SpawnerManager> , IManager<string,Spawner>
{
	vector<Spawner*> spawners;
	Timer* betweenWaveTimer;
	Timer* betweenWaveUpdateTimer;
	int wavesLevel;
	int betweenWaveCurrentTime;
	int betweenWaveDuration;
public:
	SpawnerManager();
public:
	inline int SetBetweenWaveTime()const { return betweenWaveCurrentTime; }
	inline int GetWavesLevel()const { return wavesLevel; }
	inline void Register(Spawner* _spawner) { spawners.push_back(_spawner); }
	inline void StartBeetwenWaveTimer() { /*cout << "[SpawnerManager::StartBeetwenWaveTimer] => start timer" << endl;*/ betweenWaveTimer->Start(); }
	void EndWave();
private:
	void UpdateTimer();
	void StartWave();
	void StartAssaults(const int& _activeSpawners);
};

