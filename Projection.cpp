#include "Projection.h"
using namespace std;

Projection::Projection(double maxN, double minN)
{
	max = maxN;
	min = minN;
}

double Projection::getMax()
{
	return max;
}

double Projection::getMin()
{
	return min;
}

bool Projection::overlaps(Projection & other)
{
	double otherMax = other.getMax();
	double otherMin = other.getMin();
	return (otherMax >= max && otherMin >= max) || (otherMax <= min && otherMin <= min);
}
