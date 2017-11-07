#pragma once

class Projection {
private:
	double max;
	double min;
public:
	Projection(double maxN, double minN);
	double getMax();
	double getMin();
	bool overlaps(Projection& other);
};