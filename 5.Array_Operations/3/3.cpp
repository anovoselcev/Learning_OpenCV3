#include <opencv2/opencv.hpp>
#include <iostream>

void PrintRectFor(cv::Mat& img, const cv::Point& lhs, const cv::Point& rhs) {
	for (int i = lhs.y; i <= rhs.y; i++) {
		std::cout << i << std::endl;
		img.at<cv::Vec3b>(i, rhs.x + 1) = { 200, 0, 100 };
		img.at<cv::Vec3b>(i, lhs.x + 1) = { 200, 0, 100 };
	}
	
	for (int i = lhs.x; i <= rhs.x; i++) {
		img.at<cv::Vec3b>(lhs.y, i) = { 200, 0, 100 };
		img.at<cv::Vec3b>(rhs.y, i) = { 200, 0, 100 };
	}


}


int main() {
	cv::Mat img = cv::Mat::zeros(cv::Size(100, 100), CV_16UC3);
	cv::Point p1(20, 5), p2(40, 20);
	PrintRectFor(img, p1, p2);
	cv::namedWindow("Window", cv::WINDOW_NORMAL);
	cv::imshow("Window", img);
	cv::waitKey(0);
	return 0;
}

