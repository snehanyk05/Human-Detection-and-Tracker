#include <iostream>
#include <vector>
#include <numeric>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/tracking.hpp>

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
    cv::Ptr<cv::MultiTracker> multiTracker;
    /**
     * @brief Private Variable for current frame
     * 
     */
    cv::Mat frame_;


public:
    /**
     * @brief Construct a new Track object
     * 
     */
    Track();
    /**
 * @brief Sets current frame
 */

    void setFrame(cv::Mat frame);
    /**
     * @brief Initializes params for the network
     * @param params type : std::vector<float>
     * @return void
     */
    void initializeTracker();

    
    /**
     * @brief Gets the Poses from the bounding boxes in the UAV's Camera Frame.
     * @param coordinates type : std::vector<float>
     * @return std::vector<float> Retruns the coordinates for bounding boxes in the frame
     */

    std::vector<float> getCoordinatesInCameraFrame(std::vector<float> coordinates);
    /**
     * @brief Runs the tracking algo by taking in frameid, detections and conidence scores
     * @param frame type : cv::Mat
     * @param detections type : std::vector<std::vector<float>>
     * @param confidenceDetection type : std::vector<float>
     * @return void
     */
    void runTrackerAlgorithm(std::vector<cv::Rect> detections, std::vector<float> confidenceDetection);
    void resizeBoxes(cv::Rect &box);
    void updateTracker();
    /**
     * @brief Draws green bounding box around the tracked human
     * @param coordinates type : std::vector<float>
     * @return void
     */
    cv::Mat drawGreenBoundingBox();
    /**
     * @brief Destroy the Track object
     * 
     */
    ~Track() {}
};