#include "pch.h"
#include "Point.h"
#include "Chart.h"

Point::Point()
	:x(0), y(0)
{}

Point::~Point() {}

Point::Point(int x, int y)
	: x(x), y(y)
{}

/// Using ranges rather than '>' and '<'
bool Point::IsInsideChart(Chart chart)
{
	std::vector<int> xVector(std::abs(chart.topLeft.x - chart.bottomRight.x) + 1);
	std::vector<int> yVector(std::abs(chart.topLeft.y - chart.bottomRight.y) + 1);
	std::iota(xVector.begin(), xVector.end(), 0);
	std::iota(yVector.begin(), yVector.end(), 0);

	return
		(xVector.end() != std::find(xVector.begin(), xVector.end(), x)
			&& yVector.end() != std::find(yVector.begin(), yVector.end(), y));
}