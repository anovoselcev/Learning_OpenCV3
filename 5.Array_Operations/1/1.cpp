#include <opencv2/opencv.hpp>
int main() {
	cv::Mat src1 = cv::imread("../../image2.png");
	cv::Mat src2 = cv::imread("../../image1.png");
	int x = 100;
	int y = 100;
	int w = 300;
	int h = 300;
	double alpha = 0.4;
	double beta = 0.6;
	cv::Mat roi1(src1, cv::Rect(x, y, w, h));
	cv::Mat roi2(src2, cv::Rect(0, 0, w, h));
	cv::addWeighted(roi1, alpha, roi2, beta, 0.0, roi1);
	cv::namedWindow("Alpha blend");
	cv::imshow("Alpha blend", src1);
	cv::waitKey(0);
	return 0;
}

