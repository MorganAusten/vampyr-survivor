#pragma once
#include "Building.h"

class Barrier : public Building
{
public:
	/*const string& _name, const ShapeData& _data, const CollisionType& _collisionType, const BuildingData& _bData,
		const int _maxHp, const float _damage = 0*/
	Barrier(const Vector2f& _pos);
};

