#include <opencv2/opencv.hpp>

int main() {
	cv::Mat mat1 = cv::Mat::zeros(cv::Size(20, 1), CV_32F);
	cv::RNG rng;
	rng.fill(mat1, cv::RNG::UNIFORM, 0., 1.);
	rng.fill(mat1, cv::RNG::NORMAL, 0., 1.);
	cv::Mat mat2 = cv::Mat::zeros(cv::Size(20, 1), CV_16U);
	rng.fill(mat2, cv::RNG::UNIFORM, 0, 255);
	cv::Mat mat3 = cv::Mat::zeros(cv::Size(20, 1), CV_16UC3);
	rng.fill(mat3, cv::RNG::UNIFORM, 0, 255);
	return 0;
}

