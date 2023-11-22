Green Screen Effect with OpenCV
This repository contains a C++ script that demonstrates how to create a green screen effect using OpenCV. The script captures live video from a webcam, identifies the green background, and replaces it with a specified background image. This README explains how to compile and run the script.

Prerequisites
Before you begin, ensure you have the following installed:

CMake (version 3.10 or higher)
OpenCV (version 4.x)
A C++ compiler (GCC or Clang)
Installation
Clone the Repository

Use Git to clone the repository to your local machine:

bash
Copy code
git clone [URL to the repository]
Install OpenCV

If you haven't installed OpenCV, you can do so using the following command (for Ubuntu):

bash
Copy code
sudo apt-get install libopencv-dev
Compilation
Create a Build Directory

Navigate to the cloned repository and create a new directory for the build:

bash
Copy code
cd [repository-name]
mkdir build && cd build
Run CMake

From the build directory, run CMake to generate the Makefile:

bash
Copy code
cmake ..
Compile the Code

Compile the code using the generated Makefile:

bash
Copy code
make
Usage
Run the Script

After compilation, you can run the script:

bash
Copy code
./[executable-name]
Provide a Background Image

Place the image you want to use as the background in the same directory as the script, or update the path in the code accordingly:

cpp
Copy code
cv::Mat background = cv::imread("[path-to-your-background-image]");
Script Overview
The script opens the default camera and captures live video frames.
It converts the captured frames to HSV color space for better color detection.
The script then identifies green areas in the frame and replaces them with the specified background image.
You can adjust the range of the green color detected by changing the lowerGreen and upperGreen scalar values.
Exiting the Program
Press the ESC key to exit the program.
Contributions
Contributions to this project are welcome. Please ensure to follow the project's coding style and submit a pull request for review.

Feel free to open an issue if you encounter any problems or have suggestions for improvements.

Happy coding!
