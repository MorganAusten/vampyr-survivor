#include "Tile.h"
#include "Macro.h"

Tile::Tile(const TileType& _type, const Vector2f& _pos) : Actor(STRING_ID("Tile"),ShapeData(_pos, Vector2f(TILE_SIZE),GetPathWithType(_type)))
{
	type = _type;
	shape->setOrigin(Vector2f(0.f, 0.f));
	shape->setOutlineThickness(-2.f);
	shape->setOutlineColor(Color::White);
}

void Tile::ResetTileCost()
{
	pathfindingParam.h = MAX_VALUE;
	pathfindingParam.g = MAX_VALUE;
	pathfindingParam.parent = nullptr;
}
