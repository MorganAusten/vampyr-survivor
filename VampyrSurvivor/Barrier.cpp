#include "Barrier.h"
#include "Macro.h"

Barrier::Barrier(const Vector2f& _pos) : Actor(STRING_ID("Zarrier"), ShapeData(_pos, Vector2f(TILE_SIZE), "Barriere.png"), CT_BLOCK)
{
	hp = 500;
	shape->setOrigin(0.f,0.f);
}
