#include "ActorManager.h"
#include "TimerManager.h"
#include "InputManager.h"

ActorManager::ActorManager()
{
	stop = false;
}


void ActorManager::Init()
{
	for (Actor* _actor : GetAllValues())
	{
		_actor->Init();
	}
}

void ActorManager::Update()
{
	const float _deltaTime = TimerManager::GetInstance().GetDeltaTime();
	int _size  = GetAllValues().size();
	cout << _size << endl;
	int _var = 0;
	for (Actor* _actor : GetAllValues())
	{
		_actor->Update(stop ? 0.0f : _deltaTime);
		++_var;
	}

	GarbageValues();
}