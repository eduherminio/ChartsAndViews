#include "pch.h"
#include "View.h"
#include "Color.h"
#include "Point.h"
#include "Chart.h"
#include <vector>
#include <numeric>
#include <algorithm>

View::View()
	:color(_defaultColor)
{}

/// Using ranges rather than '>' and '<'
bool View::DoChartsOverlap() // OK, valid only for max_size=2
{
	if (charts.size() != max_size)
	{
		return false;
	}

	std::vector<int> xVector(std::abs(charts[0].topLeft.x - charts[0].bottomRight.x) + 1);
	std::vector<int> yVector(std::abs(charts[0].topLeft.y - charts[0].bottomRight.y) + 1);
	std::iota(xVector.begin(), xVector.end(), 0);
	std::iota(yVector.begin(), yVector.end(), 0);

	return
		(xVector.end() != std::find(xVector.begin(), xVector.end(), charts[0].topLeft.x)
			|| xVector.end() != std::find(xVector.begin(), xVector.end(), charts[0].bottomRight.x))
		&& (yVector.end() != std::find(yVector.begin(), yVector.end(), charts[0].topLeft.y)
			|| yVector.end() != std::find(yVector.begin(), yVector.end(), charts[0].bottomRight.y));
};

Color View::GetColor(int x, int y)
{
	return GetColor(Point(x, y));
}

Color View::GetColor(Point point) {
	std::vector<int> chartsIndexes;

	for (size_t i = 0; i < charts.size(); ++i)
	{
		if (point.IsInsideChart(charts[i]))
		{
			chartsIndexes.push_back(i);
		}
	}

	Color color = this->_defaultColor;
	for (size_t i = 0; i < chartsIndexes.size(); ++i)
	{
		color.r += charts.at(i).color.r;
		color.g += charts.at(i).color.g;
		color.b += charts.at(i).color.b;
	}

	if (chartsIndexes.size())
	{
		color.r /= chartsIndexes.size();
		color.g /= chartsIndexes.size();
		color.b /= chartsIndexes.size();
	}

	return color;
}