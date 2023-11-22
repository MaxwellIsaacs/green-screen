# Green Screen with OpenCV

This repository contains a C++ script that demonstrates how to create a green screen effect using OpenCV. The script captures live video from a webcam, identifies the green background, and replaces it with a specified background image. This README explains how to compile and run the script.

## Prerequisites

Before you begin, ensure you have the following installed:

- OpenCV (version 4.x)
- A C++ compiler (GCC or Clang)

### Clone the Repository

Use Git to clone the repository to your local machine:

```bash
git clone https://github.com/MaxwellIsaacs/green-screen/tree/main
```

### Compile the Script
To compile the script, use the following command in your terminal:
```bash
g++ -std=c++11 -o [EXECUTABLE-NAME] greenscreen.cpp -I/usr/local/Cellar/opencv/4.8.1_4/include/opencv4 \
-L/usr/local/Cellar/opencv/4.8.1_4/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio
```

## Usage
- **Run the Script**: `./[executable-name]`
- **Background Image**: Place your background image in the script's directory or update the path in the script: 
  `cv::Mat background = cv::imread("[path-to-your-background-image]");`

## Script Details
- Captures live video frames.
- Converts frames to HSV for color detection.
- Replaces green areas with a background image.
- Exit with the ESC key.



Happy coding

