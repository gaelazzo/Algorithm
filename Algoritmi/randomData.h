#pragma once

#include <vector>
#include <tuple>
#include <random>
using namespace std;

namespace Algoritmi {
	vector<int> createRandomVector(size_t n, double min, double max);
	std::string createRandomStringLower(const int len);
}