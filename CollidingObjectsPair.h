#pragma once

#include "BaseObject.h"

class CollidingObjectsPair {
private:
	BaseObject* object1;
	BaseObject* object2;
public:
	CollidingObjectsPair(BaseObject* obj1, BaseObject* obj2);
};