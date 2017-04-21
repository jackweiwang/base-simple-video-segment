#include "WeightedMovingMean.h"

WeightedMovingMean::WeightedMovingMean() :  enableWeight(true), enableThreshold(true), showBackground(false)
{
  std::cout << "WeightedMovingMean()" << std::endl;
}

WeightedMovingMean::~WeightedMovingMean()
{
  std::cout << "~WeightedMovingMean()" << std::endl;
}

void WeightedMovingMean::process(const cv::Mat &img_input, cv::Mat &img_output, cv::Mat &img_bgmodel)
{
  if(img_input.empty())
    return;

  if(img_input_prev_1.empty())
  {
    img_input.copyTo(img_input_prev_1);
    return;
  }

  if(img_input_prev_2.empty())
  {
    img_input_prev_1.copyTo(img_input_prev_2);
    img_input.copyTo(img_input_prev_1);
    return;
  }
  
  cv::Mat img_input_f(img_input.size(), CV_32F);
  img_input.convertTo(img_input_f, CV_32F, 1./255.);

  cv::Mat img_input_prev_1_f(img_input.size(), CV_32F);
  img_input_prev_1.convertTo(img_input_prev_1_f, CV_32F, 1./255.);

  cv::Mat img_input_prev_2_f(img_input.size(), CV_32F);
  img_input_prev_2.convertTo(img_input_prev_2_f, CV_32F, 1./255.);

  cv::Mat img_background_f(img_input.size(), CV_32F);
  
  if(enableWeight)
    img_background_f = ((img_input_f * 0.5) + (img_input_prev_1_f * 0.3) + (img_input_prev_2_f * 0.2));
  else
    img_background_f = ((img_input_f) + (img_input_prev_1_f) + (img_input_prev_2_f)) / 3.0;

  cv::Mat img_background(img_background_f.size(), CV_8U);

  double minVal, maxVal;
  minVal = 0.; maxVal = 1.;
  img_background_f.convertTo(img_background, CV_8U, 255.0/(maxVal - minVal), -minVal);
  
  if(showBackground)
    cv::imshow("W Moving Mean BG Model", img_background);

  cv::Mat img_foreground;
  cv::absdiff(img_input, img_background, img_foreground);

  if(img_foreground.channels() == 3)
    cv::cvtColor(img_foreground, img_foreground, CV_BGR2GRAY);

  cv::threshold(img_foreground, img_foreground, threshold, 255, cv::THRESH_BINARY);

  cv::imshow("W Moving Mean FG Mask", img_foreground);

  img_foreground.copyTo(img_output);
  img_background.copyTo(img_bgmodel);

  img_input_prev_1.copyTo(img_input_prev_2);
  img_input.copyTo(img_input_prev_1);

}