#include <opencv2/core/types_c.h>
int main(){
	cv::Matx33f m(1,2,3,4,5,6,7,8,9);
	cv::Vec3f v(-1, -3, 4);
	cv::Vec3f d = m* v;
	return 0;
}

