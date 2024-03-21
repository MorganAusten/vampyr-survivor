#pragma once
#include "Entity.h"

struct BuildingData
{
	int level;
	int cost;
	int upgradeCost;
	int maxLevel;
	int wavesToUnlock;

public:
	BuildingData() = default;
	BuildingData(int _level, int _cost, int _upgradeCost, int _maxLevel)
	{
		level = _level;
		cost = _cost;
		upgradeCost = _upgradeCost;
		maxLevel = _maxLevel;
	
	}
};

class Building : public Entity
{
	BuildingData* data;

public:
	Building();
	Building(const string& _name, const ShapeData& _data, const CollisionType& _collisionType,const BuildingData& _bData,
	const int _maxHp,const float _damage = 0);
	~Building();

public:
	void Upgrade();
};

