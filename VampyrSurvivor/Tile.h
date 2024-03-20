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

	string GetPathWithType(const TileType& _type)
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

		int _rand = Random<int>((int)(_names.size())-1,1);

		return _names[_rand];
	}


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

