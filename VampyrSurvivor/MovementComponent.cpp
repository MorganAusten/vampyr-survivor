#include "MovementComponent.h"
#include"TimerManager.h"

MovementComponent::MovementComponent(Actor* _owner, const int _speed, const bool _shouldResetDirection) :Component(_owner)
{
    canMove = true;
    direction = new Vector2i(0, 0);
    collision = nullptr;
    speed = _speed;
}

void MovementComponent::Move()
{
    if (!canMove) return;
    Shape* _shape = owner->GetShape();
    const Vector2f& _tileSize = (Vector2f)TILE_SIZE;
    const float _directionX = (direction->x * speed * _tileSize.x);
    const float _directionY = (direction->y * speed * _tileSize.y);
    const Vector2f& _position = owner->GetShapePosition() + Vector2f(_directionX, _directionY);
    _shape->setPosition(_position);
    if (direction)
    {
        delete direction;
    }
    direction = new Vector2i(0, 0);
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