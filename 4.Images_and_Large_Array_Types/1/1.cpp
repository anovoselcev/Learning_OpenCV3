﻿//Суммирование по двум массивам с помощью N-арного итератора
#include <opencv2/core/types_c.h>
int main(){
	const int n_mat_size = 5;
	const int n_mat_sz[] = { n_mat_size, n_mat_size, n_mat_size };
	cv::Mat n_mat0(3, n_mat_sz, CV_32FC1);
	cv::Mat n_mat1(3, n_mat_sz, CV_32FC1);

	cv::RNG rng;
	rng.fill(n_mat0, cv::RNG::UNIFORM, 0.f, 1.f);
	rng.fill(n_mat1, cv::RNG::UNIFORM, 0.f, 1.f);

	const cv::Mat* arrays[] = { &n_mat0, &n_mat1, 0 };
	cv::Mat my_planes[2];
	cv::NAryMatIterator it(arrays, my_planes);

	float s = 0.f;
	int n = 0;
	for (int p = 0; p < it.nplanes; p++, ++it) {
		s += cv::sum(it.planes[0])[0];
		s += cv::sum(it.planes[1])[0];
		n++;
	}
	return 0;
}

