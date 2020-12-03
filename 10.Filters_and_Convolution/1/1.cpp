#include <opencv2/opencv.hpp>

int main() {

	cv::namedWindow("Window3");
	cv::namedWindow("Window5");
	cv::namedWindow("Window11");

	cv::Mat img = cv::imread("../../image2.png"), dst1, dst2, dst3;

	cv::GaussianBlur(img, dst1, cv::Size(3,3), 12.2);
	cv::GaussianBlur(img, dst2, cv::Size(5, 5), 12.2);
	cv::GaussianBlur(img, dst3, cv::Size(11, 11), 12.2);

	cv::imshow("Window3", dst1);
	cv::imshow("Window5", dst2);
	cv::imshow("Window11", dst3);

	cv::waitKey();
	return 0;
}

