// 8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <opencv2/opencv.hpp>

int main(){
    cv::namedWindow("Example8", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Log_Polar", cv::WINDOW_AUTOSIZE);
    cv::VideoCapture capture(0);
    double fps = capture.get(cv::CAP_PROP_FPS);
    cv::Size size(capture.get(cv::CAP_PROP_FRAME_WIDTH),
        capture.get(cv::CAP_PROP_FRAME_HEIGHT));
    cv::VideoWriter writer;
    writer.open("Out.MJPG", cv::VideoWriter::fourcc('M','J','P','G'), fps, size);
    cv::Mat logpolar_frame, bgr_frame;
    for (;;) {
        capture >> bgr_frame;
         if (bgr_frame.empty())
            break;
        cv::imshow("Example8", bgr_frame);
        cv::logPolar(bgr_frame, logpolar_frame, cv::Point2f(bgr_frame.cols / 2, bgr_frame.rows / 2), 40, cv::WARP_FILL_OUTLIERS);
        cv::imshow("Log_Polar", logpolar_frame);
        writer << logpolar_frame;
        char c = cv::waitKey(10);
        if (c == 27)
            break;
    }
    capture.release();
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
