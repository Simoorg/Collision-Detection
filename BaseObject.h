#pragma once
#include "BaseShape.h"
#include "BaseCircle.h"
#include "BaseRect.h"
#include "BaseTrapeze.h"
#include "BaseTriangle.h"
#include <vector>
#include <string>

using namespace std;
class BaseObject
{
private:
	vector<BaseShape*> shapes;
public:
	enum TYPE { DEF_RECT, DEF_TRIANGLE, DEF_CIRCLE, DEF_TRAPEZE };

	BaseObject();
	~BaseObject();
	void addShape(TYPE type, double arg1, double arg2, double arg3, double arg4 = 0, double arg5 = 0, double arg6 = 0, double arg7 = 0, double arg8 = 0);
	void shift(double deltaX, double deltaY);
	void rotate(double radians);
	bool areColliding(BaseObject & other);
	std::vector<BaseShape*> getShapes();
	string toString();
};

