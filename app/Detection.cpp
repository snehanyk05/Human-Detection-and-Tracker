/**
 * Copyright 2020 Sneha Nayak, Sukoon Sarin
 * @file Detection.cpp
 * @author Sneha Nayak (snehanyk@umd.edu)
 * @author Sukoon Sarin (sukoon@umd.edu)
 * @brief Detection Class implementation
 * @version 0.1
 * @date 2020-10-19
 * 
 * @copyright Copyright (c) 2020 Sneha Nayak, Sukoon Sarin
 * 
 */
#include "../include/Detection.h"

/**
 * @brief Detection constructor.
 */ 
Detection::Detection()
{
    confThreshold = 0.0;
    nmsThreshold = 0.0;
    inpWidth = 0.0;
    inpHeight = 0.0;

  std::vector<float> v(4);
  v = { 34.0,23.1,64.2,53.4 };
  detections.push_back(v);
  confidenceDetection.push_back(0.7);

  std::vector<float> v1(4);
  v1 = { 64.3,53.3,94.3,83.3 };
  detections.push_back(v1);

  confidenceDetection.push_back(0.9);
  detectionsDict["frame_1"]= detections;
}
/**
 * @brief Fetches all bounding boxes of detected humans in a single frame
 */
std::vector<std::vector<float>> Detection::getDetections()
{
  return detections;
}
/**
 * @brief Gives confidence metric for each bounding box for detected humans in a frame
 */
std::vector<float> Detection::getConfidence()
{
  return confidenceDetection;
}
/**
 * @brief Fetches all detections for all Frames
 */
std::map<std::string, std::vector<std::vector<float>>> Detection::getAllDetectionsList()
{
  return detectionsDict; 
}

 /**
 * @brief Initializes Confidence and non maximum suppression threshold along with width and height of the image
 */
void Detection::initializeParams(float confThreshold, float nmsThreshold, float inpWidth, float inpHeight)
{
}
/**
 * @brief Sets path to model weights file, model config file and model class files
 */
void Detection::loadModelandLabelClasses(std::string modelWeightsFile, std::string modelConfigFile, std::string modelClassFile)
{
}
/**
 * @brief Fetched current frame 
 */
cv::Mat Detection::readInput() {}
/**
 * @brief RUns YOLOv4 algo and detects humans. If humans detected returns 1 else 0.
 */
bool Detection::processFrameforHuman(cv::Mat frame) {}
/**
 * @brief Draws a bounding box over frame from the given coordinates
 */
void Detection::drawRedBoundingBox(std::vector<float> coordinates) {}
/**
 * @brief Stores detections and confidence sores w.r.t frame IDs
 */
void Detection::storeFoundCoordinates(int frame_id, std::vector<std::vector<float>> detections, std::vector<float> confidenceDetection) {}
