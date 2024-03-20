#include "Mob.h"
#include "MovementComponent.h"
#include "pathFindingComponent.h"

//Useless
Mob::Mob(const string& _name, const ShapeData& _data, const CollisionType& _collisionType) :
	Entity(_name, _data, _collisionType)
{
	components.push_back(new MovementComponent(this));
	components.push_back(new PathfindingComponent(this));
	ComputeNewPath();
}

Mob::Mob(const string& _name, const ShapeData& _data, const CollisionType& _collisionType, const float _maxHp, const float _damages) :
	Entity(_name, _data, _collisionType, _maxHp, _damages)
{
	components.push_back(new MovementComponent(this));
	components.push_back(new PathfindingComponent(this));
	ComputeNewPath();
}

void Mob::Update(const float _deltaTime)
{
	MovementComponent* _mouvementComp = GetComponent<MovementComponent>();
	vector<Tile*> _path = GetComponent<PathfindingComponent>()->GetPath();
	int _positionIndex = _mouvementComp->GetPositionIndex();
	if (_positionIndex >= _path.size() - 1)
		IsToRemove();
	_mouvementComp->Update();
}

void Mob::ComputeNewPath()
{
	cout << "[Mob::ComputeNewPath]" << endl;
	GetComponent<PathfindingComponent>()->ComputeNewPath();
	vector<Tile*> _path = GetComponent<PathfindingComponent>()->GetPath();
	GetComponent<MovementComponent>()->SetDestination(_path[0]->GetShapePosition());
	cout << " CurrentMobPosition : (" << GetShapePosition().x << "," << GetShapePosition().y << ") " << endl;
	cout << " Destination : (" << GetComponent<MovementComponent>()->GetDestination().x << "," << GetComponent<MovementComponent>()->GetDestination().y << ") " << endl;
	cout << " TilePosition : (" << _path[0]->GetShapePosition().x << "," << _path[0]->GetShapePosition().y << ") " << endl;
}
