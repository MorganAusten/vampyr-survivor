#pragma once
#include "Tile.h"
#include <iostream>
#include <fstream>

using namespace std;

class Map
{
	vector<Tile*> tiles;

public:
	Map();

public:
	void GenerateMap();
};

