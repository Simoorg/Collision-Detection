#pragma once
#include "BaseShape.h"

class BaseTrapeze : public BaseShape
{
public:
	BaseTrapeze();
	BaseTrapeze(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
	~BaseTrapeze();
};

