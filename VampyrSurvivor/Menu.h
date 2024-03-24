#pragma once
#include "IManagable.h"
#include "Canvas.h"
#include "ShapeWidget.h"
#include "Button.h"
#include "Label.h"
#include "SoundData.h"

#define PATH_BACKGROUND "UIs/Menus/Background.png"
#define PATH_TITLE_ICON "UIs/Menus/TitleBarMenu.png"
#define PATH_POINTER "UIs/Menus/Pointer.png"
#define FONT "Font.ttf"

class Game;

class Menu : public IManagable<string>
{
	bool isInit;
	SoundData* sound;
protected:
	Canvas* canvas;
	Button* playButton;
	Button* exitButton;
	Game* game;
public:
	virtual void SetStatus(const bool _status, const bool _applyToWidgets = true)
	{
		if (!isInit)
		{
			Init();
			isInit = true;
		}

		canvas->SetVisibilityStatus(_status, _applyToWidgets);
	}
	bool IsActive() const
	{
		return isInit && canvas->GetVisibilityStatus();
	}

public:
	Menu(const string& _name,Game* _game);

private:
	virtual void Register() override;
	void StartGame();
protected:
	void MovePointers(Button* _button);
	void MovePointers(const Vector2f& _position, const Vector2f& _size);

public:
	virtual void Init();
};

