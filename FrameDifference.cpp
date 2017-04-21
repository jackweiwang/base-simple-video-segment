
#include "FrameDifference.h"

FrameDifference::FrameDifference() : threshold(15)
{
	std::cout << "FrameDifference()" << std::endl;
}

FrameDifference::~FrameDifference()
{
	std::cout << "~FrameDifference()" << std::endl;
}

void FrameDifference::process(const cv::Mat &img_input, cv::Mat &img_output, cv::Mat &img_bgmodel)
{
	if (img_input.empty())
		return;

	if (img_input_prev.empty())
	{
		img_input.copyTo(img_input_prev);
		return;
	}

	cv::absdiff(img_input_prev, img_input, img_foreground);

	if (img_foreground.channels() == 3)
		cv::cvtColor(img_foreground, img_foreground, CV_BGR2GRAY);

	cv::threshold(img_foreground, img_foreground, threshold, 255, cv::THRESH_BINARY);

	cv::imshow("Frame Difference", img_foreground);

	img_foreground.copyTo(img_output);

	img_input.copyTo(img_input_prev);

}

