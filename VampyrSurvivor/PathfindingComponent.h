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

public:
    PathfindingComponent(ShapeObject* _owner);

    void ComputeNewPath();


    //private void Update()
    //{
    //    timer += Time.deltaTime;
    //    if (timer > 0.3)
    //    {
    //        Debug.Log("done");
    //        ComputeNewPath();
    //        timer = 0;
    //    }
    //}

    //Tile* FindClosestNode(ShapeObject* _object)
    //{
    //    if (data.Nodes.Count == 0) return null;

    //    float _distance = float.MaxValue;
    //    Node _closest = null;
    //    for (int i = 0; i < data ? .Nodes.Count; i++)
    //    {
    //        float _newDistance = Vector3.Distance(_object.GetShapePosition(), data.Nodes[i].Position);
    //        if (_newDistance < _distance)
    //        {
    //            _distance = _newDistance;
    //            _closest = data.Nodes[i];
    //        }
    //    }
    //    return _closest;
    //}
public:
    // Il faut trouver le point le plus proche du game object, puis le donner comme End.
    void Start();
};

