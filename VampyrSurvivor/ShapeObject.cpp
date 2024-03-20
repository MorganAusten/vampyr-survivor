#include "ShapeObject.h"
#include "TextureManager.h"
#include <iostream>

ShapeObject::ShapeObject(const ShapeData& _data)
{
	const Vector2f& _size = _data.size;
	shape = new RectangleShape(_size);
	std::cout << shape->getGlobalBounds().getSize().x << " " << shape->getGlobalBounds().getSize().y << endl;
	shape->setPosition(_data.position);

	TextureManager& _textureManager = TextureManager::GetInstance();
	_data.rect == IntRect() ? _textureManager.Load(this, _data.path)
		: _textureManager.LoadWithRect(this, _data.path, _data.rect);
}

ShapeObject::~ShapeObject()
{
	delete shape;
}