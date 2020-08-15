#include <opencv2/opencv.hpp>
#include <iostream>
int main() {
	size_t c = 300, r = 300;
	cv::Mat source(c, r, 1.f);
	cv::Mat integrate(c, r, 0.f);
	cv::RNG rng(0x1234);
	rng.fill(source, cv::RNG::NORMAL, 0, 1);
	cv::namedWindow("Source", cv::WINDOW_AUTOSIZE);
	//cv::namedWindow("Integrate", cv::WINDOW_AUTOSIZE);
	//integrate.at<float>(0, 0) = 0;
	float last_sum_col = 0, last_sum_row = 0;
	for (int i = 0; i < source.cols; i++) {
		for (int j = 0; j < source.rows; j++) {
			if ((i == 0) && (j != 0)) {
				integrate.at<float>(0, j) = last_sum_col + source.at<float>(0, j - 1);
				last_sum_col = integrate.at<float>(0, j);
			}
			else if ((j == 0) && (i != 0)) {
				integrate.at<float>(i, 0) = last_sum_row + source.at<float>(i - 1, 0);
				last_sum_row = integrate.at<float>(i, 0);
			}
			else if(i !=0 && j !=0) {
				float sum1 = integrate.at<float>(i, j - 1) + integrate.at<float>(i - 1, j);
				float sum2 = sum1 - integrate.at<float>(i - 1, j - 1);
				//std::cout << sum << std::endl;
				integrate.at<float>(i, j) = sum2;
			}
		}
	}
	
	cv::imshow("Source", source);
	//cv::imshow("Integrate", integrate);
	cv::waitKey(0);
	return 0;
}

