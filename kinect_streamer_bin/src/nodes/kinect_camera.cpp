#include <ros/ros.h>
#include <kinect_streamer/kinect_streamer.hpp>

#include <libfreenect2/libfreenect2.hpp>
#include <libfreenect2/frame_listener_impl.h>
#include <libfreenect2/registration.h>
#include <libfreenect2/packet_pipeline.h>
#include <libfreenect2/logger.h>

#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/CameraInfo.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include <camera_info_manager/camera_info_manager.h>

// roslaunch aruco_detect aruco_detect.launch camera:=/color_a image:=/image_raw dictionary:=1 fiducial_len:=0.120 publish_images:=true
// roslaunch aruco_detect aruco_detect.launch camera:=/color_b image:=/image_raw dictionary:=1 fiducial_len:=0.120 publish_images:=true

int main(int argc, char** argv) {
    //libfreenect2::setGlobalLogger(NULL);
    std::string serial_a = "501530742442";
    std::string serial_b = "226287140347";
    ros::init(argc, argv, "kinect_camera");
    bool show = false;
    bool info = true;
    try {
        KinectStreamer::KinectDevice kin_dev_a(serial_a);
        KinectStreamer::KinectDevice kin_dev_b(serial_b);
        if (!kin_dev_a.start()) {
            std::cout << "Failed to start Kinect A." << std::endl;
            exit(-1);
        }
        if (!kin_dev_b.start()) {
            std::cout << "Failed to start Kinect B." << std::endl;
            exit(-1);
        }
        //
        ros::NodeHandle nh_camera_info_color_a;
        ros::NodeHandle nh_camera_info_color_b;
        
        ros::NodeHandle nh_camera_color;
        ros::NodeHandle nh_camera_color_a(nh_camera_color, "color_a");
        ros::NodeHandle nh_camera_color_b(nh_camera_color, "color_b");
        camera_info_manager::CameraInfoManager manager_color_a(nh_camera_color_a, "color_a");
        camera_info_manager::CameraInfoManager manager_color_b(nh_camera_color_b, "color_b");
        
        ros::Publisher pub_camera_info_color_a = nh_camera_info_color_a.advertise<sensor_msgs::CameraInfo>("color_a/camera_info", 1);
        ros::Publisher pub_camera_info_color_b = nh_camera_info_color_b.advertise<sensor_msgs::CameraInfo>("color_b/camera_info", 1);
        std::cout << "TEST!" << std::endl;
        if (!manager_color_a.loadCameraInfo("")) {
            std::cout << "Failed to get calibration from Color A .yaml" << std::endl;
            exit(-1);
        }
        if (!manager_color_a.isCalibrated()) {
            std::cout << "Color A is not calibrated." << std::endl;
        }
        if (!manager_color_b.loadCameraInfo("")) {
            std::cout << "Failed to get calibration from Color B .yaml" << std::endl;
            exit(-1);
        }
        if (!manager_color_b.isCalibrated()) {
            std::cout << "Color B is not calibrated." << std::endl;
        }
        //
        ros::NodeHandle nh_color_a;
        ros::NodeHandle nh_color_b;
        image_transport::ImageTransport it_color_a(nh_color_a);
        image_transport::ImageTransport it_color_b(nh_color_b);
        image_transport::Publisher pub_color_a = it_color_a.advertise("color_a/image_raw", 1);
        image_transport::Publisher pub_color_b = it_color_b.advertise("color_b/image_raw", 1);
        if (show) {
            cv::namedWindow("Color A", cv::WINDOW_NORMAL);
            cv::namedWindow("Color B", cv::WINDOW_NORMAL);
        }
        while (ros::ok()) {
            libfreenect2::Frame* color_a = kin_dev_a.get_frame(libfreenect2::Frame::Color);
            libfreenect2::Frame* color_b = kin_dev_b.get_frame(libfreenect2::Frame::Color);
            cv::Mat img_color_a(cv::Size(color_a->width, color_a->height), CV_8UC4, color_a->data);
            cv::Mat img_color_b(cv::Size(color_b->width, color_b->height), CV_8UC4, color_b->data);
            cv::flip(img_color_a, img_color_a, 1);
            cv::flip(img_color_b, img_color_b, 1);
            sensor_msgs::ImagePtr msg_color_a = cv_bridge::CvImage(std_msgs::Header(), "bgra8", img_color_a).toImageMsg();
            sensor_msgs::ImagePtr msg_color_b = cv_bridge::CvImage(std_msgs::Header(), "bgra8", img_color_b).toImageMsg();
            pub_color_a.publish(msg_color_a);
            pub_color_b.publish(msg_color_b);
            sensor_msgs::CameraInfo info_camera_a = manager_color_a.getCameraInfo();
            sensor_msgs::CameraInfo info_camera_b = manager_color_b.getCameraInfo();
            info_camera_a.header.stamp = ros::Time::now();
            info_camera_b.header.stamp = ros::Time::now();
            pub_camera_info_color_a.publish(info_camera_a);
            pub_camera_info_color_b.publish(info_camera_b);

            if (show) {
                cv::imshow("Color A", img_color_a);
                cv::imshow("Color B", img_color_b);
                cv::resizeWindow("Color A", cv::Size(960, 540));
                cv::resizeWindow("Color B", cv::Size(960, 540));
                char c = cv::waitKey(1);
                if (c == ' ') {
                    while (cv::waitKey(1) != ' ') {
                        
                    }   
                }
            }
            kin_dev_a.release_frames();
            kin_dev_b.release_frames();
            
        }
    } catch (std::exception e) {
        exit(-1);
    }
}