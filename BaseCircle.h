#pragma once
#include "BaseShape.h"

class BaseCircle : public BaseShape
{
private:
	double radius;
public:
	BaseCircle();
	BaseCircle(double x1, double y1, double radius);
	~BaseCircle();
	Projection makeProjection(double axisX, double axisY, vector<double> toProjection);
	bool areColliding(BaseShape & other);
	double getRadius();
};

