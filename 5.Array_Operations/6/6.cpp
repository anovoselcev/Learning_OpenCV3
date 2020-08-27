#include <opencv2/opencv.hpp>
#include <iostream>

template<typename T>
void fillMat(cv::Mat& img, T value) {
	for (int i = 0; i < img.cols; ++i) {
		for (int j = 0; j < img.rows; ++j)
			img.at<uchar>(j, i) = value;
	}
}

int main() {
	cv::Mat img = cv::imread("../../image3.png");
	cv::Mat chanels[3];
	cv::split(img, chanels);
	cv::namedWindow("Green");
	cv::namedWindow("Clone1");
	cv::namedWindow("Clone2");
	cv::Mat clone1, clone2;
	clone1 = clone2 = chanels[1].clone();
	double min, max;
	cv::Point pmin, pmax;
	cv::minMaxLoc(chanels[1], &min, &max, &pmin, &pmax);
	fillMat(clone1, (max - min) / 2);
	clone2 = cv::Mat::zeros(img.cols, img.rows, chanels[1].type());
	cv::compare(chanels[1], clone1, clone2, cv::CMP_GE);
	cv::subtract(chanels[1], (max - min) / 4, chanels[1], clone2);
	cv::imshow("Green", chanels[1]);
	cv::imshow("Clone1", clone1);
	cv::imshow("Clone2", clone2);
	cv::waitKey(0);
	return 0;
}

