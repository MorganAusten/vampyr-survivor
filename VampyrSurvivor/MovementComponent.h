#pragma once
#include<SFML/Graphics.hpp>
#include"Component.h"
#include"ActorManager.h"
#include"Macro.h"
#include"CollisionComponent.h"
#include"Tile.h"

using namespace sf;

class MovementComponent :public Component
{
    int positionIndex;
    int speed;
    float lerpTimer;
    bool canMove;
    Vector2i direction;
    Vector2f destination;
    CollisionComponent* collision;
public:
    inline void IncreasePositionIndex() { positionIndex++; }
    inline void ResetPositionIndex() { positionIndex = 0 ; }
    inline int GetPositionIndex()const { return positionIndex; }
    inline bool GetCanMove(){ return canMove;}
    inline int GetSpeed() const {return speed;}
    inline void SetCanMove(const bool _status){canMove = _status; }
    inline void SetDestination(const Vector2f& _destination)
    { 
        destination = Vector2f(_destination.x + TILE_SIZE.x/2, _destination.x + TILE_SIZE.y / 2);
        UpdateDirection();
    }
    inline Vector2i GetDirection()const { return direction;}
    inline Vector2f GetDestination()const { return destination;}
    void Update();
public:
    MovementComponent(Actor* _owner, const int _speed = 1 , const bool _shouldResetDirection = true);
private:
    void Move();
    inline void UpdateDirection() {
        Vector2f _direction = (destination - owner->GetShapePosition());
        direction = (Vector2i)Normalize(_direction);
    }
    void ActualizeNextTile(Tile* _nextTile);
    void TryToMove();
};
