#include <opencv2/core/types_c.h>
#include <iostream>
int main(){
	double value = 2.123;
	std::cout << "Ceil = " << cvCeil(value) << std::endl;
	std::cout << "Floor = " << cvFloor(value) << std::endl;
	cv::Point2f p1;
	cv::Point p2(p1);
	cv::Point p3(p2);
	return 0;
}

