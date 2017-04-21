#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>

#include <opencv2/video/background_segm.hpp>

#include "base.h"

class KNN : public Base
{
private:
  bool firstTime;
  cv::Ptr<cv::BackgroundSubtractorKNN> knn;
  int history;
  int nSamples;
  float dist2Threshold;
  int knnSamples;
  bool doShadowDetection;
  int shadowValue;
  float shadowThreshold;
  bool showOutput;

public:
  KNN();
  ~KNN();

  void process(const cv::Mat &img_input, cv::Mat &img_output, cv::Mat &img_bgmodel);

};

