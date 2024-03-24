#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Canvas.h"
#include "Button.h"
#include "InputManager.h"
#include "Tile.h"
#include "Game.h"

class HUD : public Singleton<HUD>, public IManager<string, Canvas>
{
	vector<Button*> buttons;

public:
	void AddButton(Button* _button)
	{
		buttons.push_back(_button);
	}

	Button* GetButtonAtMousePos() const
	{
		for (Button* _button : buttons)
		{
			Shape* _shape = _button->GetDrawable();
			FloatRect _rect = _shape->getGlobalBounds();
			if (_rect.contains(InputManager::GetInstance().GetMousePosition()))
			{
				return _button;
			}
		}

		return nullptr;
	}

	Tile* GetTileAtPos(const Vector2f& _position) const
	{
		for (Actor* _actor : ActorManager::GetInstance().GetAllValues())
		{
			Tile* _tile = dynamic_cast<Tile*>(_actor);
			if (_tile && _tile->GetShape()->getGlobalBounds().contains(_position))
			{
				return _tile;
			}
		}
		return nullptr;
	}

public:
	void Interact(const Vector2f& _worldPosition, const Event& _event);
	Button* GetHoveredButton(const vector<Button*>& _buttons);
	Button* GetPressedButton(const vector<Button*>& _buttons);
};

