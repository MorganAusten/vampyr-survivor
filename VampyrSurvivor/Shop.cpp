#include "Shop.h"
#include "ShapeWidget.h"
#include "Macro.h"
#include "Barrier.h"
#include "Tile.h"
#include "HUD.h"
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
		{"Barier",10},
	};
	maxBuildings = 36;
	showAvailableTiles = false;
	selectedButton = nullptr;
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
	for (SaleableData _buildingData : buildingsId)
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
		ShopButton* _widget = new ShopButton(ShapeData(_weaponPosition + _shopWeaponSize / 2.f, _shopWeaponSize, GetPathWithId(_buildingData.id)),
			ButtonData(
				[&]() { 
					selectedButton = (ShopButton*)HUD::GetInstance().GetButtonAtMousePos();
					cout << ActorManager::GetInstance().GetPlayer()->GetStat()->money << endl;
					cout << selectedButton->GetBuildingPrice() << endl;
					if (selectedButton->GetBuildingPrice() <= ActorManager::GetInstance().GetPlayer()->GetStat()->money)
					{
						ToggleAvailableTiles();
					}
						ToggleShop();
					 },
				nullptr,
				nullptr
				), _buildingData.id, _buildingData.price);
		_widget->GetDrawable()->setOutlineColor(Color::Blue);
		AddWidget(_widget);
		_weaponPosition.x += _shopWeaponSize.x + _shopWeaponSize.x / 2;
		_rowWeaponCount++;
		_allWeaponCount++;
	}
}

void Shop::AddBuilding(const SaleableData& _buildingData)
{
	//AddWidget(_building->GetWidget());
	buildingsId.push_back(_buildingData);
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

void Shop::Construct(const Vector2f& _position)
{
	Tile* _tile = HUD::GetInstance().GetTileAtPos(_position);
	if (_tile)
	{
		if (_tile->GetType() == TT_GRASS)
		{
			ToggleAvailableTiles();
			return;
		}
		if (!_tile->GetBuilding())
		{
			Building* _building = CreateBuildingWithButtonId(selectedButton->GetId(), _tile->GetShapePosition());
			_tile->SetBuilding(_building);
			ToggleAvailableTiles();
			Player* _player = ActorManager::GetInstance().GetPlayer();
			_player->GetStat()->money -= selectedButton->GetBuildingPrice();
			_player->GetStat()->SetStringMoney(_player->GetStat()->money);
		}
	}

}
