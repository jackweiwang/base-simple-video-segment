#include "MixtureOfGaussianV2.h"

MixtureOfGaussianV2::MixtureOfGaussianV2() : firstTime(true), alpha(0.05), threshold(15)
{
  std::cout << "MixtureOfGaussianV2()" << std::endl;
}

MixtureOfGaussianV2::~MixtureOfGaussianV2()
{
  std::cout << "~MixtureOfGaussianV2()" << std::endl;
}

void MixtureOfGaussianV2::process(const cv::Mat &img_input, cv::Mat &img_output, cv::Mat &img_bgmodel)
{
  if(img_input.empty())
    return;

  if (firstTime) {
	  mog = cv::createBackgroundSubtractorMOG2();
  }
  
  mog->apply(img_input, img_foreground, alpha);
  
  cv::Mat img_background;
  mog->getBackgroundImage(img_background);

  cv::threshold(img_foreground, img_foreground, threshold, 255, cv::THRESH_BINARY);

  cv::imshow("GMM (Zivkovic&Heijden)", img_foreground);
  cv::imshow("GMM BKG (Zivkovic&Heijden)", img_background);
  
  img_foreground.copyTo(img_output);
  img_background.copyTo(img_bgmodel);

  firstTime = false;
}

