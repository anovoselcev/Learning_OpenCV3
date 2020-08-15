#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

template <typename T>
class TypeWriter {
public:
	TypeWriter(){}

	TypeWriter(int cols, int rows) : img_c1(cv::Mat_<T>(cols, rows, T(0))),
		img_c3(cv::Mat::zeros(cols, rows, CV_8UC3)) {
		table.resize(rows/20);
		for (auto& x : table) {
			x.resize(cols/10);
			x = std::vector<short>(cols / 10, -1);
		}
		colours.resize(10);
		colours[0] = { 0, 230, 255 };
		colours[1] = { 0, 180, 255 };
		colours[2] = { 0, 140, 255 };
		colours[3] = { 130, 255, 0 };
		colours[4] = { 180, 255, 0 };
		colours[5] = { 220, 255, 0 };
		colours[6] = { 255, 0, 160 };
		colours[7] = { 255, 0, 200 };
		colours[8] = { 255, 0, 230 };
		colours[9] = { 210, 240, 120 };
	}

	void Run() {
		cv::namedWindow("TypeWriter", cv::WINDOW_AUTOSIZE);
		for (;;) {
			if (!is_colour)
				cv::imshow("TypeWriter", img_c1);
			else
				cv::imshow("TypeWriter", img_c3);
			char c = cv::waitKey(0);
			if (c != 0)
				Print(c);
		}
	}

private:
	cv::Mat_<T> img_c1;
	cv::Mat img_c3;
	std::vector<std::vector<short>> table;
	bool is_colour = false;
	std::vector<cv::Vec3b> colours;
	
	std::pair<int, int> pos = { 0, 0 };

	void set_position() {
		if (pos.first + 10 >= img_c1.cols) {
			pos.first = 0;
			pos.second = (pos.second + 20) % img_c1.rows;
		}
		else
			pos.first += 10;
	}

	void restore_position() {
		if (pos.first == 0) {
			if (pos.second != 0) {
				pos.first = img_c1.cols - 10;
				pos.second -= 20;
			}
		}
		else {
			pos.first -= 10;
		}
		PrintRect();
	}

	void Up() {
		if (pos.second != 0)
			pos.second -= 20;
	}

	void Down() {
		if (pos.second != img_c1.rows - 20)
			pos.second += 20;
	}

	void Left() {
		if (pos.first != 0)
			pos.first -= 10;
	}

	void Right() {
		if (pos.first != img_c1.cols - 10)
			pos.first += 10;
	}

	void PrintNumber(char num) {
		bool action = false;
		if (num == '0')
			action = PrintNull();
		else if (num == '1')
			action = PrintOne();
		else if (num == '2')
			action = PrintTwo();
		else if (num == '3')
			action = PrintThree();
		else if (num == '4')
			action = PrintFour();
		else if (num == '5')
			action = PrintFive();
		else if (num == '6')
			action = PrintSix();
		else if (num == '7')
			action = PrintSeven();
		else if (num == '8')
			action = PrintEight();
		else if (num == '9')
			action = PrintNine();
		else if (num == ' ')
			action = true;
		else if (num == 'r')
			colour();
		if (action)
			set_position();
	}

	void Print(char num) {
		PrintNumber(num);
		if (num == 'w')
			Up();
		else if (num == 's')
			Down();
		else if (num == 'a')
			Left();
		else if (num == 'd')
			Right();
		else if( num == 'c'){
			clear();
			return;
		}
		else if (num == 8)
			restore_position();
	}
	
	bool PrintNull() {
		for (int x = pos.first+1; x < pos.first + 9; x++) {
			if (!is_colour) {
				img_c1[pos.second + 1][x] = T(255);
				img_c1[pos.second + 18][x] = T(255);
			}
			else {
				img_c3.at<cv::Vec3b>(pos.second + 1, x) = colours[0];
				img_c3.at<cv::Vec3b>(pos.second + 18, x) = colours[0];
			}
		}
		for (int y = pos.second + 1; y < pos.second + 19; y++) {
			if (!is_colour) {
				img_c1[y][pos.first + 1] = T(255);
				img_c1[y][pos.first + 8] = T(255);
			}
			else {
				img_c3.at<cv::Vec3b>(y, pos.first + 1) = colours[0];
				img_c3.at<cv::Vec3b>(y, pos.first + 8) = colours[0];
			}
		}
		if(!is_colour)
			img_c1[pos.second + 9][pos.first + 4] = T(255);
		else
			img_c3.at<cv::Vec3b>(pos.second + 9, pos.first + 4) = colours[0];
		table[pos.second / 20][pos.first / 10] = 0;
		return true;
	}

	bool PrintOne() {
		for (int y = pos.second + 1; y < pos.second + 19; y++) {
			if(!is_colour)
				img_c1[y][pos.first + 4] = T(255);
			else
				img_c3.at<cv::Vec3b>(y, pos.first + 4) = colours[1];
		}
		table[pos.second / 20][pos.first / 10] = 1;
		return true;
	}

