#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	cv::Mat_<uchar> img = cv::Mat_<uchar>::zeros(400, 400);
	cv::namedWindow("Circle");
	cv::circle(img, cv::Point(100, 100), 80, uchar(100));
	cv::imshow("Circle", img);
	cv::waitKey(0);
	return 0;
}

