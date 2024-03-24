#include "ShopButton.h"

ShopButton::ShopButton(const ShapeData& _data, const ButtonData& _bData, const string& _id, const int _buildingPrice) : Button(_data, _bData)
{
	id = _id;
	buildingPrice = _buildingPrice;
}
