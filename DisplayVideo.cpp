#include "opencv2/opencv.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "\n\n\tusage: <application name> <Video File Path> \n\n" << std::endl;

        return -1;
    }

    std::cout << "\n\tVideo file path: " << argv[1] << std::endl;

    cv::VideoCapture v_cap;

    v_cap.open(argv[1]);

    if (!v_cap.isOpened())
    {
        std::cout << "\n\n\tError openning video :(\n\n" << std::endl;

        return -1;
    }

    while(1)
    {
        cv::Mat v_frame;

        v_cap >> v_frame;

        if (v_frame.empty())
        {
            break;
        }

        cv::imshow("Frame", v_frame);
        char c = (char)cv::waitKey(25);

        if (c == 27)
        {
            break;
        }
    };

    v_cap.release();
    cv::destroyAllWindows();

    return 0;
}