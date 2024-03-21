#pragma once
#include "ShapeWidget.h"
#include "Canvas.h"

enum ProgressType
{
    PT_CENTER,
    PT_LEFT,
    PT_TOP,
    PT_RIGHT,
    PT_BOTTOM,

    PT_COUNT
};

class ProgressBar : public ShapeWidget
{
    ProgressType type;
    ShapeWidget* foreground;
    float currentValue;
    float maxValue;
    Vector2f size;

public:
    inline virtual void SetShapePosition(const Vector2f& _position) override
    {
        ShapeWidget::SetShapePosition(_position);
        foreground->SetShapePosition(_position - Vector2f(GetDrawable()->getGlobalBounds().getSize().x / 2.0f, 0.0f));
    }
    inline void SetType(const ProgressType& _type)
    {
        type = _type;
        UpdateOriginAndPosition(size);
    }
    inline  void SetValue(const float _newValue)
    {
        currentValue = _newValue > maxValue ? maxValue : _newValue < 0 ? 0 : _newValue;
        Update();
    }
    inline void ChangeValue(const float _byAmount)
    {
        const float _newValue = currentValue + _byAmount;
        currentValue = _newValue > maxValue ? maxValue : _newValue < 0 ? 0 : _newValue;
        Update();
    }
    inline void ResetValue()
    {
        currentValue = maxValue;
        Update();
    }
    inline void ChangeMaxValue(const float _factor)
    {
        maxValue += _factor;
        Update();
    }
    inline float GetCurrentValue() const
    {
        return currentValue;
    }
    inline float GetMaxValue() const
    {
        return maxValue;
    }
    inline ShapeWidget* GetForeground() const
    {
        return foreground;
    }

    inline void SetType(const WidgetType& _type)
    {
		SetWidgetType(_type);
    }
    void UpdateOriginAndPosition(const Vector2f& _size);
    void Update();
public:
    ProgressBar(const ShapeData& _data, const string& _path,
        const ProgressType& _type, const float _maxValue = 100.0f);
    ~ProgressBar();

private:
    IntRect MakeRect(const float _percent);
};
