#include "Mob.h"
#include "MovementComponent.h"
#include "pathFindingComponent.h"
#include "ProgressBar.h"


Mob::Mob(const string& _name, const ShapeData& _data, const CollisionType& _collisionType, const float _maxHp, float _speed, const float _damages) :
	Entity(_name, _data, _collisionType, _maxHp, _damages)
{
	components.push_back(new MovementComponent(this,_speed));
	components.push_back(new PathfindingComponent(this));
	ComputeNewPath();
}

void Mob::Update(const float _deltaTime)
{
	vector<Tile*> _path = GetComponent<PathfindingComponent>()->GetPath();
	int _positionIndex = GetComponent<MovementComponent>()->GetPositionIndex();
	if (_positionIndex >= _path.size() - 1)
		IsToRemove();
	GetComponent<MovementComponent>()->Update();
	lifeBar->SetShapePosition(GetShapePosition() +  Vector2f(0,-20));
}

void Mob::ComputeNewPath()
{
	GetComponent<PathfindingComponent>()->ComputeNewPath();
	vector<Tile*> _path = GetComponent<PathfindingComponent>()->GetPath();
	GetComponent<MovementComponent>()->SetOrigin();
	GetComponent<MovementComponent>()->SetDestination(_path[0]->GetShapePosition());
	/*cout << " CurrentMobPosition : (" << GetShapePosition().x << "," << GetShapePosition().y << ") " << endl;
	cout << " Destination : (" << GetComponent<MovementComponent>()->GetDestination().x << "," << GetComponent<MovementComponent>()->GetDestination().y << ") " << endl;
	cout << " TilePosition : (" << _path[0]->GetShapePosition().x << "," << _path[0]->GetShapePosition().y << ") " << endl;*/
}

void Mob::PassedThePortal()
{
	SetToRemove(true);
	lifeBar->SetVisible(false);
}
