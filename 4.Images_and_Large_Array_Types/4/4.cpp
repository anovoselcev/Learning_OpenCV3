#include <opencv2/opencv.hpp>
#include <iostream>

cv::Mat Integrate(const cv::Mat& source) {
	size_t c = source.cols;
	size_t r = source.rows;
	int type = source.type();
	cv::Mat integrate = cv::Mat::zeros(c, r, type);
	integrate.at<float>(0, 0) = source.at<float>(0,0);
	for (int i = 0; i < source.rows; i++) {
		for (int j = 0; j < source.cols; j++) {
			if ((i == 0) && (j != 0))
				integrate.at<float>(0, j) = source.at<float>(0, j) + integrate.at<float>(0, j - 1);
			else if ((j == 0) && (i != 0))
				integrate.at<float>(i, 0) = source.at<float>(i, 0) + integrate.at<float>(i - 1, 0);
			else if ((i != 0) && (j != 0))
				integrate.at<float>(i, j) = source.at<float>(i,j)  + integrate.at<float>(i, j - 1) + integrate.at<float>(i - 1, j) - integrate.at<float>(i - 1, j - 1);
		}
	}
	return integrate;
}

float IntegrateArea(const cv::Mat& source, cv::Point2i p) {
	float result = source.at<float>(p.y, p.x);
	if (p.x != 0)
		result += IntegrateArea(source, cv::Point2i(p.x - 1, p.y));
	if(p.y != 0)
		result += IntegrateArea(source, cv::Point2i(p.x, p.y - 1));
	if((p.x != 0) && (p.y != 0))
		result -= IntegrateArea(source, cv::Point2i(p.x - 1, p.y - 1));
	return result;
}

int main() {
	cv::Mat source(400, 400, CV_32F);
	cv::RNG rng(std::time(0));
	rng.fill(source, cv::RNG::NORMAL, 0.f, 10.f);
	cv::namedWindow("Source", cv::WINDOW_NORMAL);
	cv::namedWindow("Integrate", cv::WINDOW_NORMAL);
	cv::Mat integrate = Integrate(source);
	std::cout << IntegrateArea(source, cv::Point2d(4, 5)) - integrate.at<float>(cv::Point2i(4, 5)) << std::endl;
	char c = '1';
	while (c != 'c') {
		cv::imshow("Source", source);
		cv::imshow("Integrate", integrate);
		c = cv::waitKey(0);
	}
	return 0;
}

