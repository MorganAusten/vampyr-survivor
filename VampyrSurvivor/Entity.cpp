#include "Entity.h"
#include "ProgressBar.h"
#include "HUD.h"
#include "Macro.h"

Entity::Entity() : Actor()
{
	canvas = nullptr;
	hp = 0;
	maxHp = 0;
	damage = 0;
}

Entity::Entity(const string& _name, const ShapeData& _data, const CollisionType& _collisionType,
	const float _maxHp, const float _damage,const ActorType& _type) : Actor(_name,_data, _type,_collisionType)
{
	maxHp = _maxHp;
	damage = _damage;
	hp = maxHp;
	const Vector2f& _pos = Vector2f(_data.position.x, _data.position.y - _data.size.y / 2.f);
	const Vector2f& _size = Vector2f(_data.size.x /**1.5f*/, _data.size.y / 4.f);
	canvas = new Canvas(STRING_ID("Entity"), FloatRect(Vector2f(10000000, 0), Vector2f(1, 1)));
	lifeBar = new ProgressBar(ShapeData(_pos, _size, "lifebar.png"), PT_CENTER, maxHp);
	lifeBar->SetType(WT_WORLD);
	canvas->AddWidget(lifeBar);  
}

inline void Entity::SetHP(float _hp)
{
	hp -= _hp;
	lifeBar->ChangeValue(_hp);
}

void Entity::TakeDamages(const float& _damages)
{

}
