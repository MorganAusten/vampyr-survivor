#include "Tile.h"
#include "Macro.h"

Tile::Tile(const TileType& _type, const Vector2f& _pos) : Actor(STRING_ID("Tile"), const ShapeData(_pos, Vector2f(TILE_SIZE)))
{
	type = _type;

	Color _color = type == TT_GRASS ? Color::Green : Color::Red;

	shape->setFillColor(_color);
}
