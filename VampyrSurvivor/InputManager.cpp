#include "InputManager.h"
#include "HUD.h"

bool InputManager::Update(RenderWindow& _window)
{

	const Vector2i& _mousePosition = Mouse::getPosition(_window);
	mousePosition = Vector2f(_mousePosition);
	worldPosition = _window.mapPixelToCoords(_mousePosition);

	Event _event;
	while (_window.pollEvent(_event))
	{
		if (_event.type == Event::Closed) _window.close();
		if (_event.type == Event::Resized)
		{
			cout << "resized" << endl;
		}
		//HUD::GetInstance().Interact(worldPosition, _event.type);
		HUD::GetInstance().Interact(worldPosition, _event);
		UpdateInputs(_event);
	}

	GarbageValues();

	return true;
}

void InputManager::UpdateInputs(const Event& _event)
{
	for (const auto& _pair : allValues)
	{
		if (_pair.second->isActive)
		{
			_pair.second->Update(_event);
		}
	}
}