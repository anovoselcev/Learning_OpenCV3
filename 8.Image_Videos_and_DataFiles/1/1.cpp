#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>

int main() {
	cv::VideoCapture cap;
	cap.open("../../video1.mp4");
    if (!cap.isOpened()) {
        std::cerr << "Ошибка при открытии устройства захвата." << std::endl;
        return -1;
    }
    cv::namedWindow("Frame");
    cv::namedWindow("BFrame");
    cv::namedWindow("CFrame");
    cv::namedWindow("Combo", cv::WINDOW_NORMAL);
    std::vector<cv::Mat> vec(3);
    for (;;) {
        cap >> vec[0];
        if (vec[0].empty())
            break;
        cv::Mat conv;
        cv::cvtColor(vec[0], conv, cv::COLOR_BGR2GRAY);
        cv::cvtColor(conv, vec[1], cv::COLOR_GRAY2BGR);
        cv::Canny(conv, vec[2], 10, 10);
        conv = vec[2].clone();
        cv::cvtColor(conv, vec[2], cv::COLOR_GRAY2BGR);
        cv::Mat res(vec[0].rows*3, vec[0].cols, vec[0].type());
       
        vec[0].copyTo(res.rowRange(0, vec[0].rows).colRange(0, vec[0].cols));
        vec[1].copyTo(res.rowRange(vec[0].rows, 2 * vec[0].rows).colRange(0, vec[0].cols));
		vec[2].copyTo(res.rowRange(vec[0].rows * 2, vec[0].rows * 3).colRange(0, vec[0].cols));
        cv::putText(vec[0], "Origin", cv::Point(100, 100), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(100, 200, 250));
        cv::putText(vec[1], "Gray", cv::Point(100, 100), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(100, 200, 250));
        cv::putText(vec[2], "Canny", cv::Point(100, 100), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(100, 200, 250));
    	cv::putText(res, "Combo", cv::Point(100, 100), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(100, 200, 250));
    	cv::imshow("Frame", vec[0]);
        cv::imshow("BFrame", vec[1]);
        cv::imshow("CFrame", vec[2]);
        cv::imshow("Combo", res);
        if (cv::waitKey(33) >= 0)
            break;
    }
	return 0;
}

