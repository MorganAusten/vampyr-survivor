#include "Building.h"
#include "ActorManager.h"
#include "ProgressBar.h"
#include "Tile.h"


Building::Building() : Entity()
{
	data = nullptr;
}

Building::Building(const string& _name, const ShapeData& _data, const CollisionType& _collisionType, const BuildingData& _bData,
	const float _maxHp, const float _damage) : Entity(_name, _data, _collisionType,_maxHp,_damage)
{
	data = new BuildingData(_bData);
	data->isAttackable = true;
}

void Building::TakeDamages(const float& _damages)
{
	lifeBar->ChangeValue(_damages);
	if (lifeBar->GetCurrentValue() <= 0)
		Destroyed();
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

void Building::Destroyed()
{
	currentTile->SetBuilding(nullptr);
	SetToRemove(true);
}
