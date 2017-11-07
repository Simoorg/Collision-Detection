#include "BaseObject.h"


BaseObject::BaseObject()
{
}


BaseObject::~BaseObject()
{
}

void BaseObject::addShape(TYPE type, double arg1, double arg2, double arg3, double arg4, double arg5, double arg6, double arg7, double arg8)
{
	BaseShape *newShape;
	newShape = new BaseShape();
	switch (type)
	{
	case DEF_CIRCLE:
		newShape = new BaseCircle(arg1, arg2, arg3);
		break;
	case DEF_RECT:
		newShape = new BaseRect(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
		break;
	case DEF_TRAPEZE:
		newShape = new BaseTrapeze(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
		break;
	case DEF_TRIANGLE:
		newShape = new BaseTriangle(arg1, arg2, arg3, arg4, arg5, arg6);
		break;
	}
	shapes.push_back(newShape);
}

void BaseObject::shift(double deltaX, double deltaY)
{
	for (int i = 0; i < shapes.size(); i++) {
		shapes[i]->shift(deltaX, deltaY);
	}
}

void BaseObject::rotate(double radians)
{
	for (int i = 0; i < shapes.size(); i++) {
		shapes[i]->rotate(radians);
	}
}

bool BaseObject::areColliding(BaseObject& other) {
	vector<BaseShape*> otherShapes = other.getShapes();
	for (int i = 0; i < shapes.size(); i++) {
		for (int j = 0; j < otherShapes.size(); j++) {
			if (shapes[i]->areColliding(*(otherShapes[j])))
				return true;
		}
	}
	return false;
}

std::vector<BaseShape*> BaseObject::getShapes() {
	return shapes;
}

string BaseObject::toString() {
	string str = "Obiekt sklada sie z: ";
	for (int i = 0; i < shapes.size(); i++) {
		str += "\n     ";
		str += shapes[i]->toString();
	}
	return str;
}
