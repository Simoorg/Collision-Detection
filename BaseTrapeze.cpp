#include "BaseTrapeze.h"


BaseTrapeze::BaseTrapeze()
{
}

BaseTrapeze::BaseTrapeze(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	points.push_back(x1);
	points.push_back(y1);
	points.push_back(x2);
	points.push_back(y2);
	points.push_back(x3);
	points.push_back(y3);
	points.push_back(x4);
	points.push_back(y4);	
	isCircle = false;

}

BaseTrapeze::~BaseTrapeze()
{
}
