#include<opencv2/opencv.hpp>

int main() {
	cv::Mat img = cv::Mat::zeros(cv::Size(100, 100), CV_8U);
	img.at<uchar>(49, 49) = 255;
	cv::namedWindow("GaussianBlur 5x5");
	cv::namedWindow("GaussianBlur 9x9");
	cv::namedWindow("GaussianBlur 5x5 -> 5x5");
	cv::namedWindow("GaussianBlur 9x9 -> 9x9");
	cv::Mat dst1, dst2, dst3, dst4;
	cv::GaussianBlur(img, dst1, cv::Size(5, 5), 0.001);
	cv::GaussianBlur(img, dst2, cv::Size(9, 9), 0.001);
	cv::imshow("GaussianBlur 5x5", dst1);
	cv::imshow("GaussianBlur 9x9", dst2);
	cv::GaussianBlur(dst1, dst3, cv::Size(5, 5), 0.001);
	cv::GaussianBlur(dst2, dst4, cv::Size(9, 9), 0.001);
	cv::imshow("GaussianBlur 5x5 -> 5x5", dst3);
	cv::imshow("GaussianBlur 9x9 -> 9x9", dst4);
	cv::waitKey();
	return 0;
}

