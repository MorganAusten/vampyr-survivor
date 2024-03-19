#include "AlstarAlgo.h"
#include "Tile.h"
#include "Map.h"

void AlstarAlgo::ComputePath(Tile* _start, Tile* _end)
{
    _start->ResetTileCost();
    vector<Tile*> _openList = vector<Tile*>(), _closedList = vector<Tile*>();
    _start->pathfindingParam.g = 0;
    _start->pathfindingParam.h = 0;
    _openList.push_back(_start);
    // il faut bien vider les listes, sinon c'est le freeze
    while (_openList.size() > 0)
    {
        Tile* _current = _openList[0];
        EraseElement(_openList, _current);
        _closedList.push_back(_current);
        if (_current == _end)
        {
            //correctPath = GetFinalPath(_start, _end);
            //TODO return final path
            return;
        }
        //Parmis les points liés a current, on checks ceux qu'on peut mettre dans l'open liste
        for (int i = 0; i < _current->pathfindingParam.successors.size(); i++)
        {
            Tile* _next = _current->pathfindingParam.map->GetGrid()[_current->pathfindingParam.successors[i]];
            for (Tile* _tile : _closedList)
                
            if (Contains(_next,_closedList))
                continue;
            //On calcul le coût:
            float _hCost = Distance(_current->GetShapePosition(), _next->GetShapePosition());
            float _gCost = _current->pathfindingParam.g + _hCost;
            if (_gCost < _next->pathfindingParam.g)
            {
                _next->pathfindingParam.g= _gCost;
                _next->pathfindingParam.h = _hCost;
                _next->pathfindingParam.parent = _current;
                _openList.push_back(_next);
            }
        }
    }
}
