#include "Entity.h"
#include "ProgressBar.h"
#include "HUD.h"
#include "Macro.h"

Entity::Entity() : Actor()
{
	progressBarCanvas = nullptr;
	hp = 0;
	lifeBar = nullptr;
	maxHp = 0;
	damage = 0;
}

Entity::Entity(const string& _name, const ShapeData& _data, const CollisionType& _collisionType,
	const float _maxHp, const float _damage) : Actor(_name,_data,_collisionType)
{
	progressBarCanvas = new Canvas(STRING_ID("LifeBar"));
	
	maxHp = _maxHp;
	damage = _damage;
	hp = maxHp;
	const Vector2f& _pos = Vector2f(_data.position.x, _data.position.y - _data.size.y / 2.f);
	const Vector2f& _size = Vector2f(_data.size.x, _data.size.y / 2.f);
	lifeBar = new ProgressBar(ShapeData(_pos, _size), "Textures/heart.png", PT_CENTER, maxHp);
	lifeBar->SetType(WT_WORLD);
	progressBarCanvas->AddWidget(lifeBar);
}

Entity::Entity(const string& _name, const ShapeData& _data, const CollisionType& _collisionType)
{

}

inline void Entity::SetHP(float _hp)
{
	hp -= _hp;
	lifeBar->ChangeValue(_hp);
}
