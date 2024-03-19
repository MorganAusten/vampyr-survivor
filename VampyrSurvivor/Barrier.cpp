#include "Barrier.h"
#include "Macro.h"
Barrier::Barrier(const string& _name, const int _hp, const Vector2f& _pos) : Actor(_name, ShapeData(_pos,Vector2f(TILE_SIZE),"Barriere.png"), CT_BLOCK)
{
	hp = _hp;
}
