#include <iostream>
#include <vector>
#include <tuple>
#include <random>

using namespace std;


namespace Algoritmi {
	vector<int> createRandomVector(size_t n, double min, double max) {
		vector<int> v = vector<int>(n);
		random_device rd;
		mt19937 mt(rd());
		uniform_real_distribution<double> dist(min, max);
		for (size_t i = 0; i < n; i++) {
			v[i] = (int)dist(mt);
		}
		return v;
	}


	std::string createRandomStringLower(const int len) {
		static const char alphanum[] =
			//"0123456789"
			//"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		std::string tmp_s;
		tmp_s.reserve(len);

		for (int i = 0; i < len; ++i) {
			tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
		}

		return tmp_s;
	}

}