#pragma once
#include "ShapeObject.h"
#include "AlstarAlgo.h"
#include "Map.h"

class PathfindingComponent : public Component
{
    ShapeObject* owner = nullptr;
    ShapeObject* target = nullptr;
    AlstarAlgo* astar = new AlstarAlgo();
    Map* map = nullptr;
    int EndIndex = 0;
    float timer = 0;
    Tile* start = nullptr;
    Tile* destination = nullptr;
    vector<Tile*> path;

public:
    PathfindingComponent(Actor* _owner);
    void ComputeNewPath();
    inline vector<Tile*> GetPath()const { return path; }
private:
    Tile* FindClosestTile(ShapeObject* _object);
    void DrawPath();
};

