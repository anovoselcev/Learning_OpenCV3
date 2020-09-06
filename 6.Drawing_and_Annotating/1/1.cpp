#include<opencv2/opencv.hpp>
#include <vector>

int main() {
	cv::Mat img = cv::imread("../../image3.png");
	cv::circle(img, cv::Point(40, 40), 20, cv::Scalar(30, 240, 170));
	cv::rectangle(img, cv::Rect(100, 100, 200, 30), cv::Scalar(245, 40, 167));
	cv::ellipse(img, cv::Point(200, 200), cv::Size(100, 200), 40, 0, 280, cv::Scalar(40, 130, 250));
	cv::line(img, cv::Point(0, 0), cv::Point(400, 400), cv::Scalar(60, 240, 89));
	std::vector<cv::Point> points;
	for (int i = 0; i < 10; ++i)
		points.push_back(cv::Point(i * 10 + i * 5 / 2, i * 6 + i * 7 / 3));
	cv::polylines(img, points, true, cv::Scalar(240, 220, 20));
	cv::namedWindow("Window", cv::WINDOW_NORMAL);
	cv::imshow("Window", img);
	cv::waitKey(0);
	return 0;
}

