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
		int _random = Random(2, 0);
		return _names[_random];
	}
	else if (_type == TT_SPAWNER)
	{
		return 	"Spawner.png";
	}

	int _size = _names.size()-1;
	int _random = Random(_size-1, 2);
	return _names[_random];
}

Tile::Tile(const TileType& _type, const Vector2f& _pos, Building* _building, bool _hasSpawner, bool _navigable) : Actor(STRING_ID("Tile"), ShapeData(_pos, Vector2f(TILE_SIZE), GetPathWithType(_type)))
{
	type = _type;
	hasSpawner = _hasSpawner;
	building = _building;
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
