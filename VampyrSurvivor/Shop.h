#pragma once
#include "Canvas.h"
#include "Building.h"

class Shop : public Canvas
{
	vector<string> buildingsId;
	int maxBuildings;
public:

	Shop(const string& _name);


public:

	bool isOpen() const
	{
		return isVisible;
	}

	string GetPathWithId(const string& _id) const
	{
		map<string, string> _weaponPaths =
		{
			{"Barier","Barriere.png"},
		};

		if (_weaponPaths.find(_id) == _weaponPaths.end())
		{
			return "idk.png";
		}

		return _weaponPaths[_id];
	}

private:
	void InitShop();

public:
	void AddBuilding(const string& _buildingId);
	void ToggleShop();
};

