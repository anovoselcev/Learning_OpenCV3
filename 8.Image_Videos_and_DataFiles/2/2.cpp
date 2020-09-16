#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	auto img = cv::imread("../../image3.png");
	cv::namedWindow("Window");
	cv::setMouseCallback("Window", [](
		int event,
		int x, int y,
		int flags,
		void* userdata)
		{
            if (event == cv::EVENT_LBUTTONDOWN){
				auto vec = static_cast<cv::Mat*>(userdata)->at<cv::Vec3f>(y, x);
				std::cout << "At : x = " << x << "; and y = " << y << ";" << std::endl;
				std::cout << "Blue = "	<< vec[0] << std::endl;
				std::cout << "Green = " << vec[1] << std::endl;
				std::cout << "Red = "	<< vec[2] << std::endl;
            }
            else if (event == cv::EVENT_RBUTTONDOWN){
            }
            else if (event == cv::EVENT_MBUTTONDOWN) {
            }
            else if (event == cv::EVENT_MOUSEMOVE){
            }
		}, &img);
	cv::imshow("Window", img);
	cv::waitKey(0);
	return 0;
}

