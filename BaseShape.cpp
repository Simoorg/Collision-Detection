
#include "BaseShape.h"
#include "BaseCircle.h"
using namespace std;


BaseShape::BaseShape()
{
}


BaseShape::~BaseShape()
{
}

void BaseShape::rotate(double radians) {
	int vecSize = points.size();
	for (int i = 0; i < vecSize; i =i+2) {
		double oldX = points[0];
		points.erase(points.begin());
		double oldY = points[0];
		points.erase(points.begin());
		double newX = oldX*cos(radians) - oldY*sin(radians);
		double newY = oldX*sin(radians) + oldY*cos(radians);
		points.push_back(newX);
		points.push_back(newY);
	}
}

void BaseShape::shift(double deltaX, double deltaY)
{
	for (int i = 0; i < points.size(); i =i+2) {
		points[i] = points[i] + deltaX;
		points[i+1] = points[i+1] + deltaY;
	}
}

bool BaseShape::areColliding(BaseShape& other) {
	if (isCircle == true && other.getIsCircle() == true) {
		return areColliding(other);
	}

	vector<double> otherPoints = other.getPoints();
	vector<double> axes1 = getAxes(points);
	vector<double> axes2 = getAxes(other.getPoints());

	int index;
	if (isCircle == true) {
		index = closestPoint(points, otherPoints);
		axes2.push_back((-1)*(points[1] - otherPoints[index + 1]));
		axes2.push_back(points[0] - otherPoints[index]);
		axes1.clear();
	}
	if (other.getIsCircle()){
		index = closestPoint(otherPoints, points);
		axes1.push_back((-1)*(otherPoints[1] - points[index + 1]));
		axes1.push_back(otherPoints[0] - points[index]);
		axes2.clear();
	}

	for (int i = 0; i < axes1.size(); i = i + 2) {
		Projection proj1 = makeProjection(axes1[i], axes1[i + 1], points);
		Projection proj2 = other.makeProjection(axes1[i], axes1[i + 1], otherPoints);
		if (!proj1.overlaps(proj2))
			return false;
	}
	for (int i = 0; i < axes2.size(); i = i + 2) {
		Projection proj1 = makeProjection(axes2[i], axes2[i + 1], points);
		Projection proj2 = other.makeProjection(axes2[i], axes2[i + 1], otherPoints);
		if (!proj1.overlaps(proj2))
			return false;
	}
	return true;
}


vector<double> BaseShape::getAxes(vector<double>& toAxes) {
	vector<double> axes;
	for (int i = 0; i < toAxes.size(); i = i + 2) {
		double x1 = toAxes[i];
		double y1 = toAxes[i+1];
		double x2 = toAxes[i + 2 >= toAxes.size() ? 0 : i + 2];
		double y2 = toAxes[i + 3 >= toAxes.size() ? 1 : i + 3];
		x1 = x1 - x2;
		y1 = y1 - y2;
		axes.push_back(-y1);
		axes.push_back(x1);
	}

	return axes;
}

double BaseShape::dotProduct(double x1, double y1, double axisX, double axisY) {
	return (x1*axisX) + (y1*axisY);
}

Projection BaseShape::makeProjection(double axisX, double axisY, vector<double> toProjection) {
	double min = dotProduct(toProjection[0], toProjection[1], axisX, axisY);
	double max = min;
	for (int i = 2; i < toProjection.size(); i=i+2) {
		double temp = dotProduct(toProjection[i], toProjection[i + 1], axisX, axisY);
		if (temp < min) {
			min = temp;
		}
		else if (temp > max) {
			max = temp;
		}
	}
	Projection proj = Projection(max, min);
	return proj;
}

vector<double> BaseShape::getPoints() {
	return points;
}

bool BaseShape::getIsCircle () {
	return isCircle;
}
double BaseShape::getRadius() {
	return 0;
 }

int BaseShape::closestPoint(vector<double> circ, vector<double> poly) {
	double circleX = circ[0];
	double circleY = circ[1];
	double minDist = sqrt((circleX - poly[0] * circleX - poly[0]) + (circleY - poly[1] * circleY - poly[1]));
	int minIndex = 0;
	for (int i = 2; i < poly.size(); i = i + 2) {
		double tempDist = sqrt((circleX - poly[i] * circleX - poly[i]) + (circleY - poly[i + 1] * circleY - poly[i + 1]));
		if (tempDist < minDist) {
			minDist = tempDist;
			minIndex = i;
		}
	}
	return minIndex;
}

std::string BaseShape::toString()
{
	string str = "";
	if (isCircle) {
		str += "Kolo o srodku w punkcie: " + to_string(points[0]) + ", " + to_string(points[1]);
		str += " oraz srednicy " + to_string(getRadius());
	}
	else {
		str += "Wielokat o wierzcholkach w punktach: (";
		for (int i = 0; i < points.size(); i++) {
			str += to_string(points[i]);
			if ((i+1) % 2 == 0 && i != 0)
				str += "), (";
			else
				str += ", ";
		}
		str.erase(str.length() - 3, str.length() - 1);
	}
	return str;
}
