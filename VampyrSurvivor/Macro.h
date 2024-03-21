#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Actor.h"
#include "ActorManager.h"

using namespace std;
using namespace sf;


#pragma warning (disable :4244) // warning cast argument T
#pragma warning (disable :26495) // warning Always initialize

#define MAX_VALUE 3.40282346638e38f;

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define TILE_SIZE Vector2i(50, 50)

#define STRING_ID(name) name + to_string(GetUniqueID())
#define SIZE(vector) static_cast<int>(vector.size())

int GetUniqueID();
float Length(Vector2f& _vector);

Vector2f Normalize(Vector2f& _vector);
float Distance(const float _first, const float _second);
float Distance(const Vector2f& _first, const Vector2f& _second);
float Distance(const float _first, const float _second);
//void SetOriginAtMiddle(Shape* _shape);
string GetLevelFromIndex(const int _index);
vector<string> GetWords(const string& _text, const bool _withSpaces = false);

static inline float Randn()
{
	return -1 + 2 * ((float)rand()) / RAND_MAX;
}
template <typename T>
T Random(const T _max, const T _min = T(0))
{
	return int(rand() % (int)_max) + _min;
}

template <typename T>
bool IsEqual(const T& _first, const T& _second, const float _minRange = 0.001f)
{
	return abs(_second - _first) <= _minRange;
}

template <typename T>
bool Contains(T* _valueToFind, const vector<T*>& _vector)
{
	for (T* _value : _vector)
	{
		if (_value == _valueToFind) return true;
	}

	return false;
}

template<typename T>
vector<T*> Reverse(vector<T*> _vector)
{

	vector<T*> _result;
	for (size_t i = _vector.size() - 1, x = 0; x < _vector.size(); i--, x++)
		_result.push_back(_vector[i]); 
	return _result;
}

template <typename T>
int GetIndexByValue(const vector<T*>& _vector, T* _value)
{
	int _index = 0;

	for (T* _currentValue : _vector)
	{
		if (_currentValue == _value)
		{
			return _index;
		}

		_index++;
	}

	return -1;
}

template<typename Class>
vector<Class*> RetrieveAllMobsAround(const Vector2f& _position, const float _radiusAction)
{
	vector<Class*> _classes = vector<Class*>();
	CircleShape* _circle = new CircleShape(_radiusAction);
	_circle->setPosition(_position);

	const vector<Actor*> _actor = ActorManager::GetInstance().GetAllValues();

	for (Actor* _entity : _actor)
	{
		if (_circle->getGlobalBounds().intersects(_entity->GetDrawable()->getGlobalBounds()))
		{
			Class* _class = dynamic_cast<Class*>(_entity);
			_classes.push_back(_class);
		}
	}

	return _classes;
}

template <typename T>
void EraseElement(vector<T*>& _vector, const T* _element)
{
	_vector.erase(remove(_vector.begin(), _vector.end(), _element), _vector.end());
}

template <typename T>
void EraseElement(vector<T*>* _vector, const T* _element)
{
	_vector->erase(remove(_vector->begin(), _vector->end(), _element), _vector->end());
}