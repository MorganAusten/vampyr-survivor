#pragma once
#include "Canvas.h"
#include "Building.h"
#include "ShopButton.h"
#include "Barrier.h"
#include <map>

struct SaleableData
{
	string id;
	int price;

	SaleableData(const string& _id, const int _price)
	{
		id = _id;
		price = _price;
	}
};

class Shop : public Canvas
{
	vector<SaleableData> buildingsId;
	vector<ShopButton*> buttons;
	ShopButton* selectedButton;
	int maxBuildings;
	bool showAvailableTiles;
public:

	Shop(const string& _name);


public:

	bool ShowAvailableTiles() const
	{
		return showAvailableTiles;
	}

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

	Building* CreateBuildingWithButtonId(const string& _id,const Vector2f& _position)
	{
		map<string, function<Building* ()>> _weaponPaths =
		{
			{"Barier", [&]() { return new Barrier(_position); }},
		};

		if (_weaponPaths.find(_id) == _weaponPaths.end())
		{
			return nullptr;
		}

		return _weaponPaths[_id]();
	}

private:
	void InitShop();

public:
	void AddBuilding(const SaleableData& _buildingData);
	void ToggleAvailableTiles();
	void Construct(const Vector2f& _position);
	void ToggleShop();
};

