// 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int g_slider_position = 0;
int g_run = 1;
int g_dontset = 0;
cv::VideoCapture g_cap;

void onTrackbarSlide(int pos, void*) {
    g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
    if (!g_dontset)
        g_run = 1;
    g_dontset = 0;
}

int main(){
    cv::namedWindow("Example3", cv::WINDOW_AUTOSIZE);
    g_cap.open("../../video1.MP4");
    int frames = g_cap.get(cv::CAP_PROP_FRAME_COUNT);
    int tmpw = g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int tmph = g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    std::cout << "В виде " << frames << " кадров размером("
        << tmpw << ", " << tmph << ")." << std::endl;
    cv::createTrackbar("Position", "Example3", &g_slider_position, frames, onTrackbarSlide);
    cv::Mat frame;
    for (;;) {
        if (g_run != 0) {
            g_cap >> frame;
            if (frame.empty())
                break;
            int current_pos = g_cap.get(cv::CAP_PROP_POS_FRAMES);
            g_dontset = 1;
            cv::setTrackbarPos("Position", "Example3", current_pos);
            cv::imshow("Example3", frame);
            g_run -= 1;
        }
        char c = cv::waitKey(10);
        if (c == 's') {
            g_run = 1;
            std::cout << "Покадровый режим, run = " << g_run << std::endl;
        }
        if (c == 'r') {
            g_run = -1;
            std::cout << "Непрерывный режим, run = " << g_run << std::endl;
        }
        if (c == 27)
            break;
    }
    cv::destroyWindow("Example3");
    return 0;
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
