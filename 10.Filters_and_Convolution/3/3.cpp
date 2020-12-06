#include <opencv2/opencv.hpp>
int main() {
	cv::namedWindow("GaussianBlur 9x9, sig_x = 1");
	cv::namedWindow("GaussianBlur 9x9, sig_x = 4");
	cv::namedWindow("GaussianBlur 9x9, sig_x = 6");

	cv::namedWindow("GaussianBlur 0x0, sig_x = 1");
	cv::namedWindow("GaussianBlur 0x0, sig_x = 4");
	cv::namedWindow("GaussianBlur 0x0, sig_x = 6");

	cv::namedWindow("GaussianBlur 0x0, sig_x = 1, sig_y = 9");
	cv::namedWindow("GaussianBlur 0x0, sig_x = 9, sig_y = 1");
	cv::namedWindow("GaussianBlur 0x0, sig_x = 1 -> 9, sig_y = 9 -> 1");

	cv::namedWindow("GaussianBlur 9x9, sig_x = 0, sig_y = 0");

	cv::Mat img = cv::imread("../../image2.png"), dst1, dst2,dst3;

	cv::GaussianBlur(img, dst1, cv::Size(9, 9), 1);
	cv::GaussianBlur(img, dst2, cv::Size(9, 9), 4);
	cv::GaussianBlur(img, dst3, cv::Size(9, 9), 6);

	cv::imshow("GaussianBlur 9x9, sig_x = 1", dst1);
	cv::imshow("GaussianBlur 9x9, sig_x = 4", dst2);
	cv::imshow("GaussianBlur 9x9, sig_x = 6", dst3);

	cv::GaussianBlur(img, dst1, cv::Size(0, 0), 1);
	cv::GaussianBlur(img, dst2, cv::Size(0, 0), 4);
	cv::GaussianBlur(img, dst3, cv::Size(0, 0), 6);

	cv::imshow("GaussianBlur 0x0, sig_x = 1", dst1);
	cv::imshow("GaussianBlur 0x0, sig_x = 4", dst2);
	cv::imshow("GaussianBlur 0x0, sig_x = 6", dst3);

	cv::GaussianBlur(img, dst1, cv::Size(0, 0), 1, 9);
	cv::GaussianBlur(img, dst2, cv::Size(0, 0), 9, 1);
	cv::GaussianBlur(dst1, dst3, cv::Size(0, 0), 9, 1);

	cv::imshow("GaussianBlur 0x0, sig_x = 1, sig_y = 9", dst1);
	cv::imshow("GaussianBlur 0x0, sig_x = 9, sig_y = 1", dst2);
	cv::imshow("GaussianBlur 0x0, sig_x = 1 -> 9, sig_y = 9 -> 1", dst3);

	cv::GaussianBlur(img, dst1, cv::Size(9, 9), 0, 0);
	cv::imshow("GaussianBlur 9x9, sig_x = 0, sig_y = 0", dst1);
	cv::waitKey();

	return 0;
}

