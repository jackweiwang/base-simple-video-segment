#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>


#include "base.h"

class AdaptiveSelectiveBackgroundLearning : public Base
{
private:
  bool firstTime;
  cv::Mat img_background;
  double alphaLearn;
  double alphaDetection;
  long learningFrames;
  long counter;
  double minVal;
  double maxVal;
  int threshold;
  bool showOutput;

public:
  AdaptiveSelectiveBackgroundLearning();
  ~AdaptiveSelectiveBackgroundLearning();

  void process(const cv::Mat &img_input, cv::Mat &img_output, cv::Mat &img_bgmodel);

};

