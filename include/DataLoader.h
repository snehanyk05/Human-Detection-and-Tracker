/**
 * Copyright 2020 Sneha Nayak, Sukoon Sarin
 * @file DataLoader.h
 * @author Sneha Nayak (snehanyk@umd.edu)
 * @author Sukoon Sarin (sukoon@umd.edu)
 * @brief Source header file for Data loader class.
 * @version 0.1
 * @date 2020-10-19
 * 
 * @copyright Copyright (c) 2020 Sneha Nayak, Sukoon Sarin
 * 
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

/**
 * @brief Data loader class
 * 
 */
class DataLoader
{

private:
    /**
     * @brief Private variable to define the type for our input stream
     * 
     */
    std::string method_;
    /**
     * @brief Private variable to Store current frame
     * 
     */
    cv::Mat frame;
    
    /**
     * @brief Private variable to Store sequence of Frame 
     * 
     */
    std::vector<cv::Mat> sequenceOfFrames;
    
    /**
     * @brief Private varible for path to the input method  
     * 
     */
    std::string path;

public:
    /**
     * @brief Construct a new Data Loader object
     * 
     */
    DataLoader();

    /**
     * @brief Set the Input Stream Method object
     * @param method Defines the type for our input stream 
     * @return void
     */
    void setInputStreamMethod(std::string method);
    
    /**
     * @brief Get the Input Stream Method object. Fetches input method 
     * @param void
     * @return std::string - Returns the input stream method
     */
    std::string getInputStreamMethod();

    /**
     * @brief Fetches the current Frame
     * @param void
     * @return cv::Mat - Returns the current Frame
     */
    cv::Mat getFrame();

    /**
     * @brief Destroy the Data Loader object
     * 
     */
    ~DataLoader(){}
};