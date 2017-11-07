#include "BaseCircle.h"
using namespace std;

BaseCircle::BaseCircle()
{
}

BaseCircle::BaseCircle(double x1, double y1, double nRadius)
{
	isCircle = true;
	points.push_back(x1);
	points.push_back(y1);
	radius = nRadius;
}

BaseCircle::~BaseCircle()
{
}

Projection BaseCircle::makeProjection(double axisX, double axisY, vector<double> toProjection) {
	double min = BaseShape::dotProduct(toProjection[0], toProjection[1], axisX, axisY);
	double max = min;
	Projection proj = Projection(max + radius, min - radius);
	return proj;
}

bool BaseCircle::areColliding(BaseShape& other) {
	double deltaX = points[0] - other.getPoints()[0];
	double deltaY = points[1] - other.getPoints()[1];
	double dist = sqrt(deltaX*deltaX + deltaY*deltaY);
	return ((radius + other.getRadius()) > dist);
}

double BaseCircle::getRadius() {
	return radius;
}