	bool PrintTwo() {
		for (int x = pos.first + 1; x < pos.first + 7; x++) {
			if (!is_colour) {
				img_c1[pos.second + 1][x] = T(255);
				img_c1[pos.second + 10][x] = T(255);
				img_c1[pos.second + 18][x] = T(255);
			}
			else {
				img_c3.at<cv::Vec3b>(pos.second + 1, x) = colours[2];
				img_c3.at<cv::Vec3b>(pos.second + 10, x) = colours[2];
				img_c3.at<cv::Vec3b>(pos.second + 18, x) = colours[2];
			}
		}

		for (int y = pos.second + 1; y < pos.second + 19; y++) {
			if (y < pos.second + 11) {
				if(!is_colour)
					img_c1[y][pos.first + 6] = T(255);
				else
					img_c3.at<cv::Vec3b>(y, pos.first + 6) = colours[2];
			}
			else {
				if(!is_colour)
					img_c1[y][pos.first + 1] = T(255);
				else
					img_c3.at<cv::Vec3b>(y, pos.first + 1) = colours[2];
			}
		}
		table[pos.second / 20][pos.first / 10] = 2;
		return true;
	}

	bool PrintThree() {
		for (int x = pos.first + 2; x < pos.first + 8; x++) {
			if (!is_colour) {
				img_c1[pos.second + 1][x] = T(255);
				img_c1[pos.second + 10][x] = T(255);
				img_c1[pos.second + 18][x] = T(255);
			}
			else {
				img_c3.at<cv::Vec3b>(pos.second + 1, x) = colours[3];
				img_c3.at<cv::Vec3b>(pos.second + 10, x) = colours[3];
				img_c3.at<cv::Vec3b>(pos.second + 18, x) = colours[3];
			}
		}
		for (int y = pos.second + 1; y < pos.second + 19; y++) {
			if (!is_colour)
				img_c1[y][pos.first + 7] = T(255);
			else
				img_c3.at<cv::Vec3b>(y, pos.first + 7) = colours[3];
		}
		table[pos.second / 20][pos.first / 10] = 3;
		return true;
	}

	bool PrintFour() {
		for (int x = pos.first + 1; x < pos.first + 8; x++) {
			if (!is_colour)
				img_c1[pos.second + 10][x] = T(255);
			else
				img_c3.at<cv::Vec3b>(pos.second + 10, x) = colours[4];
		}

		for (int y = pos.second + 1; y < pos.second + 19; y++) {
			if (!is_colour) {
				img_c1[y][pos.first + 7] = T(255);
				if (y < pos.second + 10)
					img_c1[y][pos.first + 1] = T(255);
			}
			else {
				img_c3.at<cv::Vec3b>(y, pos.first + 7) = colours[4];
				if (y < pos.second + 10)
					img_c3.at<cv::Vec3b>(y, pos.first + 1) = colours[4];
			}
		}
		table[pos.second / 20][pos.first / 10] = 4;
		return true;
	}

	bool PrintFive() {
		for (int x = pos.first + 2; x < pos.first + 8; x++) {
			if (!is_colour) {
				img_c1[pos.second + 1][x] = T(255);
				img_c1[pos.second + 10][x] = T(255);
				img_c1[pos.second + 18][x] = T(255);
			}
			else {
				img_c3.at<cv::Vec3b>(pos.second + 1, x) = colours[5];
				img_c3.at<cv::Vec3b>(pos.second + 10, x) = colours[5];
				img_c3.at<cv::Vec3b>(pos.second + 18, x) = colours[5];
			}
		}
		for (int y = pos.second + 1; y < pos.second + 19; y++) {
			if (!is_colour) {
				if (y < pos.second + 11)
					img_c1[y][pos.first + 2] = T(255);
				else
					img_c1[y][pos.first + 7] = T(255);
			}
			else {
				if (y < pos.second + 11)
					img_c3.at<cv::Vec3b>(y, pos.first + 2) = colours[5];
				else
					img_c3.at<cv::Vec3b>(y, pos.first + 7) = colours[5];
			}
		}
		table[pos.second / 20][pos.first / 10] = 5;
		return true;
	}

	bool PrintSix() {
		for (int x = pos.first + 1; x < pos.first + 8; x++) {
			if (!is_colour) {
				img_c1[pos.second + 1][x] = T(255);
				img_c1[pos.second + 10][x] = T(255);
				img_c1[pos.second + 18][x] = T(255);
			}
			else {
				img_c3.at<cv::Vec3b>(pos.second + 1, x) = colours[6];
				img_c3.at<cv::Vec3b>(pos.second + 10, x) = colours[6];
				img_c3.at<cv::Vec3b>(pos.second + 18, x) = colours[6];
			}
		}
		for (int y = pos.second + 1; y < pos.second + 19; y++) {
			if (!is_colour) {
				img_c1[y][pos.first + 1] = T(255);
				if (y > pos.second + 11)
					img_c1[y][pos.first + 7] = T(255);
			}
			else {
				img_c3.at<cv::Vec3b>(y, pos.first + 1) = colours[6];
				if (y > pos.second + 11)
					img_c3.at<cv::Vec3b>(y, pos.first + 7) = colours[6];
			}
		}
		table[pos.second / 20][pos.first / 10] = 6;
		return true;
	}

