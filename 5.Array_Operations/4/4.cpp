#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	cv::Mat img = cv::Mat::zeros(cv::Size(210, 210), CV_8U);
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 10; j++) {
			cv::Mat roiImg = cv::Mat::zeros(cv::Size(210, 210), CV_8U);
			cv::Rect roi = cv::Rect(cv::Point(10 * i + j, 10 * i + j),
									cv::Point(209 - 10 * i - j, 209 - 10 * i - j));
			
			cv::rectangle(roiImg, roi, 1);
			img.setTo(20 * i, roiImg);
		}
	}
	cv::namedWindow("Window");
	cv::imshow("Window", img);
	cv::waitKey(0);
	return 0;
}

