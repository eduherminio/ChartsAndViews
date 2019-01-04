#include "pch.h"
#include "Chart.h"
#include "Point.h"

Chart::Chart() {}
Chart::~Chart() {}

Chart::Chart(Point topLeft, Point bottomRight, Color color)
	:topLeft(topLeft), bottomRight(bottomRight), color(color)
{}