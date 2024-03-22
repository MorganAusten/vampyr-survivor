#include "ActorSpawner.h"
#include "SpriteUtils.h"
#include "Actor.h"
#include "Mob.h"

ActorSpawner::ActorSpawner(Actor* _owner)
{
	owner = _owner;
}

void ActorSpawner::SpawnActor(const MobID& _mob, const Vector2f& _pos)
{
	cout << "[ActorSpawner::SpawnActor] => here" << endl;
	/*switch (_mob)
	{
		case M_WOLF:
		{
			MOB_WOLF(_pos, 100);
			break;
		}
		default:
			break;
	}*/
}

void ActorSpawner::SpawnActor(const BuildingID& _building,const Vector2f& _pos)
{
	//switch (_building)
	//{
	//case B_BARRIER:
	//{
	//	//MOB_WOLF(GetShapePosition(), 100);
	//	break;
	//}
	//default:
	//	break;
	//}
}
