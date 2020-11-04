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
void Track::initializeTracker()
{
  multiTracker = cv::MultiTracker::create();
}


/**
 * @brief Runs the tracking algo by taking in frameid, detections and conidence scores
 */
void Track::runTrackerAlgorithm(std::vector<cv::Rect> detections, std::vector<float> confidenceDetection)
{
  cv::Ptr<cv::MultiTracker> multiTrackerTemp = cv::MultiTracker::create();
  multiTracker = multiTrackerTemp;
  for (auto &detection : detections)
  {
    resizeBoxes(detection);
    multiTracker->add(cv::TrackerKCF::create(), frame_, detection);
  }
}
/**
 * @brief Sets current frame
 */

void Track::setFrame(cv::Mat frame)
{

  frame_ = frame;
}
/**
 * @brief Draws green bounding box around the tracked human
 */
cv::Mat Track::drawGreenBoundingBox()
{
  for (const auto &object : multiTracker->getObjects())
  {

    cv::rectangle(frame_, object, cv::Scalar(255, 0, 0), 2, 8);

    std::vector<float> coordinates= {float(object.x), float(object.width), float(object.y), float(object.height)};
    std::vector<float> pose = getCoordinatesInCameraFrame(coordinates);
    std::string label = cv::format("%.2f", pose[0]);
    label = "Pose: ("+label + ","+cv::format("%.2f", pose[1])+")";
    // int baseLine;
    // cv::Size labelSize = cv::getTextSize(label, cv::FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
    cv::putText(frame_, label, cv::Point(coordinates[0], coordinates[2]), cv::FONT_HERSHEY_SIMPLEX, 0.75, cv::Scalar(0, 0, 0), 1);
  }
  return frame_;
}

/**
 * @brief Gets the Poses from the bounding boxes in the UAV's Camera Frame.
 */
std::vector<float> Track::getCoordinatesInCameraFrame(std::vector<float> coordinates)
{
  std::vector<float> v1(2);
  v1 = {coordinates[0]+(coordinates[1]/2), coordinates[2]+(coordinates[3]/2)};

  return v1;
}
void Track::resizeBoxes(cv::Rect &box)
{
  box.x += cvRound(box.width * 0.1);
  box.width = cvRound(box.width * 0.8);
  box.y += cvRound(box.height * 0.06);
  box.height = cvRound(box.height * 0.8);
}

void Track::updateTracker()
{
  multiTracker->update(frame_);
}