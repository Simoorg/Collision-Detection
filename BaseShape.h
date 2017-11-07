#pragma once

#include <vector>
#include <string>
#include "Projection.h"

using namespace std;

class BaseShape
{
protected:
	bool isCircle;
	vector <double> points;
public:
	BaseShape();
	virtual ~BaseShape();
	void rotate(double radians);
	void shift(double deltaX, double deltaY);
	virtual bool areColliding(BaseShape& other);
	vector<double> getAxes(vector<double>& toAxes);
	double dotProduct(double x1, double y1, double axisX, double axisY);
	virtual Projection makeProjection(double axisX, double axisY, vector<double> toProjection);
	vector<double> getPoints();
	bool getIsCircle();
	virtual double getRadius();
	int closestPoint(vector<double> circ, vector<double> poly);
	std::string toString();
};

