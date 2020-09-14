#include <opencv2/opencv.hpp>
#include <ctime>
#include <vector>
#include <iostream>

int main() {
	std::vector<cv::Mat> mat(3, cv::Mat::zeros(cv::Size(1, 100), CV_16U));
	cv::RNG rng(std::time(0));
	rng.fill(mat[0], cv::RNG::NORMAL, 64, 10);
	rng.fill(mat[1], cv::RNG::NORMAL, 192, 10);
	rng.fill(mat[2], cv::RNG::NORMAL, 128, 2);
	cv::Mat result(100, 3, CV_16U);
	for (int i = 0; i < 3; i++)
		mat[i].copyTo(result.col(i));
	cv::PCA pca;
	auto m = pca(result, cv::noArray(), cv::PCA::DATA_AS_COL, 2);
	auto mean = pca.mean;
	return 0;
}

