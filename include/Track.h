#include <iostream>
#include <vector>
#include <numeric>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <map>

/**
 * @brief 
 * 
 */
class Track
{

private:
    /**
     * @brief Private Variable for track ID of individual human being tracked
     * 
     */
    int track_id;
    
    /**
     * @brief Private Variable for the Parameters to tune the network 
     * 
     */
    std::vector<float> params;

    /**
     * @brief Private Variable for Path to model Weigths
     * 
     */
    std::string modelWeightsFile;

    /**
     * @brief Private Variable for path to class file
     * 
     */
    std::string modelClassFile;

    /**
     * @brief Private Variable for path to model metric file
     * 
     */
    std::string modelMetricFile;

    /**
     * @brief Private Variable for path to model feature file
     * 
     */
    std::string modelFeatureFile;

    /**
     * @brief Private Variable for current frame
     * 
     */
    cv::Mat frame;

    /**
     * @brief Private variable to store all detections in the current frame
     * 
     */
    std::vector<std::vector<float>> detections;

    /**
     * @brief Private Variable to store confidence scores of the current frame
     * 
     */
    std::vector<float> confidenceDetection;

    /**
     * @brief Runs the tracking algo by taking in frameid, detections and conidence scores
     * @param frame type : cv::Mat
     * @param detections type : std::vector<std::vector<float>>
     * @param confidenceDetection type : std::vector<float>
     * @return void
     */
    void runTrackerAlgorithm(cv::Mat frame, std::vector<std::vector<float>> detections, std::vector<float> confidenceDetection);
    
    /**
     * @brief Draws green bounding box around the tracked human
     * @param coordinates type : std::vector<float>
     * @return void
     */
    void drawGreenBoundingBox(std::vector<float> coordinates);

public:
    /**
     * @brief Construct a new Track object
     * 
     */
    Track();

    /**
     * @brief Initializes params for the network
     * @param params type : std::vector<float>
     * @return void
     */
    void initializeParams(std::vector<float> params);
    
    /**
     * @brief initializes the feature extracor and takes path to model weights file, model metric file. model feature file  and model class file
     * @param modelWeightsFile type : std::string
     * @param modelClassFile type : std::string
     * @param modelMetricFile type : std::string
     * @param modelFeatureFile type : std::string
     * @return void
     */
    void initializeFeatureExtractor(std::string modelWeightsFile, std::string modelClassFile, std::string modelMetricFile, std::string modelFeatureFile);
    
    /**
     * @brief Gets the Poses from the bounding boxes in the UAV's Camera Frame.
     * @param coordinates type : std::vector<float>
     * @return std::vector<float> Retruns the coordinates for bounding boxes in the frame
     */
    std::vector<float> getCoordinatesInCameraFrame(std::vector<float> coordinates);

    /**
     * @brief Destroy the Track object
     * 
     */
    ~Track(){}
};