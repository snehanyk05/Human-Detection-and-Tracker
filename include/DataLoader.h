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
    cv::Mat frame_;
    
    /**
     * @brief Private varible for path to the input method  
     * 
     */
    std::string path_;



    /**
     * @brief Private variable to 
     * 
     */
    std::string outputFile;

public:
    /**
     * @brief Construct a new Data Loader object
     * 
     */
    DataLoader();
    DataLoader(std::string path, std::string method);
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
     * @brief Processes the input file
     * @param void
     * @return void
     */
    void processInput(cv::CommandLineParser parser);


  /**
   * @brief updates isVideo and isImage values.
   * @param[in] parser It containes information about the imagepath and videopath.
   * @return type int.
   */
    int checkParser(cv::CommandLineParser parser);

    /**
     * @brief Destroy the Data Loader object
     * 
     */
    ~DataLoader(){}
};