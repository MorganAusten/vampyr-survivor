#include "Mob.h"
#include "MovementComponent.h"
#include "pathFindingComponent.h"
#include "SpriteUtils.h"
#include "ProgressBar.h"


Mob::Mob(const string& _name, const ShapeData& _data, const CollisionType& _collisionType, const float _maxHp, float _speed, const float _damages, const ActorType& _type) :
	Entity(_name, _data, _collisionType, _maxHp, _damages, _type)
{
	components.push_back(new MovementComponent(this, _speed));
	components.push_back(new PathfindingComponent(this));
	ComputeNewPath();
	InitAnims();
}

void Mob::Update(const float _deltaTime)
{
	vector<Tile*> _path = GetComponent<PathfindingComponent>()->GetPath();
	int _positionIndex = GetComponent<MovementComponent>()->GetPositionIndex();
	if (_positionIndex >= _path.size() - 1)
		IsToRemove();
	GetComponent<MovementComponent>()->Update();
	if (lifeBar->GetCurrentValue() > 0 && !IsToRemove())
		lifeBar->SetShapePosition(GetShapePosition() + Vector2f(0, -50));
}

void Mob::TakeDamages(const float& _damages)
{
	lifeBar->ChangeValue(_damages);
	if (lifeBar->GetCurrentValue() <= 0)
		Dies();
}

void Mob::ComputeNewPath()
{
	GetComponent<PathfindingComponent>()->ComputeNewPath();
	vector<Tile*> _path = GetComponent<PathfindingComponent>()->GetPath();
	GetComponent<MovementComponent>()->SetOrigin();
	GetComponent<MovementComponent>()->SetDestination(_path[0]->GetShapePosition());
	/*cout << " CurrentMobPosition : (" << GetShapePosition().x << "," << GetShapePosition().y << ") " << endl;
	cout << " Destination : (" << GetComponent<MovementComponent>()->GetDestination().x << "," << GetComponent<MovementComponent>()->GetDestination().y << ") " << endl;
	cout << " TilePosition : (" << _path[0]->GetShapePosition().x << "," << _path[0]->GetShapePosition().y << ") " << endl;*/
}

void Mob::PassedThePortal()
{
	//WaveManager::GetInstance()->DecreaseMobCounter()
	Dies();
}

void Mob::InitAnims()
{
	AnimationData _animData = WOLF_WALK_ANIM;
	AnimationData _animData2 = WOLF_ATTACK_ANIM;
	AnimationData _animData3 = WOLF_DEATH_ANIM;
	vector<AnimationData> _anims = { _animData, _animData2, _animData3};
	InitAnimations(_anims);
}

void Mob::Dies()
{
	SetToRemove(true);
	canvas->Unregister(lifeBar);
}
