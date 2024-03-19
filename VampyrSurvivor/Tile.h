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
	bool navigable = true;
};

class Tile : public Actor
{
	TileType type;
	sf::Vector2f position;
public:
	FPathFinding pathfindingParam;
public:
	Tile(const TileType& _type, const Vector2f& _pos,bool _navigable = true);
	std::string ToString(Object* _object) override;
public:
	inline void AddSuccessor(int _successor) { pathfindingParam.successors.push_back(_successor); }
	void ResetTileCost();

	Tile operator=(const Tile& _other)
	{
		Tile _new = _other;
		_new.type = type;
		_new.pathfindingParam.successors = pathfindingParam.successors;
		_new.pathfindingParam.g = pathfindingParam.g;
		_new.pathfindingParam.h = pathfindingParam.h;
		_new.pathfindingParam.parent = pathfindingParam.parent;
		_new.pathfindingParam.navigable = pathfindingParam.navigable;
		_new.position = position;
		_new.pathfindingParam.map = pathfindingParam.map;
		return _new;
	}
};

