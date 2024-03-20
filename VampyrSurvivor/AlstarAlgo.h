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
};

