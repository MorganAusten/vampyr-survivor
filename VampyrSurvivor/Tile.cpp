#include "Tile.h"
#include "Macro.h"
#include "SpriteUtils.h"
#include "Spawner.h"
#include "Assault.h"
#include "Game.h"

string Tile::GetPathWithType(const TileType& _type)
{
	vector<string> _names =
	{
		"Floor.png",
		"Floor1.png",
		"Tree.png",
		"Tree1.png"
	};

	if (_type == TT_PATH)
	{
		int _random = RandomInt(1);
		return _names[_random];
	}
	else if (_type == TT_SPAWNER)
	{
		return 	"Spawner.png";
	}
	else if (_type == TT_PORTAL)
	{
		return 	"portalRings1.png";
	}

	

	int _size = (int)_names.size()-1;
	int _random = RandomInt(_size, 2);
	return _names[_random];
}

Tile::Tile(const TileType& _type, const Vector2f& _pos, Building* _building, bool _hasSpawner, bool _navigable) : Actor(STRING_ID("Tile"), ShapeData(_pos, Vector2f(TILE_SIZE), GetPathWithType(_type)),FIELD)
{
	type = _type;
	hasSpawner = _hasSpawner;
	building = _building;
	if (building)
	{
		building->SetCurrentTile(this);
		if (building->GetData()->isAttackable)
			pathfindingParam.hasObstacle = true;
	}
	pathfindingParam.navigable = _navigable;
	pathfindingParam.map = Game::GetMap();
	shape->setOrigin(Vector2f(0.f, 0.f));
	if (hasSpawner)
	{
		spawner = new Spawner(
			{ 
				{ALL_ASSAULT,ALL_ASSAULT,ALL_ASSAULT} ,
			{ALL_ASSAULT,ALL_ASSAULT,ALL_ASSAULT,ALL_ASSAULT},
			{ALL_ASSAULT,ALL_ASSAULT,ALL_ASSAULT,ALL_ASSAULT} 
			}, _pos);
	}
	if (type == TT_PORTAL)
	{
		InitPortalAnims();
	}
}

void Tile::InitPortalAnims()
{
	string _str = STRING_ID("Portal");
	string _str1 = STRING_ID("Portal1");
	string _str2 = STRING_ID("Portal2");
	string _str3 = STRING_ID("Portal3");
	string _str4 = STRING_ID("Portal4");
	InitAnimations({ AnimationData(_str, Vector2f(0, 0), Vector2f(32, 32), ReadDirection::READ_RIGHT, false, 4, 0.1f,_str1),
		AnimationData(_str1, Vector2f(0, 32), Vector2f(32, 32), ReadDirection::READ_RIGHT, false, 4, 0.1f,_str2),
		AnimationData(_str2, Vector2f(0, 64), Vector2f(32, 32), ReadDirection::READ_RIGHT, false, 4, 0.1f,_str3),
		AnimationData(_str3, Vector2f(0, 96), Vector2f(32, 32), ReadDirection::READ_RIGHT, false, 4, 0.1f,_str4),
		AnimationData(_str4, Vector2f(0, 128), Vector2f(32, 32), ReadDirection::READ_RIGHT, false, 1, 0.1f,_str)
		});
}

std::string Tile::ToString(Object* _object)
{
	Tile* _tile = (Tile*)_object;
	if (!_tile)
	{
		cerr << "[Tile::ToString] = >No Tile" << endl;
		return std::string();
	}
	return typeid(_tile).name();
}

void Tile::ResetTileCost()
{
	pathfindingParam.h = MAX_VALUE;
	pathfindingParam.g = MAX_VALUE;
	pathfindingParam.parent = nullptr;
}
