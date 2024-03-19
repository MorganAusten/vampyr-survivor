#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Actor.h"
#include "InteractableActor.h"

class Player;

class ActorManager : public Singleton<ActorManager>, public IManager<string, Actor>
{
	Player* player;
	vector<InteractableActor*> interactables;
	bool stop;
public:
	void AddInteractable(InteractableActor* _interactable)
	{
		interactables.push_back(_interactable);
	}

	vector<InteractableActor*> GetInteractables() const
	{
		return interactables;
	}

	void SetStop(const bool _stop)
	{
		stop = _stop;
	}
public:
	ActorManager();
	~ActorManager();
public:
	inline Player* GetPlayer()const { return player; }
	inline void RegisterPlayer(Player* _player) { player = _player; }
	void Init();
	void Update();
};

