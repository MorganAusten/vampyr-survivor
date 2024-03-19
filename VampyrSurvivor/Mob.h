#pragma once
#include "Entity.h"

struct FMobSettings
{
	int dammages = 0;
	int dropCount = 0;
	int moveSpeed = 0;
};

class Mob : public Entity
{
	//FSM
	//PathfindingComponent
	//MovementComponent
	//AttackComponent
public:
	FMobSettings settings;
};

