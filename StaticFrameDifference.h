#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>


#include "base.h"

class StaticFrameDifferenceBGS : public Base
{
private:
  bool firstTime;
  cv::Mat img_background;
  cv::Mat img_foreground;
  bool enableThreshold;
  int threshold;
  bool showOutput;

public:
  StaticFrameDifferenceBGS();
  ~StaticFrameDifferenceBGS();

  void process(const cv::Mat &img_input, cv::Mat &img_output, cv::Mat &img_bgmodel);

private:
  void saveConfig();
  void loadConfig();
};

