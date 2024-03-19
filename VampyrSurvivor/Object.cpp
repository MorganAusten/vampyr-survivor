#include "Object.h"

std::string Object::ToString(Object* _object)
{
	return typeid(_object).name();
}
