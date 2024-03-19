#pragma once
#include <iostream>
#include <fstream>
#include "Macro.h"

class Tile;

class AlstarAlgo
{
    vector<Tile*> correctPath;

public:
    void ComputePath(Tile* _start, Tile* _end);

    // pour que la liste commence par start et non par end.
    //List<Node> GetFinalPath(Node _start, Node _end)
    //{
    //    List<Node> _path = new List<Node>();
    //    Node _current = _end;
    //    _path.Add(_end);
    //    while (_current != _start)
    //    {
    //        _path.Add(_current.Parent);
    //        _current = _current.Parent;
    //    }
    //    _path.Reverse();
    //    return _path;
    //}

    //public void DrawPath()
    //{
    //    Gizmos.color = Color.magenta;
    //    for (int i = 0; i < correctPath.Count - 1; i++)
    //    {
    //        Gizmos.DrawLine(correctPath[i].Position + Vector3.up, correctPath[i + 1].Position + Vector3.up);
    //    }
    //}
};

