/**
 * Copyright 2020 Sneha Nayak, Sukoon Sarin
 * @file DataLoader.h
 * @author Sneha Nayak (snehanyk@umd.edu)
 * @author Sukoon Sarin (sukoon@umd.edu)
 * @brief Source header file for Detection class.
 * @version 0.1
 * @date 2020-10-19
 * 
 * @copyright Copyright (c) 2020 Sneha Nayak, Sukoon Sarin
 * 
 */
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <opencv2/core/core.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <map>

/**
 * @brief Detection class responsible for running Human detection using YOLOv4 on image or video.
 * 
 */
class Detection
{

private:
    /**
     * @brief Private variable for confThreshold
     * 
     */
    float confThreshold_;

    /**
     * @brief  Private variable for nmsThreshold
     * 
     */
    float nmsThreshold_;

    /**
     * @brief Private variable for inpWidth
     * 
     */
    float inpWidth_;

    /**
     * @brief Private variable for inpHeight
     * 
     */
    float inpHeight_;

    /**
     * @brief Private variable for modelWeightsFile
     * 
     */
    std::string modelWeightsFile_;

    /**
     * @brief Private variable for modelConfigFile
     * 
     */
    std::string modelConfigFile_;

    /**
     * @brief Private variable for modelClassFile
     * 
     */
    std::string modelClassFile_;

    /**
     * @brief Private variable for current frame
     * 
     */
    cv::Mat frame_;
    std::vector<std::string> classes;

    /**
     * @brief Private variable to store all detections in the current frame
     * 
     */
    std::vector<cv::Rect> detections;

    /**
     * @brief Private Variable to store confidence scores of the current frame
     * 
     */
    std::vector<float> confidenceDetection;

    /**
     * @brief Draws a bounding box over frame from the given coordinates
     * @param coordinates Type : std::vector<float> 
     * @return void
     */
    void drawRedBoundingBox(std::vector<int> coordinates, int classID, float conf);
    std::vector<cv::String> getOutputsNames(const cv::dnn::Net &net);
    std::vector<cv::Rect> postProcess(const std::vector<cv::Mat> &outs);

public:
    /**
     * @brief constructor for Detection class with no parameters.
     * 
     */
    Detection();

    /**
     * @brief Initializes Confidence and non maximum suppression threshold along with width and height of the image
     * @param confThreshold type : float
     * @param nmsThreshold type : float
     * @param inpWidth type : float
     * @param inpHeight type : float
     * @return void
     */
    void initializeParams(float confThreshold, float nmsThreshold, float inpWidth, float inpHeight);

    /**
     * @brief Sets path to model weights file, model config file and model class files
     * @param modelWeightsFile type : std::string 
     * @param modelConfigFile type : std::string 
     * @param modelClassFile type : std::string 
     * @return void
     */
    void loadModelandLabelClasses(std::string modelWeightsFile, std::string modelConfigFile, std::string modelClassFile);

    /**
     * @brief Fetches all bounding boxes of detected humans in a single frame
     * @param void
     * @return std::vector<std::vector<float>> - Returns all the detections in the frame
     */
    std::vector<cv::Rect> getDetections();

    /**
     * @brief RUns YOLOv4 algo and detects humans. If humans detected returns 1 else 0.
     * 
     * @param frame Type : cv::Mat
     * @return true 
     * @return false 
     */
    std::vector<cv::Rect> processFrameforHuman();

    /**
     * @brief Gives confidence metric for each bounding box for detected humans in a frame
     * @param void
     * @return std::vector<float> - Returns all the the confidence scores in the Frame
     */
    std::vector<float> getConfidence();

    /**
     * @brief Destroy the Detection object
     * 
     */

    void setFrame(cv::Mat frame);

    ~Detection() {}
};