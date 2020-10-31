/**
 * Copyright 2020 Sneha Nayak, Sukoon Sarin
 * @file DataLoader.cpp
 * @author Sneha Nayak (snehanyk@umd.edu)
 * @author Sukoon Sarin (sukoon@umd.edu)
 * @brief Data loader Class implementation
 * @version 0.1
 * @date 2020-10-19
 * 
 * @copyright Copyright (c) 2020 Sneha Nayak, Sukoon Sarin
 * 
 */
#include "../include/DataLoader.h"
#include <iostream>

/**
 * @brief Dataloader constructor.
 */
DataLoader::DataLoader()
{
  frame = cv::imread("../darknet/data/dog.jpg", cv::IMREAD_COLOR);
  
}
/**
 * @brief Set the Input Stream Method object
 */
void DataLoader::setInputStreamMethod(std::string method){
  method = method;
}
/**
 * @brief Get the Input Stream Method object. Fetches input method 
 */
std::string DataLoader::getInputStreamMethod(){
  return method;
}
/**
 * @brief Fetches the current Frame
 */
cv::Mat DataLoader::getFrame(){

  return frame;
  
}