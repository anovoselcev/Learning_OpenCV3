// 9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <opencv2/opencv.hpp>

int g_slider_position = 0;
int g_discret = 0;
cv::VideoCapture cap;

void onTrackbarSlide(int pos, void*) {
    cap.set(cv::CAP_PROP_POS_FRAMES, pos);
    g_discret = pos;
}

int main(){
    cv::namedWindow("Task2", cv::WINDOW_NORMAL);
    cap.open(0);
    cv::createTrackbar("Position", "Task2", &g_slider_position, 7, onTrackbarSlide);
    cv::Mat img1, img2;
    
    for (;;) {
        cap >> img1;
        cv::setTrackbarPos("Position", "Task2", g_discret);
        cv::Mat tmp = img1;
        for (int i = 0; i <= g_discret; ++i) {
            cv::pyrDown(tmp, img2);
            tmp = img2;
        }
        cv::imshow("Task2", img2);
        char c = cv::waitKey(10);
        if (c == 27)
            break;
    }
    cap.release();
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
