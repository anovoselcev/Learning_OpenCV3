#include <opencv2/opencv.hpp>
#include <iostream>
int main() {
	cv::Mat mat = cv::Mat::zeros(3, 2, CV_32F);
	mat.at<float>(0, 0) = 1.f;
	mat.at<float>(0, 1) = 1.f;
	mat.at<float>(1, 0) = 0.f;
	mat.at<float>(1, 1) = 1.f;
	mat.at<float>(2, 0) = -1.f;
	mat.at<float>(2, 1) = 1.f;

	cv::Mat W, U, Wt;
	cv::SVD svd;
	svd.compute(mat, W, U, Wt);

	std::cout << W.at<float>(0, 0) << " " << W.at<float>(1, 1) << std::endl;
	return 0;
}

