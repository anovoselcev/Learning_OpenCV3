#include <opencv2/opencv.hpp>
#include <chrono>
#include <iostream>

int main() {
	cv::RNG rng(std::chrono::steady_clock::now().time_since_epoch().count());
	float f1 = rng.uniform(0.f, 1.f),
		f2 = rng.uniform(0.f, 1.f),
		f3 = rng.uniform(0.f, 1.f);
	std::cout << "f1 = " << f1 << "; f2 = " << f2 << "; f3 = " << f3 << std::endl;
	double d1 = rng.gaussian(1.),
		d2 = rng.gaussian(1.),
		d3 = rng.gaussian(1.);
	std::cout << "d1 = " << d1 << "; d2 = " << d2 << "; d3 = " << d3 << std::endl;
	int c1 = rng.uniform(0, 255),
		c2 = rng.uniform(0, 255),
		c3 = rng.uniform(0, 255);
	std::cout << "c1 = " << c1 << "; c2 = " << c2 << "; c3 = " << c3 << std::endl;
	return 0;
}

