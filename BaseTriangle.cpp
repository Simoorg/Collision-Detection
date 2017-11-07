
#include "BaseTriangle.h"


BaseTriangle::BaseTriangle()
{
}

BaseTriangle::BaseTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	points.push_back(x1);
	points.push_back(y1);
	points.push_back(x2);
	points.push_back(y2);
	points.push_back(x3);
	points.push_back(y3);
	isCircle = false;
}


BaseTriangle::~BaseTriangle()
{
}
