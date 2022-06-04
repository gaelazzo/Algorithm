#pragma once

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

namespace Algoritmi {

	std::tuple<int, int> searchOccurrenciesNaive(char* p, char* S, std::vector<int> A);

	std::vector<int> kasai(string s, vector<int> sa);
}