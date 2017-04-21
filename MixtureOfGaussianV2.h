#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>

#include <opencv2/video/background_segm.hpp>

#include "base.h"

class MixtureOfGaussianV2 : public Base
{
private:
  bool firstTime;
  cv::Ptr<cv::BackgroundSubtractorMOG2> mog;
  cv::Mat img_foreground;
  double alpha;

  int threshold;


public:
  MixtureOfGaussianV2();
  ~MixtureOfGaussianV2();

  void process(const cv::Mat &img_input, cv::Mat &img_output, cv::Mat &img_bgmodel);


};

