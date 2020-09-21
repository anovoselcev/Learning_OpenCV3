#include <opencv2/opencv.hpp>
#include <iostream>

class MultyTracbar{
public:

	MultyTracbar() = default;

	MultyTracbar(std::string name){
		cap_.open(name);
	}

	void Run(){
		cv::createTrackbar("Position", "Window", &pos_one_, cap_.get(cv::CAP_PROP_FRAME_COUNT) / 10, &MultyTracbar::TrackEvent1, this);
		cv::createTrackbar("Pause", "Window", &pos_second, 1, &MultyTracbar::TrackEvent2, this);
		cv::Mat img;
		for (;;) {
			if (!discret_second && cap_.get(cv::CAP_PROP_FRAME_COUNT) > cap_.get(cv::CAP_PROP_POS_FRAMES)) {
				cap_ >> img;
				cv::setTrackbarPos("Position", "Window", cap_.get(cv::CAP_PROP_POS_FRAMES) / 10);
			}
			cv::imshow("Window", img);
			char c = cv::waitKey(10);
			if (c == 27)
				break;
		}
		cap_.release();
	}

	static void TrackEvent1(int pos, void* ptr){
		auto sample = static_cast<MultyTracbar*>(ptr);
		if (sample->GetCapture().get(cv::CAP_PROP_FRAME_COUNT) > pos * 10) {
			sample->GetCapture().set(cv::CAP_PROP_POS_FRAMES, pos * 10);
			sample->GetDiscretOne() = pos;
		}
	}

	static void TrackEvent2(int pos, void* ptr){
		auto sample = static_cast<MultyTracbar*>(ptr);
		sample->GetDiscretSecond() = pos;
	}

	int& GetPosOne() { return pos_one_; }

	int& GetPosSecond() { return pos_second; }

	int& GetDiscretOne() { return discret_one; }

	int& GetDiscretSecond() { return discret_second; }

	cv::VideoCapture& GetCapture() { return cap_; }

protected:
	cv::VideoCapture cap_;
	int pos_one_	   = 0,
		pos_second	   = 0,
		discret_one	   = 0,
		discret_second = 0;
};


int main() {
	cv::namedWindow("Window");
	MultyTracbar mt("../../video1.mp4");
	mt.Run();
	
	return 0;
}

