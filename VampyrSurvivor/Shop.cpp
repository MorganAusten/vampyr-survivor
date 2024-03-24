#include "Shop.h"
#include "ShapeWidget.h"
#include "Macro.h"
#include "Barrier.h"
#include "Tile.h"
//ShapeData(const Vector2f& _position, const Vector2f& _size,
//	const string& _path = "", const IntRect& _rect = IntRect())
//	: Data(_position, _path)
//{
//	size = _size;
//	rect = _rect;
//}

Shop::Shop(const string& _name) : Canvas(_name)
{
	buildingsId = {
		"Barier",
		"",
		"",
		"",
		"",
		"",
	};
	maxBuildings = 36;
	alreadyClick = false;
	showAvailableTiles = false;
	SetVisibilityStatus(false);
	InitShop();

}

void Shop::InitShop()
{

	const Vector2f& _windowSize = Vector2f((float)SCREEN_WIDTH, (float)SCREEN_HEIGHT);
	const Vector2f& _startPosition = Vector2f(_windowSize.x * 20.f / 100.f, _windowSize.y * 10.f / 100.f);
	const Vector2f& _size = Vector2f(_windowSize.x * 60.f / 100.f, _windowSize.y * 80.f / 100.f);


	ShapeWidget* _widget = new ShapeWidget(ShapeData(_startPosition, _size, ""));
	Shape* _shape = _widget->GetDrawable();
	_shape->setFillColor(Color(255, 255, 255, 180));
	_shape->setOutlineThickness(-2.0f);
	_shape->setOutlineColor(sf::Color::Yellow);
	AddWidget(_widget);

	const Vector2f& _shopWeaponSize = _size / 10.f;

	Vector2f _weaponPosition = _startPosition;

	int _rowWeaponCount = 0;
	int _allWeaponCount = 0;
	for (string _buildingId : buildingsId)
	{
		if (_allWeaponCount >= maxBuildings)
		{
			continue;
		}

		if (_rowWeaponCount >= 6)
		{
			_rowWeaponCount = 0;
			_weaponPosition.x = _startPosition.x;
			_weaponPosition.y += _shopWeaponSize.y + _shopWeaponSize.y / 2;
		}
		Button* _widget = new Button(ShapeData(_weaponPosition + _shopWeaponSize / 2.f, _shopWeaponSize, GetPathWithId(_buildingId)),
			ButtonData(
				[&]() { ToggleShop(); ToggleAvailableTiles(); },
				nullptr,
				nullptr
				)

		);
		_widget->GetDrawable()->setOutlineColor(Color::Blue);
		AddWidget(_widget);
		_weaponPosition.x += _shopWeaponSize.x + _shopWeaponSize.x / 2;
		_rowWeaponCount++;
		_allWeaponCount++;
	}
}

void Shop::AddBuilding(const string& _buildingId)
{
	//AddWidget(_building->GetWidget());
	buildingsId.push_back(_buildingId);
}

void Shop::ToggleAvailableTiles()
{
	showAvailableTiles = !showAvailableTiles;
	for (Actor* _actor : ActorManager::GetInstance().GetAllValues())
	{
		Tile* _tile = dynamic_cast<Tile*>(_actor);
		if (_tile)
		{
			if (showAvailableTiles)
			{
				if (!_tile->GetBuilding())
				{
					if (_tile->GetType() == TT_PATH)
					{
						_tile->GetShape()->setFillColor(Color::Green);
					}
				}
				else
				{
					_tile->GetShape()->setFillColor(Color::Red);
				}
			}

			else
			{
				_tile->GetShape()->setFillColor(Color::White);
			}
		}
	}
}

void Shop::ToggleShop()
{
	SetVisibilityStatus(!isVisible);
}
