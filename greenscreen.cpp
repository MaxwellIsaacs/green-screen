#include <opencv2/opencv.hpp>
//he
int main() {
    /**
    * @brief Load the background image.
    * @param background Path to the background image.
    */
    cv::Mat background = cv::imread("[YOUR-IMAGE-PATH]");
    if (background.empty()) {
        std::cerr << "Error: Unable to load background image" << std::endl;
        return -1;
    } // test

    /**
    * @brief Open the default camera.
    * @param cap Video capture object.
    */
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error: Unable to open the camera" << std::endl;
        return -1;
    }

    cv::Mat frame, hsvFrame, mask, maskedFrame, result;
    while (true) {
        /**
        * @brief Capture a new frame from the camera.
        */
        cap >> frame;
        if (frame.empty()) break; // Check if the frame is valid

        /**
        * @brief Resize the background to match the frame size.
        */
        cv::resize(background, background, frame.size());

        /**
        * @brief Convert the frame to HSV color space for better color detection.
        */
        cv::cvtColor(frame, hsvFrame, cv::COLOR_BGR2HSV);

        /**
        * @brief Define the range of green color in HSV.
        * @param lowerGreen Lower bound of the green color.
        * @param upperGreen Upper bound of the green color.
        */
        cv::Scalar lowerGreen(35, 50, 50); // You may need to adjust these values
        cv::Scalar upperGreen(85, 255, 255); // depending on your green screen

        /**
        * @brief Create a mask to identify green areas in the frame.
        */
        cv::inRange(hsvFrame, lowerGreen, upperGreen, mask);

        /**
        * @brief Create an inverse mask for non-green areas.
        */
        cv::Mat inverseMask = ~mask;

        /**
        * @brief Extract the non-green areas (foreground) from the frame.
        */
        cv::bitwise_and(frame, frame, maskedFrame, inverseMask);

        /**
        * @brief Extract the green areas (background) from the background image.
        */
        cv::Mat backgroundArea;
        cv::bitwise_and(background, background, backgroundArea, mask);

        /**
        * @brief Combine the foreground with the new background.
        */
        cv::add(maskedFrame, backgroundArea, result);

        /**
        * @brief Display the resulting frame with the green screen effect.
        */
        cv::imshow("Green Screen Effect", result);

        /**
        * @brief Exit the loop if the ESC key is pressed.
        */
        if (cv::waitKey(10) == 27) break;
    }

    /**
    * @brief Release the video capture object and close all OpenCV windows.
    */
    cap.release();
    cv::destroyAllWindows();

    return 0;
}
