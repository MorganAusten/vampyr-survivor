#include "Tile.h"
#include "Macro.h"
#include "Game.h"

Tile::Tile(const TileType& _type, const Vector2f& _pos,bool _navigable) : Actor(STRING_ID("Tile"),ShapeData(_pos, Vector2f(TILE_SIZE)))
{
	type = _type;
	pathfindingParam.navigable = _navigable;
	pathfindingParam.map = Game::GetMap();

	shape->setOutlineColor(Color::Black);
	shape->setOutlineThickness(-1.f);
	shape->setOrigin(Vector2f(0.f, 0.f));
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
