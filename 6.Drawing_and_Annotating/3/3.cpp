#include <opencv2/opencv.hpp>
#include <chrono>
int main() {
	cv::namedWindow("Window", cv::WINDOW_AUTOSIZE);
	cv::VideoCapture cap;
    cap.open("../../video1.MP4");
    int FPS = 0, FPSlast = 0;
    auto start = std::chrono::steady_clock::now();
    cv::Mat frame;
    for (;;) {
        cap >> frame;
        if (frame.empty())
            break;
        if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() > 1000) {
            start = std::chrono::steady_clock::now();
            FPSlast = FPS;
            FPS = 0;
        }
        else {
            FPS++;
        }
        cv::putText(frame, "FPS = " + std::to_string(FPSlast), cv::Point(100, 100), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(100, 200, 250));

        cv::imshow("Window", frame);
        if (cv::waitKey(33) >= 0)
            break;
    }
	return 0;
}

