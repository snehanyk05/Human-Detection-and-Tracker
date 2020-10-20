/**
 * @file    main.cpp
 * @author  Sneha Nayak, Sukoon Sarin
 * @copyright Copyright (c) 2020 Sneha Nayak, Sukoon Sarin
 * @version 0.1
 * @date 2020-10-19
 * @brief Main file to run detetction and tracking
 */
#include "../include/DataLoader.h"
#include "../include/Detection.h"
#include "../include/Track.h"
#include <iostream>
/**
 * @fn main
 * @brief Main function
 * @detail Finds detection and tracks human, return coordinates in UAV's camera frame
 * @return Program execution status
 */
int main() {
    DataLoader data;
    data.setInputStreamMethod(std::string("Image"));
    std::cout << "Data input method is " << data.getInputStreamMethod()<< std::endl;
    cv::imshow("Data",data.getFrame());
    
    Detection detect;
    detect.initializeParams(0.8,0.9,320,320);
   
    Track track;
    std::vector<float> v(4);
    v = { 34.0,23.1,64.2,53.4 };
    track.initializeParams(v);
    std::vector<float> v1 = track.getCoordinatesInCameraFrame(v);

  return 0;
}
