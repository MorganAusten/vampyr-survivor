#include "Canvas.h"
#include "HUD.h"

//Rajouter un delete pour un objet précis

Canvas::Canvas(const string& _name, const FloatRect& _rect) : IManagable(_name)
{
	Register();

	isVisible = true;
	rect = _rect;
	//ShapeWidget* _w = new ShapeWidget(ShapeData(Vector2f(0, 0), Vector2f(1000, 1000)));
	//_w->SetVisible(true);
	//_w->GetDrawable()->setFillColor(Color::Red);
	//uiWidgets.push_back(_w);
}

Canvas::~Canvas()
{
	for (Widget* _widget : uiWidgets)
	{
		delete _widget;
	}

	for (Widget* _widget : worldWidgets)
	{
		delete _widget;
	}
}


void Canvas::Register()
{
	HUD::GetInstance().Add(id, this);
}

void Canvas::AddWidget(Widget* _widget)
{
	if (Button* _button = dynamic_cast<Button*>(_widget))
	{
		HUD::GetInstance().AddButton(_button);
	}

	vector<Widget*>* _widgets[] = {
		&uiWidgets,
		&worldWidgets
	};

	_widgets[_widget->GetType()]->push_back(_widget);
}

