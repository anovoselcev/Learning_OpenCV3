#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	cv::Mat img = cv::imread("../../image3.png");
	cv::Mat gray;
	cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
	cv::cvtColor(gray, gray, cv::COLOR_GRAY2BGR);
	cv::putText(gray, "Hello World", cv::Point(100, 100), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(100, 200, 250));
	cv::namedWindow("Window", cv::WINDOW_NORMAL);
	cv::imshow("Window", gray);
	cv::waitKey(0);
	return 0;
}

