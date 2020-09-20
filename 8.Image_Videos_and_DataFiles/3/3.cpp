#include <opencv2/opencv.hpp>

class ImageDrawer{
public:

	ImageDrawer() = default;

	ImageDrawer(std::string name){
		origin = cv::imread(name);
		tmp = origin.clone();
		gysto.resize(3);
		for (auto& gyst : gysto)
			gyst = cv::Mat::zeros(500, 700, origin.type());
	}

	static void MousePressEvent(
		int event,
		int x,
		int y,
		int flags,
		void* userdata){
		
		auto sample  = static_cast<ImageDrawer*>(userdata);
		
		auto& start = sample->GetStart();
		
		if (event == cv::EVENT_LBUTTONDOWN) {
			start = cv::Point2d(x, y);
		}
		else if (event == cv::EVENT_MOUSEMOVE && flags == 1) {
			sample->Restore();
			auto rect = sample->PrepareRect(x, y);
			cv::rectangle(sample->GetTMP(), rect, cv::Scalar(100, 100, 240));
			
		}
		else if (event == cv::EVENT_LBUTTONUP) {
		}
	}

	cv::Mat& GetTMP() { return tmp; }

	void Restore(){
		tmp = origin.clone();
	}

	cv::Point2d& GetStart() { return start; }

	cv::Mat& GetGysto(int i) { return gysto[i]; }

	cv::Rect PrepareRect(int x, int y){
		cv::Rect result;
		if (x > start.x && y < start.y)
			result = cv::Rect(start.x, y, x - start.x, start.y - y);
		else if (x < start.x && y > start.y)
			result = cv::Rect(x, start.y, start.x - x, y - start.y);
		else if (x < start.x && y < start.y)
			result = cv::Rect(x, y, start.x - x, start.y - y);
		else
			result = cv::Rect(start.x, start.y, x - start.x, y - start.y);
		SetGysto(result);
		return result;
	}
	
private:

	void ClearGysto(){
		for (auto& gyst : gysto)
			gyst = cv::Mat::zeros(500, 700, origin.type());
	}
	
	void SetGysto(cv::Rect rect){
		ClearGysto();
		for (uint8_t num = 0; num < 3; ++num) {
			std::vector<uint32_t> count(8,0);
			for (uint32_t x = rect.x; x < rect.x + rect.width; ++x) {
				for (uint32_t y = rect.y; y < rect.y + rect.height; ++y)
					count[origin.at<cv::Vec3b>(y, x)[num] / 32]++;
			}
			PrintGysto(count, num);
		}
		cv::imshow("GistoBlue", gysto[0]);
		cv::imshow("GistoGreen", gysto[1]);
		cv::imshow("GistoRed", gysto[2]);
	}

	void PrintGysto(const std::vector<uint32_t>& vec, uint8_t num){
		cv::Scalar color = {0,0,0};
		color[num] = 255;
		uint32_t max = *std::max_element(vec.begin(), vec.end());
		if (!max) max = 1;
		for (uint8_t i = 0; i < 8; ++i) 
			cv::rectangle(gysto[num], cv::Point(50 * (i + 3), 450), cv::Point(50 * (i + 4), 450 -  vec[i] * 400/max), color);
		cv::putText(gysto[num], "Max = " + std::to_string(max), cv::Point(5, 50), cv::FONT_HERSHEY_COMPLEX, 0.4, color);
		cv::putText(gysto[num], "Half = " + std::to_string(max/2), cv::Point(5, 250), cv::FONT_HERSHEY_COMPLEX, 0.4, color);
		cv::putText(gysto[num], "Quarter = " + std::to_string(max /4), cv::Point(5, 350), cv::FONT_HERSHEY_COMPLEX, 0.4, color);
	}
	
	cv::Mat origin;
	cv::Mat tmp;
	std::vector<cv::Mat> gysto;
	cv::Point2d start;
};


int main() {
	ImageDrawer imgd("../../image3.png");
	cv::namedWindow("Window");
	cv::namedWindow("GistoRed");
	cv::namedWindow("GistoBlue");
	cv::namedWindow("GistoGreen");
	cv::setMouseCallback("Window", &ImageDrawer::MousePressEvent, &imgd);
	char key = '1';
	while (key != 'e') {
		cv::imshow("Window", imgd.GetTMP());
		key = cv::waitKey(33);
	}
	return 0;
}

