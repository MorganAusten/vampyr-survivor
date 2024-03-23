#pragma once
#include "ShapeObject.h"
#include "IManagable.h"
#include "CollisionComponent.h"
#include "AnimationComponent.h"

using namespace std;

enum ActorType
{
	NONE,
	FIELD,
	MOB,
	SPAWNER,
	GPE,
};

class Actor : public ShapeObject, public IManagable<string>
{

protected:
	ActorType type;
	vector<Component*> components;
	CollisionComponent* collision;
	AnimationComponent* animation;
public:
	template <typename T>
	T* GetComponent() const
	{
		for (Component* _currentComponent : components)
		{
			if (T* _component = dynamic_cast<T*>(_currentComponent))
			{
				return _component;
			}
		}

		return nullptr;
	}
	FloatRect GetBounds() const
	{
		return shape->getGlobalBounds();
	}
public:
	Actor() = default;
	Actor(const string& _name, const ShapeData& _data,const ActorType& _type = ActorType::NONE,const CollisionType& _collisionType = CT_NONE);
	~Actor();

protected:
	virtual void Register() override;

private:

public:
	inline ActorType& GetActorType() { return type; }
	virtual void Init();
	virtual void Update(const float _deltaTime);
	void Destroy(const float _waitingTime = 0.0f);
	void InitAnimations(const vector<AnimationData>& _animations);
};

