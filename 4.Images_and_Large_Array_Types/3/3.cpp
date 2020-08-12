#include <opencv2/opencv.hpp>
#include <iostream>

template <typename T>
class TypeWriter {
public:
	TypeWriter(){}

	TypeWriter(int cols, int rows) : img(cv::Mat_<T>(cols, rows, T(0))){}

	void Run() {
		cv::namedWindow("TypeWriter", cv::WINDOW_AUTOSIZE);
		for (;;) {
			cv::imshow("TypeWriter", img);
			char c = cv::waitKey(0);
			if (c != 0)
				Print(c);
		}
	}

private:
	cv::Mat_<T> img;
	std::pair<int, int> pos = { 0, 0 };

	void set_position() {
		if (pos.first + 10 >= img.cols) {
			pos.first = 0;
			pos.second = (pos.second + 20) % img.rows;
		}
		else
			pos.first += 10;
	}

	void Print(char num) {
		if (num == '0')
			PrintNull();
		else if (num == '1')
			PrintOne();
		else if (num == '2')
			PrintTwo();
		else if (num == '3')
			PrintThree();
		else if (num == '4')
			PrintFour();
		else if (num == '5')
			PrintFive();
		else if (num == '6')
			PrintSix();
		else if (num == '7')
			PrintSeven();
		else if (num == '8')
			PrintEight();
		else if (num == '9')
			PrintNine();
		else if( num == 'c'){
			clear();
			return;
		}
		set_position();
	}
	
	void PrintNull() {
		for (int x = pos.first+1; x < pos.first + 9; x++) {
			img[pos.second+1][x] = T(255);
			img[pos.second + 18][x] = T(255);
		}
		for (int y = pos.second + 1; y < pos.second + 19; y++) {
			img[y][pos.first+1] = T(255);
			img[y][pos.first + 8] = T(255);
		}
		img[pos.second + 9][pos.first + 4] = T(255);
	}

	void PrintOne() {
		for (int y = pos.second + 1; y < pos.second + 19; y++)
			img[y][pos.first + 4] = T(255);
	}

	void PrintTwo() {
		for (int x = pos.first + 1; x < pos.first + 7; x++) {
			img[pos.second + 1][x] = T(255);
			img[pos.second + 10][x] = T(255);
			img[pos.second + 18][x] = T(255);
		}

		for (int y = pos.second + 1; y < pos.second + 19; y++) {
			if (y < pos.second + 11)
				img[y][pos.first + 6] = T(255);
			else
				img[y][pos.first + 1] = T(255);
		}
	}

	void PrintThree() {
		for (int x = pos.first + 2; x < pos.first + 8; x++) {
			img[pos.second + 1][x] = T(255);
			img[pos.second + 10][x] = T(255);
			img[pos.second + 18][x] = T(255);
		}
		for (int y = pos.second + 1; y < pos.second + 19; y++)
			img[y][pos.first + 7] = T(255);
	}

	void PrintFour() {
		for (int x = pos.first + 1; x < pos.first + 8; x++)
			img[pos.second + 10][x] = T(255);

		for (int y = pos.second + 1; y < pos.second + 19; y++) {
			img[y][pos.first + 7] = T(255);
			if (y < pos.second + 10)
				img[y][pos.first + 1] = T(255);
		}
	}

	void PrintFive() {
		for (int x = pos.first + 2; x < pos.first + 8; x++) {
			img[pos.second + 1][x] = T(255);
			img[pos.second + 10][x] = T(255);
			img[pos.second + 18][x] = T(255);
		}
		for (int y = pos.second + 1; y < pos.second + 19; y++) {
			if (y < pos.second + 11)
				img[y][pos.first + 2] = T(255);
			else
				img[y][pos.first + 7] = T(255);
		}
	}

	void PrintSix() {
		for (int x = pos.first + 1; x < pos.first + 8; x++) {
			img[pos.second + 1][x] = T(255);
			img[pos.second + 10][x] = T(255);
			img[pos.second + 18][x] = T(255);
		}
		for (int y = pos.second + 1; y < pos.second + 19; y++) {
			img[y][pos.first + 1] = T(255);
			if (y > pos.second + 11)
				img[y][pos.first + 7] = T(255);
		}
	}

	void PrintSeven() {
		for (int x = pos.first + 1; x < pos.first + 8; x++)
			img[pos.second + 1][x] = T(255);
		
		for (int y = pos.second + 1; y < pos.second + 19; y++)
			img[y][pos.first + 7] = T(255);
	}

	void PrintEight() {
		for (int x = pos.first + 1; x < pos.first + 9; x++) {
			img[pos.second + 1][x] = T(255);
			img[pos.second + 10][x] = T(255);
			img[pos.second + 18][x] = T(255);
		}
		for (int y = pos.second + 1; y < pos.second + 19; y++) {
			img[y][pos.first + 1] = T(255);
			img[y][pos.first + 8] = T(255);
		}
	}

	void PrintNine() {
		for (int x = pos.first + 1; x < pos.first + 9; x++) {
			img[pos.second + 1][x] = T(255);
			img[pos.second + 10][x] = T(255);
			img[pos.second + 18][x] = T(255);
		}
		for (int y = pos.second + 1; y < pos.second + 19; y++) {
			img[y][pos.first + 8] = T(255);
			if(y < pos.second + 11)
				img[y][pos.first + 1] = T(255);
		}
	}
	void PrintRect() {
		for (int i = pos.second; i < pos.second + 20; i++) {
			for (int j = pos.first; j < pos.first + 10; j++) {
				img[i][j] = T(255);
			}
		}
	}

	void clear() {
		img = cv::Mat_<T>(img.cols, img.rows, T(0));
		pos = { 0, 0 };
	}

};

int main(){
	TypeWriter<uchar> tw(500, 500);
	tw.Run();
	return 0;
}

