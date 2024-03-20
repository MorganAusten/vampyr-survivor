#include "PathfindingComponent.h"
#include "TimerManager.h"
#include "Game.h"
#include "Macro.h"


PathfindingComponent::PathfindingComponent(Actor* _owner) : Component(_owner)
{
    owner = _owner;
    map = Game::GetMap();
}

void PathfindingComponent::ComputeNewPath()
{
    start = FindClosestTile(owner);
    destination = FindClosestTile(map->GetGrid()[60]);
    path = astar->ComputePath(start, destination);
    DrawPath();
}

/// <summary>
/// Renseigne la Tile la plus proche de l'objet passé en param
/// </summary>
/// <param name="_object"></param>
/// C'est le ShapeObject dont tu veux trouver la tile la plus proche de la target
/// <returns></returns>
Tile* PathfindingComponent::FindClosestTile(ShapeObject* _object)
{
    Map* _map = Game::GetMap();
    vector<Tile*> _grid = _map->GetGrid();
    int _gridSize = _grid.size();

    if (_gridSize == 0) return nullptr;

    float _distance = MAX_VALUE;
    Tile* _closest = nullptr;
    for (int i = 0; i < _gridSize; i++)
    {
        Tile* _tile = _grid[i];
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

