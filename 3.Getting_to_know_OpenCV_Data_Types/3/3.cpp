#include <opencv2/core/types_c.h>
int main(){
	cv::Matx<double,3, 3> mat;
	cv::Vec<double, 3> vec;
	auto d = mat * vec;
	cv::Matx<double, 3, 1> mat2(vec);
	return 0;
}

