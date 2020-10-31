/**
 * Copyright 2020 Sneha Nayak, Sukoon Sarin
 * @file test.cpp
 * @author Sneha Nayak (snehanyk@umd.edu)
 * @author Sukoon Sarin (sukoon@umd.edu)
 * @brief Solitary Test source file for testing the Detection, DataLoader and Track
 *        class methods. Includes all the required headers
 * @version 0.1
 * @date 2020-10-19
 * 
 * @copyright Copyright (c) 2020 Sneha Nayak, Sukoon Sarin
 * 
 */
#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "../include/DataLoader.h"
#include "../include/Detection.h"
#include "../include/Track.h"
#include <map>
#include <vector>
#include <iostream>

DataLoader dummydataloader;
Detection detection1;
Track dummytrack;
std::vector<float> vec1 = { 0.7, 0.9};
// std::vector<std::vector<float>> vec2 = { { 34.0,23.1,64.2,53.4 }, { 64.3,53.3,94.3,83.3 }, { 1.0, 2.0, 3.0, 4.0 } };
std::vector<std::vector<float>> vec2 = { { 34.0,23.1,64.2,53.4 }, { 64.3,53.3,94.3,83.3 }};
std::map<std::string, std::vector<std::vector<float>>> dic1 =  {
    { std::string("A"), vec2},
    { std::string("B"), vec2},
};

/**
 * @brief Test case for getAllDetectionsList method of Detection class. 
 */
TEST(DetectionTest, checkdetectionlist) {
  std::map<std::string, std::vector<std::vector<float>>> testmap = detection1.getAllDetectionsList();
  EXPECT_EQ(dic1["A"], testmap.begin()->second);
}

/**
 * @brief Test case for getDetections method of Detection class. 
 */
TEST(DetectionTest, checkdetections) {;
  EXPECT_EQ(vec2, detection1.getDetections() );
}

/**
 * @brief Test case for getConfidence method of Detection class. 
 */
TEST(DetectionTest, checkconfidence) {;
  EXPECT_EQ(vec1, detection1.getConfidence() );
}

/**
 * @brief Test case for getInputStreamMethod and setInputStreamMethod method of DataLoader class. 
 */
TEST(DataLoaderTest, SetandgetPath) {
  std::string test_method = "Video"; 
  dummydataloader.setInputStreamMethod(test_method);
  EXPECT_EQ(test_method, dummydataloader.getInputStreamMethod() );
}

/**
 * @brief Test case for getFrame method of DataLoaderO class. 
 */
// TEST(DataLoaderTest, GetFrame) {
//   cv::Mat test_frame = cv::imread("../sample.jpg");
//   EXPECT_EQ(test_frame, dummydataloader.getFrame() );
// }

/**
 * @brief Test case for getCoordinatesInCameraFrame method of Track class. 
 */
TEST(TrackerTest, Gettrackedcoordinates) {
  EXPECT_EQ(vec2[1], dummytrack.getCoordinatesInCameraFrame(vec1) );
}