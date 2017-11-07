#pragma once
#include "BaseShape.h"

class BaseTriangle : public BaseShape
{
public:
	BaseTriangle();
	BaseTriangle(double x1, double y1, double x2, double y2, double x3, double y3);
	~BaseTriangle();
};

