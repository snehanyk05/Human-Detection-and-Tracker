/**
 * Copyright 2020 Sneha Nayak, Sukoon Sarin
 * @file Track.cpp
 * @author Sneha Nayak (snehanyk@umd.edu)
 * @author Sukoon Sarin (sukoon@umd.edu)
 * @brief Track Class implementation
 * @version 0.1
 * @date 2020-10-19
 * 
 * @copyright Copyright (c) 2020 Sneha Nayak, Sukoon Sarin
 * 
 */
#include "../include/Track.h"

/**
 * @brief Detection constructor.
 */
Track::Track()
{
}
/**
 * @brief Initializes params for the network
 */
void Track::initializeParams(std::vector<float> params) {}

/**
 * @brief initializes the feature extracor and takes path to model weights file, model metric file. model feature file  and model class file
 */
void Track::initializeFeatureExtractor(std::string modelWeightsFile, std::string modelClassFile, std::string modelMetricFile, std::string modelFeatureFile)
{
}

/**
 * @brief Runs the tracking algo by taking in frameid, detections and conidence scores
 */
void Track::runTrackerAlgorithm(cv::Mat frame, std::vector<std::vector<float>> detections, std::vector<float> confidenceDetection)
{
}

/**
 * @brief Draws green bounding box around the tracked human
 */
void Track::drawGreenBoundingBox(std::vector<float> coordinates)
{
}

/**
 * @brief Gets the Poses from the bounding boxes in the UAV's Camera Frame.
 */
std::vector<float> Track::getCoordinatesInCameraFrame(std::vector<float> coordinates)
{
  std::vector<float> v1(4);
  v1 = { 64.3,53.3,94.3,83.3 };

  return v1;
}