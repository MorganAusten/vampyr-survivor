#pragma once
#include "Building.h"

#define PATH_BARRIER "Barriere.png"

class Barrier : public Building
{

	virtual string GetPath() { return PATH_BARRIER; }
public:
	/*const string& _name, const ShapeData& _data, const CollisionType& _collisionType, const BuildingData& _bData,
		const int _maxHp, const float _damage = 0*/
	Barrier(const Vector2f& _pos);

};

