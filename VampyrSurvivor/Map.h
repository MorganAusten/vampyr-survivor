#pragma once
#include "Tile.h"
#include <iostream>
#include <fstream>

using namespace std;

class Map
{
	int size = 0;
	bool sizeSet = false;
	vector<Tile*> grid;
	//Portal portal;
public:
	Map();
private:
	void InitMap();
	void GenerateMap(std::ifstream& _in, std::string& _line, std::map<char, std::function<void(const sf::Vector2f& _position)>>& _map, sf::Vector2i& _startPos);
	void SetSuccessor();
public:
	inline vector<Tile*> GetGrid()const { return grid; }
	void ResetGridCost();
};

