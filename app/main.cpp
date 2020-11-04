/**
 * @file    main.cpp
 * @author  Sneha Nayak, Sukoon Sarin
 * @copyright Copyright (c) 2020 Sneha Nayak, Sukoon Sarin
 * @version 0.1
 * @date 2020-10-19
 * @brief Main file to run detetction and tracking
 */
#include "../include/DataLoader.h"
// #include "../include/Detection.h"
// #include "../include/Track.h"
#include <iostream>
#include <fstream>
#include <sstream>

// keys It is used for showing parsing examples.
const char* keys =
"{help h usage ? | | Usage examples: \n\t\t./object_detection_yolo.out --image=dog.jpg \n\t\t./object_detection_yolo.out --video=run_sm.mp4}"
"{image i        |<none>| input image   }"
"{video v       |<none>| input video   }"
;
/**
 * @fn main
 * @brief Main function
 * @detail Finds detection and tracks human, return coordinates in UAV's camera frame
 * @return Program execution status
 */
int main(int argc, char** argv) {
    
    DataLoader data;
    // Detection detect;
    // Track track;


    cv::CommandLineParser parser(argc, argv, keys);
    parser.about("Use this script to run Human detection using YOLOv4 in OpenCV.");
    if (parser.has("help"))
    {
        parser.printMessage();
        return 0;
    }

    int input_type = data.checkParser(parser);
    if (input_type == 0)
        data.processInput(parser);
     else {
        data.setInputStreamMethod(std::string("Image"));
        std::cout << "Data input method is : " << data.getInputStreamMethod()<< std::endl;
    }

    //cv::imshow("Data",data.getFrame());
    
    // //detection
    // detect.initializeParams(0.8,0.9,320,320);
   
    // //tracking
    // std::vector<float> v(4);
    // v = { 34.0,23.1,64.2,53.4 };
    // track.initializeParams(v);
    // std::vector<float> v1 = track.getCoordinatesInCameraFrame(v);

  return 0;
}
