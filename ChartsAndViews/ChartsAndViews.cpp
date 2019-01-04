#include "pch.h"
#include "Chart.h"
#include "Point.h"
#include "Color.h"
#include "View.h"
#include <iostream>
#include <array>
#include <vector>
#include <numeric>
#include <algorithm>

void Print(bool, Color);

int main(int argc, char* argv[])
{
	Chart a(Point(0, 0), Point(2, 2), Color(255, 0, 100));
	Chart b(Point(1, 1), Point(3, 3), Color(255, 255, 200));

	View view;

	view.charts = { a, b };
	bool overlap = view.DoChartsOverlap();
	Color color = view.GetColor(1, 1);
	Print(overlap, color);


	view.charts = { a, a };
	overlap = view.DoChartsOverlap();
	color = view.GetColor(1, 1);
	Print(overlap, color);

	color = view.GetColor(99, 99);
	std::cout << "[" << color.r << "," << color.g << "," << color.b << "]" << std::endl;

	return 0;
}

void Print(bool boolean, Color color)
{
	std::cout << std::boolalpha << boolean << " [" << color.r << "," << color.g << "," << color.b << "]" << std::endl;
}
