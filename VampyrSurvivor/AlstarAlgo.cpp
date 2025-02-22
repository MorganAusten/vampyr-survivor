#include "AlstarAlgo.h"
#include "Tile.h"
#include "Game.h"
#include "Map.h"

vector<Tile*> AlstarAlgo::ComputePath(Tile* _start, Tile* _end)
{
    Game::GetMap()->ResetGridCost();
    vector<Tile*> _openList = vector<Tile*>(), _closedList = vector<Tile*>();
    _start->GetPathParams().g = 0;
    _start->GetPathParams().h = 0;
    _openList.push_back(_start);
    // il faut bien vider les listes, sinon c'est le freeze
    while (_openList.size() > 0)
    {
        Tile* _current = _openList[0];
        EraseElement(_openList, _current);
        _closedList.push_back(_current);
        if (_current == _end)
        {
            correctPath = GetFinalPath(_start, _end);
            return correctPath;
        }
        //Parmis les points li�s a current, on checks ceux qu'on peut mettre dans l'open liste
        for (int i = 0; i < _current->GetPathParams().successors.size(); i++)
        {
            Tile* _next = Game::GetMap()->GetGrid()[_current->GetPathParams().successors[i]];
            if (Contains(_next,_closedList) || !_next->GetPathParams().navigable)
                continue;
            //On calcul le co�t:
            float _hCost = Distance(_current->GetShapePosition(), _next->GetShapePosition());
            float _gCost = _current->GetPathParams().g + _hCost;
            if (_gCost < _next->GetPathParams().g)
            {
                _next->GetPathParams().g= _gCost;
                _next->GetPathParams().h = _hCost;
                _next->GetPathParams().parent = _current;
                _openList.push_back(_next);
            }
        }
    }
    return vector<Tile*>();
}

vector<Tile*> AlstarAlgo::GetFinalPath(Tile* _start, Tile* _end)
{
    vector<Tile*> _path = vector<Tile*>();
    //for (int i = 0; i < _path.size(); i++)
    //    cout << _path[i]->ToString(_path[i]) << endl;
    Tile* _current = _end;
    _path.push_back(_end);
    while (_current != _start)
    {
        _path.push_back(_current->GetPathParams().parent);
        _current = _current->GetPathParams().parent;
    }
    vector<Tile*> _result = Reverse(_path);
    //Check pour voir si la fonction reverse marche bien
    //for (int i = 0; i < _path.size(); i++)
    //    cout << _result[i]->ToString(_result[i]) << endl;
    return _result;
}
