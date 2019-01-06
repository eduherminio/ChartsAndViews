#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <numeric>
#include <algorithm>

class Chart;

class Point {
public:
	int x;
	int y;

	Point();
	Point(int x, int y);
	~Point();

	bool IsInsideChart(const Chart&) const;
};