#pragma once
#include "Canvas.h"
#include "Building.h"

class Shop : public Canvas
{
	vector<Building*> buildings;
public:

	Shop(const string& _name);

public:
	void AddBuilding(Building* _building);
	void ToggleShop();
};

