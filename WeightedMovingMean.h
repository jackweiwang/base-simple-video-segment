#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>

#include "base.h"

class WeightedMovingMean : public Base
{
private:

  cv::Mat img_input_prev_1;
  cv::Mat img_input_prev_2;
  bool enableWeight;
  bool enableThreshold;
  int threshold;
  bool showBackground;

public:
  WeightedMovingMean();
  ~WeightedMovingMean();

  void process(const cv::Mat &img_input, cv::Mat &img_output, cv::Mat &img_bgmodel);

};

