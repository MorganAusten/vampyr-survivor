#include "MovementComponent.h"
#include"TimerManager.h"
#include "Kismet.h"
#include "PathfindingComponent.h"

MovementComponent::MovementComponent(Actor* _owner, const int _speed, const bool _shouldResetDirection) :Component(_owner)
{
	positionIndex = 0;
	lerpTimer = 0;
	canMove = true;
	direction = Vector2i(0, 1);
	collision = nullptr;
	speed = _speed;
}

void MovementComponent::Move()
{
	if (!canMove) return;
	cout << "[MovementComponent::Move] => LerpTimer ="  << lerpTimer   << endl;
	Shape* _shape = owner->GetShape();
	const Vector2f& _position = VLinearInterp(destination, owner->GetShapePosition(),lerpTimer, 0.0001);
	cout << "[MovementComponent::Move] => owner->GetShapePosition = (" << owner->GetShapePosition().x << "," << owner->GetShapePosition().y << ")" << endl;
	cout << "[MovementComponent::Move] => destination = (" << destination.x << "," << destination.y << ")" << endl;
	cout << "[MovementComponent::Move] => _position = (" << _position.x << "," << _position.y << ")" << endl;
	_shape->setPosition(_position);
	//cout << "[MovementComponent::Move] => Direction = (" << _position.x << "," << _position.y << ")" << endl;
	if (lerpTimer >= 1)
	{
		lerpTimer = 0;
		cout << "[MovementComponent::Move] => position index = " << positionIndex << endl;
		positionIndex++;
		//ActualizeNextTile(owner->GetComponent<PathfindingComponent>()->GetPath()[positionIndex]);
	}
}


void MovementComponent::ActualizeNextTile(Tile* _nextTile)
{
	destination = _nextTile->GetShapePosition();
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