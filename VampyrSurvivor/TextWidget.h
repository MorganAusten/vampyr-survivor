#pragma once
#include "Widget.h"
#include "TextObject.h"

class TextWidget : public Widget
{
protected:
	TextObject* textObject;

public:
	virtual TextObject* GetObject() const override
	{
		return textObject;
	}
	virtual Text* GetDrawable() const override
	{
		return textObject->GetDrawable();
	}

	void SetText(const string& _text)
	{
		textObject->SetText(_text);
	}

public:
	TextWidget(const TextData& _data, const WidgetType& _type = WT_UI);
};

