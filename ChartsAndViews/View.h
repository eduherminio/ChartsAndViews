#pragma once
#include <array>
#include "Chart.h"

class Point;
class Chart;
class Color;

class View {
public:
	static const int max_size = 2;
	std::array<Chart, max_size> charts;
	Color color;

	View();
	bool DoChartsOverlap(); // OK, valid only for max_size=2
	Color GetColor(int x, int y);

private:
	const Color _defaultColor = Color(1, 2, 3);
	Color GetColor(Point point);
};