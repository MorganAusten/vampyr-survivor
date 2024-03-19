#pragma once
#include <iostream>
#include <fstream>
#include "Macro.h"

class Tile;

class AlstarAlgo
{
    vector<Tile*> correctPath;

public:
    vector<Tile*> ComputePath(Tile* _start, Tile* _end);

    // pour que la liste commence par start et non par end, retourne le path le plus court en remontant de la destination au start par les parent.
    vector<Tile*> GetFinalPath(Tile* _start, Tile* _end);

    //public void DrawPath()
    //{
    //    Gizmos.color = Color.magenta;
    //    for (int i = 0; i < correctPath.Count - 1; i++)
    //    {
    //        Gizmos.DrawLine(correctPath[i].Position + Vector3.up, correctPath[i + 1].Position + Vector3.up);
    //    }
    //}
};

