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
	Tile(const TileType& _type,const Vector2f& _pos);
public:
	inline void AddSuccessor(int _successor) { pathfindingParam.successors.push_back(_successor); }
	void ResetTileCost();
};

