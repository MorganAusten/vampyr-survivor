#pragma once
#include "Actor.h"
#include "Macro.h"
#include "Building.h"

class Spawner;

enum TileType
{
	TT_NONE,TT_GRASS,TT_PATH,TT_SPAWNER
};

struct FPathFinding
{
	class Map* map;
	vector<int> successors;
	float g = MAX_VALUE;
	float h = MAX_VALUE;
	class Tile* parent;
	bool navigable = true;
	bool hasObstacle = false;
};

class Tile : public Actor
{
	TileType type;
	sf::Vector2f position;
	FPathFinding pathfindingParam;
	Building* building;
	Spawner* spawner;
	bool hasSpawner;

public:
	Tile(const TileType& _type, const Vector2f& _pos,Building* _building = nullptr, bool _hasSpawner = false, bool _navigable = true);
public:
	inline FPathFinding& GetPathParams() { return pathfindingParam; }
	inline void SetBuilding(Building* _building) { building = _building; }
	inline Building* GetBuilding()const {return building; }
	string GetPathWithType(const TileType& _type);
	std::string ToString(Object* _object) override;
	inline void AddSuccessor(int _successor) { pathfindingParam.successors.push_back(_successor); }
	TileType GetType()const { return type; }
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

