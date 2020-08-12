// 6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <opencv2/opencv.hpp>
#include <iostream>

int main() {

	cv::Mat img_rgb, img_gry, img_cny, img_pyr, img_pyr2;

	cv::namedWindow("Example Gray", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example Canny", cv::WINDOW_AUTOSIZE);

	img_rgb = cv::imread("../../image1.png");

	cv::cvtColor(img_rgb, img_gry, cv::COLOR_BGR2GRAY);

	cv::pyrDown(img_gry, img_pyr);
	cv::pyrDown(img_pyr, img_pyr2);

	cv::Canny(img_pyr2, img_cny, 10, 100, 3, true);

	int x = 16, y = 32;
	cv::Vec3b intensity = img_rgb.at< cv::Vec3b >(y, x);

	uchar blue = intensity[0];
	uchar green = intensity[1];
	uchar red = intensity[2];

	std::cout << "At (x,y) = (" << x << ", " << y <<
		"): (blue, green, red) = (" <<
		(unsigned int)blue <<
		", " << (unsigned int)green << ", " <<
		(unsigned int)red << ")" << std::endl;

	std::cout << "Gray pixel there is: " <<
		(unsigned int)img_gry.at<uchar>(y, x) << std::endl;

	x /= 4; y /= 4;

	std::cout << "Pyramid2 pixel there is: " <<
		(unsigned int)img_pyr2.at<uchar>(y, x) << std::endl;

	img_cny.at<uchar>(x, y) = 128;

	cv::imshow("Example Gray", img_gry);
	cv::imshow("Example Canny", img_cny);

	cv::waitKey(0);

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
