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
    int speed;
    bool canMove;
    Vector2i* direction;
    CollisionComponent* collision;
    
public:

    inline bool GetCanMove()
    {
        return canMove;
    }
    inline int GetSpeed() const
    {
        return speed;
    }
    inline void SetCanMove(const bool _status)
    {
        canMove = _status;
    }
    inline void SetDirection(const Vector2i& _direction)
    {
        if (direction)
        {
            delete direction;
        }
        direction = new Vector2i(_direction);
    }
    inline Vector2i* GetDirection()
    {
        return direction;
    }


public:
    MovementComponent(Actor* _owner, const int _speed = 1, const bool _shouldResetDirection = true);

public:
    void Move();
    void TryToMove();
    void Update();
};
