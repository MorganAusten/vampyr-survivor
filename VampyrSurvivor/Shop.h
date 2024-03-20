#pragma once
#include "Canvas.h"


class Shop : public Canvas
{
	//vector<Building*> _buildings;
public:

	Shop(const string& _name);

public:
	void AddBuilding(/*Building* _building*/);
	void ToggleShop();
};