	bool PrintSeven() {
		for (int x = pos.first + 1; x < pos.first + 8; x++) {
			if (!is_colour)
				img_c1[pos.second + 1][x] = T(255);
			else
				img_c3.at<cv::Vec3b>(pos.second + 1, x) = colours[7];
		}
		
		for (int y = pos.second + 1; y < pos.second + 19; y++) {
			if (!is_colour)
				img_c1[y][pos.first + 7] = T(255);
			else
				img_c3.at<cv::Vec3b>(y, pos.first + 7) = colours[7];
		}
		table[pos.second / 20][pos.first / 10] = 7;
		return true;
	}

	bool PrintEight() {
		for (int x = pos.first + 1; x < pos.first + 9; x++) {
			if (!is_colour) {
				img_c1[pos.second + 1][x] = T(255);
				img_c1[pos.second + 10][x] = T(255);
				img_c1[pos.second + 18][x] = T(255);
			}
			else {
				img_c3.at<cv::Vec3b>(pos.second + 1, x) = colours[8];
				img_c3.at<cv::Vec3b>(pos.second + 10, x) = colours[8];
				img_c3.at<cv::Vec3b>(pos.second + 18, x) = colours[8];
			}
		}
		for (int y = pos.second + 1; y < pos.second + 19; y++) {
			if (!is_colour) {
				img_c1[y][pos.first + 1] = T(255);
				img_c1[y][pos.first + 8] = T(255);
			}
			else {
				img_c3.at<cv::Vec3b>(y, pos.first + 1) = colours[8];
				img_c3.at<cv::Vec3b>(y, pos.first + 8) = colours[8];
			}
		}
		table[pos.second / 20][pos.first / 10] = 8;
		return true;
	}

	bool PrintNine() {
		for (int x = pos.first + 1; x < pos.first + 9; x++) {
			if (!is_colour) {
				img_c1[pos.second + 1][x] = T(255);
				img_c1[pos.second + 10][x] = T(255);
				img_c1[pos.second + 18][x] = T(255);
			}
			else {
				img_c3.at<cv::Vec3b>(pos.second + 1, x) = colours[9];
				img_c3.at<cv::Vec3b>(pos.second + 10, x) = colours[9];
				img_c3.at<cv::Vec3b>(pos.second + 18, x) = colours[9];
			}
		}
		for (int y = pos.second + 1; y < pos.second + 19; y++) {
			if (!is_colour) {
				img_c1[y][pos.first + 8] = T(255);
				if (y < pos.second + 11)
					img_c1[y][pos.first + 1] = T(255);
			}
			else {
				img_c3.at<cv::Vec3b>(y, pos.first + 8) = colours[9];
				if (y < pos.second + 11)
					img_c3.at<cv::Vec3b>(y, pos.first + 1) = colours[9];
			}
		}
		table[pos.second / 20][pos.first / 10] = 9;
		return true;
	}
	void PrintRect() {
		for (int i = pos.second; i < pos.second + 20; i++) {
			for (int j = pos.first; j < pos.first + 10; j++) {
				if (!is_colour)
					img_c1[i][j] = T(0);
				else
					img_c3.at<cv::Vec3b>(i, j) = { 0,0,0 };
			}
		}
		table[pos.second / 20][pos.first / 10] = -1;
	}

	void clear() {
		img_c1 = cv::Mat_<T>(img_c1.cols, img_c1.rows, T(0));
		img_c3 = cv::Mat::zeros(img_c3.cols, img_c3.rows, CV_8UC3);
		pos = { 0, 0 };
		clear_table();
	}

	void clear_table() {
		for (auto& x : table) 
			x = std::vector<short>(img_c1.cols/10, -1);
	}

	void colour() {
		if (!is_colour)
			is_colour = true;
		else
			is_colour = false;
		std::pair<int, int> pos_last = pos;
		pos = { 0,0 };
		for (int i = 0; i < img_c1.rows/20; i++) {
			for (int j = 0; j < img_c1.cols / 10; j++) {
				short value = table[i][j];
				if (value >=0 && value <= 9)
					PrintNumber('0' + value);
				else if (value == -1) {
					PrintRect();
					set_position();
				}
			}
		}
		pos = pos_last;
	}

};

int main(){
	TypeWriter<uchar> tw(500, 500);
	tw.Run();
	return 0;
}

