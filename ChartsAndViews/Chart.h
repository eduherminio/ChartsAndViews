#pragma once
#include "Point.h"
#include "Color.h"
#include <vector>
#include <numeric>
#include <algorithm>

class Point;

class Chart {
public:
	Point topLeft;
	Point bottomRight;
	Color color;

	Chart();
	Chart(Point topLeft, Point bottomRight, Color color);
	~Chart();
};