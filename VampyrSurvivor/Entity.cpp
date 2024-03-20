#include "Entity.h"
#include "ProgressBar.h"

Entity::Entity(const string& _name, const ShapeData& _data, const CollisionType& _collisionType) : Actor(_name,_data,_collisionType)
{
}

inline void Entity::SetHP(float _hp)
{
	hp -= _hp;
	lifeBar->ChangeValue(_hp);
}
