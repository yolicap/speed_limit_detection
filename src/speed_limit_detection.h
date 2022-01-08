#ifndef SPEED_LIMIT_DETECTION_H
#define SPEED_LIMIT_DETECTION_H

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

#include <opencv2/opencv.hpp>
using namespace cv;

int * detectSpeedLimit();

#endif
