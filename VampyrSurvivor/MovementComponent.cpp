#include "MovementComponent.h"
#include"TimerManager.h"
#include "Kismet.h"
#include "Mob.h"
#include "SpriteUtils.h"
#include "ProgressBar.h"
#include "PathfindingComponent.h"

MovementComponent::MovementComponent(Actor* _owner, const int _speed) :Component(_owner)
{
	owner = _owner;
	positionIndex = 0;
	lerpTimer = 0;
	direction = Vector2i(0, 1);
	collision = nullptr;
	speed = _speed;
}

void MovementComponent::Move()
{
#pragma region cout
	//cout << "[MovementComponent::Move] => LerpTimer ="  << lerpTimer   << endl;
	//cout << "[MovementComponent::Move] => owner->GetShapePosition = (" << owner->GetShapePosition().x << "," << owner->GetShapePosition().y << ")" << endl;
	//cout << "[MovementComponent::Move] => destination = (" << destination.x << "," << destination.y << ")" << endl;
	//cout << "[MovementComponent::Move] => _position = (" << _position.x << "," << _position.y << ")" << endl;
	//cout << "[MovementComponent::Move] => Direction = (" << _position.x << "," << _position.y << ")" << endl;
#pragma endregion cout
	Mob* _owner = (Mob*)owner;
	Shape* _shape = owner->GetShape();
	const Vector2f& _position = VLinearInterp(destination, origin, lerpTimer, speed *0.0001);
	_shape->setPosition(_position);
	if (lerpTimer >= 1 || owner->GetShapePosition() == destination)
	{
		if (positionIndex == owner->GetComponent<PathfindingComponent>()->GetPath().size() - 1)
		{
			_owner->PassedThePortal();
			return;
		}
		lerpTimer = 0;
		positionIndex++;
		ActualizeNextTile(owner->GetComponent<PathfindingComponent>()->GetPath()[positionIndex]);
	}
	bool _contains = _owner->GetSettings().currentTile->GetBounds().contains(_owner->GetShapePosition());
	bool _hasObstacle = _owner->GetSettings().currentTile->GetPathParams().hasObstacle;
	if (_contains && _hasObstacle)
	{
		_owner->GetSettings().attackMode = true;
		return;
	}
	//cout << lerpTimer << endl;
}


void MovementComponent::ActualizeNextTile(Tile* _nextTile)
{
	SetOrigin();
	SetDestination(_nextTile->GetShapePosition());
	Mob* _mob = (Mob*)owner;
	_mob->GetSettings().currentTile = _nextTile;
	UpdateDirection();
}


void MovementComponent::Update()
{
	Move();
}