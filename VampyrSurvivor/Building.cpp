#include "Building.h"
#include "ActorManager.h"

Building::Building() : Entity()
{
	data = nullptr;
}

Building::Building(const string& _name, const ShapeData& _data, const CollisionType& _collisionType, const BuildingData& _bData,
	const int _maxHp, const float _damage) : Entity(_name, _data, _collisionType,_maxHp,_damage)
{
	data = new BuildingData(_bData);
}

Building::~Building()
{
	if (data) delete data;
}

void Building::Upgrade()
{
	Player* _player = ActorManager::GetInstance().GetPlayer();
	if (data->upgradeCost > _player->GetStat()->money)
	{
		return;
	}

	maxHp = maxHp * data->level * 50 / 100;
	hp = maxHp;

	damage = damage * data->level * 50 / 100;

	data->upgradeCost = data->upgradeCost * 2;
}
