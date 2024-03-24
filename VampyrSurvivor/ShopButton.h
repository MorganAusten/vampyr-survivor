#pragma once
#include "Button.h"

class ShopButton : public Button
{
	string id;
	int buildingPrice;

public:
	ShopButton(const ShapeData& _data, const ButtonData& _bData,const string& _id ,const int _buildingPrice);

public:
	string GetId() const { return id; }
	int GetBuildingPrice() const { return buildingPrice; }
};

