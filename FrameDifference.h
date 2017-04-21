#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>
#include "base.h"
class FrameDifference : public Base
{
private:
	cv::Mat img_input_prev;
	cv::Mat img_foreground;
	int threshold;

public:
	FrameDifference();
	~FrameDifference();

	void process(const cv::Mat &img_input, cv::Mat &img_output, cv::Mat &img_bgmodel);

};