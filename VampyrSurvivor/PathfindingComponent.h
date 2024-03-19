#pragma once
#include "ShapeObject.h"
#include "AlstarAlgo.h"
#include "Map.h"

class PathfindingComponent
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
    PathfindingComponent();
    PathfindingComponent(ShapeObject* _owner);
    void ComputeNewPath();
private:
    Tile* FindClosestNode(ShapeObject* _object);
    void DrawPath();
};

