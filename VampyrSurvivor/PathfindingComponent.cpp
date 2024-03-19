#include "PathfindingComponent.h"

PathfindingComponent::PathfindingComponent(ShapeObject* _owner)
{
    owner = _owner;
}

void PathfindingComponent::ComputeNewPath()
{
    //start = FindClosestNode(owner);
    //destination = FindClosestNode(target);
    //astar.ComputePath(start, destination);
}

void PathfindingComponent::Start()
{
    ComputeNewPath();
}
