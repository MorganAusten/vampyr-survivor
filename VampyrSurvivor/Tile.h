#pragma once
#include "Actor.h"
#include "Macro.h"

enum TileType
{
	TT_NONE,TT_GRASS,TT_PATH
};

struct FPathFinding
{
	class Map* map;
	vector<int> successors;
	float g = MAX_VALUE;
	float h = MAX_VALUE;
	class Tile* parent;
};

class Tile : public Actor
{
	TileType type;
	sf::Vector2f position;
public:
	FPathFinding pathfindingParam;
public:
	Tile(const TileType& _type,const Vector2f& _pos);
public:
	inline void AddSuccessor(int _successor) { pathfindingParam.successors.push_back(_successor); }
	void ResetTileCost();
};

