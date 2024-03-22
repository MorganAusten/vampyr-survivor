#pragma once
#include "Actor.h"


class Mob;
class Assault;

class Spawner : public Actor
{
	int spawnerLevel;
	vector<Assault*> assaults;
public:
	Spawner();
	Spawner(const vector<Assault*>& _assault);
public:
	void StartAssault();
};

