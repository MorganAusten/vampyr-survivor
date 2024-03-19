#pragma once
#include "Actor.h"

enum TileType
{
	TT_NONE,TT_GRASS,TT_PATH
};

class Tile : public Actor
{
	TileType type;
public:
	Tile(const TileType& _type,const Vector2f& _pos);
};

