#include "Shop.h"

Shop::Shop(const string& _name) : Canvas(_name)
{
	buildings = vector<Building*>();
}

void Shop::AddBuilding(Building* _building)
{
	AddWidget(_building->GetWidget());
	buildings.push_back(_building);
}

void Shop::ToggleShop()
{
	isVisible = !isVisible;
}
