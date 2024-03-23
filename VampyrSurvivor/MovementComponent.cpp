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
	canMove = true;
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

	if (!canMove) return;
	Shape* _shape = owner->GetShape();
	const Vector2f& _position = VLinearInterp(destination, origin, lerpTimer, speed *0.0001);
	_shape->setPosition(_position);
	if (lerpTimer >= 1)
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
	//cout << lerpTimer << endl;
}


void MovementComponent::ActualizeNextTile(Tile* _nextTile)
{
	SetOrigin();
	SetDestination(_nextTile->GetShapePosition());
	UpdateDirection();
}

void MovementComponent::TryToMove()
{
	if (!canMove) return;
	Move();
}

void MovementComponent::Update()
{
	TryToMove();
}