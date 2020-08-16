#include <opencv2/opencv.hpp>

cv::Mat Integrate(const cv::Mat& source) {
	size_t c = source.cols;
	size_t r = source.rows;
	int type = source.type();
	cv::Mat integrate(c, r, type);
	integrate.at<float>(0, 0) = 0;
	float last_sum_col = 0, last_sum_row = 0;
	for (int i = 0; i < source.rows; i++) {
		for (int j = 0; j < source.cols; j++) {
			if ((i == 0) && (j != 0)) {
				integrate.at<float>(0, j) = last_sum_col + source.at<float>(0, j - 1);
				last_sum_col = integrate.at<float>(0, j);
			}
			else if ((j == 0) && (i != 0)) {
				integrate.at<float>(i, 0) = last_sum_row + source.at<float>(i - 1, 0);
				last_sum_row = integrate.at<float>(i, 0);
			}
			else if (i != 0 && j != 0)
				integrate.at<float>(i, j) = integrate.at<float>(i, j - 1) + integrate.at<float>(i - 1, j) - integrate.at<float>(i - 1, j - 1);
		}
	}
	return integrate;
}


int main() {
	cv::Mat source(400, 400, CV_32F);
	cv::RNG rng(std::time(0));
	rng.fill(source, cv::RNG::NORMAL, 0.f, 1000.f);
	cv::namedWindow("Source", cv::WINDOW_NORMAL);
	cv::namedWindow("Integrate", cv::WINDOW_NORMAL);
	cv::Mat integrate = Integrate(source);
	char c = '1';
	while (c != 'c') {
		cv::imshow("Source", source);
		cv::imshow("Integrate", integrate);
		c = cv::waitKey(0);
	}
	return 0;
}

