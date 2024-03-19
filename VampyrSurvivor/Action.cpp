#include "Action.h"
#include "InputManager.h"

InputData::InputData(ActionType _type, int _key)
{
	type = _type;
	key = _key;
}

InputData::InputData(ActionType _type, GameControllerButtons _buttons, function<void()> _callback)
{
	type = _type;
	buttons = _buttons;
	callback = callback;
}

InputData::InputData(ActionType _type, GameControllerAxes _axes)
{
	type = _type;
	axes = _axes;
}

void Action::Register()
{
	if (ActionMap* _actionMap = InputManager::GetInstance().Get(actionMap))
	{
		_actionMap->Add(id, this);
		return;
	}

	ActionMap* _newMap = new ActionMap(actionMap);
	_newMap->Add(id, this);
}


void Action::Execute()
{
	if (data.callback)
	{
		data.callback();
	}
}

