#include "PathfindingComponent.h"
#include "TimerManager.h"
#include "Game.h"
#include "Macro.h"


PathfindingComponent::PathfindingComponent()
{
    map = Game::GetMap();
}

PathfindingComponent::PathfindingComponent(ShapeObject* _owner)
{
    owner = _owner;
    map = Game::GetMap();
}

void PathfindingComponent::ComputeNewPath()
{
    start = FindClosestNode(Game::GetMap()->GetGrid()[2]);
    destination = FindClosestNode(map->GetGrid()[106]);
    path = astar->ComputePath(start, destination);
    DrawPath();
}

/// <summary>
/// Renseigne la Tile la plus proche de l'objet passé en param
/// </summary>
/// <param name="_object"></param>
/// C'est le ShapeObject dont tu veux trouver la tile la plus proche de la target
/// <returns></returns>
Tile* PathfindingComponent::FindClosestNode(ShapeObject* _object)
{
    if (map->GetGrid().size() == 0) return nullptr;

    float _distance = MAX_VALUE;
    Tile* _closest = nullptr;
    for (int i = 0; i < map->GetGrid().size(); i++)
    {
        Tile* _tile = map->GetGrid()[i];
        float _newDistance = Distance(_object->GetShapePosition(), _tile->GetShapePosition());
        if (_newDistance < _distance && _tile->pathfindingParam.navigable)
        {
            _distance = _newDistance;
            _closest = map->GetGrid()[i];
        }
    }
    return _closest;
}

void PathfindingComponent::DrawPath()
{
    for (Tile* _tile : path)
        _tile->GetShape()->setFillColor(sf::Color::Blue);
}

