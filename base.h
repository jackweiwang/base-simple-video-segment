#pragma once
#define _CRT_SECURE_NO_WARNNINGS
#include <opencv2/opencv.hpp>

class Base
{
public:
	virtual void process(const cv::Mat &img_input, cv::Mat &img_foreground, cv::Mat &img_background) = 0;
	
	virtual ~Base() {}

};
