#include <iostream>
#include <math.h>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "FrameDifference.h"
#include "WeightedMovingMean.h"
#include "MixtureOfGaussianV2.h"
#include "WeightedMovingMean.h"
#include "WeightedMovingVariance.h"
#include "AdaptiveBackgroundLearning.h"
#include "AdaptiveSelectiveBackgroundLearning.h"
#include "KNN.h"
using namespace cv;
using namespace std;
#define UNDEFINED 0

int main(int argc, char** argv)
{
	VideoCapture cap("03.mp4"); //capture the video from web cam

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the web cam" << endl;
		return -1;
	}

	Base *bas;
	int key = 0;
	Mat img_input;
	//change this function and Change  way 
	bas = new AdaptiveBackgroundLearning;
	while (1)
	{
		cap >> img_input;
		if (img_input.empty()) break;

		cv::imshow("input", img_input);

		cv::Mat img_mask;
		cv::Mat img_bkgmodel;
		bas->process(img_input, img_mask, img_bkgmodel); // by default, it shows automatically the foreground mask image
										
		key = cvWaitKey(33);
	}

	return 0;

}