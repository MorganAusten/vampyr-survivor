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
		"Flower1.png",
		"Flower2.png",
		"Flower3.png",
		"Flower4.png",
		"Flower5.png",
		"Flower6.png",
		"Flower7.png",
		"Flower8.png",
		"Flower9.png",
		"Flower10.png",
		"Flower11.png",
		"Flower12.png",
	};

	if (_type == TT_PATH)
	{
		return _names[0];
	}
	else if (_type == TT_SPAWNER)
	{
		return 	"Spawner.png";
	}

	int _rand = Random((int)(_names.size()) - 1, 1);

	//cout << _names[_rand] << endl;

	return _names[_rand];
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
		cout << "coucou" << endl;
		spawner = new Spawner({ {ALL_ASSAULT,ALL_ASSAULT,ALL_ASSAULT} ,
			{ALL_ASSAULT,ALL_ASSAULT,ALL_ASSAULT,ALL_ASSAULT},
			{ALL_ASSAULT,ALL_ASSAULT,ALL_ASSAULT,ALL_ASSAULT} });
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
