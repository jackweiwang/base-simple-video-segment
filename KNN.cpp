#include "KNN.h"

KNN::KNN() :
		firstTime(true), history(500), nSamples(7),
		dist2Threshold(20.0f * 20.0f), knnSamples(0), doShadowDetection(true),
		shadowValue(127), shadowThreshold(0.5f), showOutput(true)
{
	std::cout << "KNNBGS()" << std::endl;
}

KNN::~KNN()
{
	std::cout << "~KNNBGS()" << std::endl;
}

void KNN::process(const cv::Mat &img_input, cv::Mat &img_output, cv::Mat &img_bgmodel)
{
	if (img_input.empty())
		return;

	int prevNSamples = nSamples;

	if (firstTime) {
		knn = cv::createBackgroundSubtractorKNN(history, dist2Threshold, doShadowDetection);
	}

	knn->setNSamples(nSamples);
	knn->setkNNSamples(knnSamples);
	knn->setShadowValue(shadowValue);
	knn->setShadowThreshold(shadowThreshold);

	knn->apply(img_input, img_output, prevNSamples != nSamples ? 0.f : 1.f);
	knn->getBackgroundImage(img_bgmodel);

	if (showOutput) {
		if (!img_output.empty())
			cv::imshow("KNN FG", img_output);

		if (!img_bgmodel.empty())
			cv::imshow("KNN BG", img_bgmodel);
	}

	firstTime = false;
}

