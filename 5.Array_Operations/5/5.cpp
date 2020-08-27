#include <opencv2/opencv.hpp>

int main() {
	cv::Mat img = cv::imread("../../image3.png");
	cv::Mat roi1 = cv::Mat::zeros(cv::Size(img.cols, img.rows), CV_8U);
	cv::Mat roi2 = cv::Mat::zeros(cv::Size(img.cols, img.rows), CV_8U);
	cv::rectangle(roi1, cv::Rect(cv::Point(5, 10),
								 cv::Point(25, 40)), 1);
	cv::rectangle(roi2, cv::Rect(cv::Point(50, 60),
						cv::Point(70, 90)), 1);
	cv::bitwise_not(img, img, roi1);
	cv::bitwise_not(img, img, roi2);
	cv::namedWindow("Window");
	cv::imshow("Window", img);
	cv::waitKey(0);
	return 0;
}

