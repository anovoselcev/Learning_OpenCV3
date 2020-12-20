#include <opencv2/opencv.hpp>

int main() {
	cv::namedWindow("Diff");
	cv::namedWindow("Erode->Dilate", cv::WINDOW_NORMAL);
	cv::namedWindow("Dilate->Erode", cv::WINDOW_NORMAL);
	auto img1 = cv::imread("../../image4.jpg");
	auto img2 = cv::imread("../../image5.jpg");
	auto diff = img2 - img1;
	cv::imshow("Diff", diff);

	cv::Mat element;
	cv::Mat cleandiff, dirtydiff;

	cv::erode(diff, cleandiff, element);
	cv::dilate(cleandiff, cleandiff, element);
	cv::imshow("Erode->Dilate", cleandiff);

	cv::dilate(diff, dirtydiff, element);
	cv::erode(dirtydiff, dirtydiff, element);
	cv::imshow("Dilate->Erode", dirtydiff);

	cv::waitKey(0);
	return 0;
}

