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


#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>

// Include PointCloud2 message
#include <sensor_msgs/PointCloud2.h>
#include <tf/tf.h>

#define MAX_DEPTH 5000.0

// roslaunch aruco_detect aruco_detect.launch camera:=/color image:=/image_raw dictionary:=1 fiducial_len:=0.120 publish_images:=true
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
        ros::NodeHandle nh_camera_info_color_a;
        ros::NodeHandle nh_camera_info_color_b;

        /* Two clouds! */
        ros::NodeHandle nh_cloud_a;
        ros::NodeHandle nh_cloud_b;
        
        ros::NodeHandle nh_camera_color_a("camera_a");
        ros::NodeHandle nh_camera_color_b("camera_b");

        camera_info_manager::CameraInfoManager manager_color_a(nh_camera_color_a, "color_a");
        camera_info_manager::CameraInfoManager manager_color_b(nh_camera_color_b, "color_b");
        
        ros::Publisher pub_camera_info_color_a = nh_camera_info_color_a.advertise<sensor_msgs::CameraInfo>("color_a/camera_info", 1);
        ros::Publisher pub_camera_info_color_b = nh_camera_info_color_b.advertise<sensor_msgs::CameraInfo>("color_b/camera_info", 1);
        if (!manager_color_a.loadCameraInfo("")) {
            std::cout << "Failed to get calibration from Color .yaml" << std::endl;
        }
        if (!manager_color_b.loadCameraInfo("")) {
            std::cout << "Failed to get calibration from Color .yaml" << std::endl;
        }
        if (!manager_color_a.isCalibrated()) {
            std::cout << "Color is not calibrated." << std::endl;
        }
        if (!manager_color_b.isCalibrated()) {
            std::cout << "Color is not calibrated." << std::endl;
        }
        ros::NodeHandle nh_color_a;
        ros::NodeHandle nh_color_b;
        image_transport::ImageTransport it_color_a(nh_color_a);
        image_transport::ImageTransport it_color_b(nh_color_b);
        image_transport::Publisher pub_color_a = it_color_a.advertise("color_a/image_raw", 1);
        image_transport::Publisher pub_color_b = it_color_b.advertise("color_b/image_raw", 1);

        ros::Publisher pub_cloud_a = nh_cloud_a.advertise<sensor_msgs::PointCloud2>("/points_a", 1);
        ros::Publisher pub_cloud_b = nh_cloud_b.advertise<sensor_msgs::PointCloud2>("/points_b", 1);

        while (ros::ok()) {
            kin_dev_a.wait_frames();
            libfreenect2::Frame* color_a = kin_dev_a.get_frame(libfreenect2::Frame::Color);
            libfreenect2::Frame* depth_a = kin_dev_a.get_frame(libfreenect2::Frame::Depth);
            libfreenect2::Frame* ir_a = kin_dev_a.get_frame(libfreenect2::Frame::Ir);

            kin_dev_b.wait_frames();
            libfreenect2::Frame* color_b = kin_dev_b.get_frame(libfreenect2::Frame::Color);
            libfreenect2::Frame* depth_b = kin_dev_b.get_frame(libfreenect2::Frame::Depth);
            libfreenect2::Frame* ir_b = kin_dev_b.get_frame(libfreenect2::Frame::Ir);

            // Create Image from Color Frame
            cv::Mat img_color_a(cv::Size(color_a->width, color_a->height), CV_8UC4, color_a->data);
            cv::Mat img_color_b(cv::Size(color_b->width, color_b->height), CV_8UC4, color_b->data);
            // Create Image from Depth Frame
            cv::Mat img_depth_a(cv::Size(depth_a->width, depth_a->height), CV_32FC1, depth_a->data);
            cv::Mat img_depth_b(cv::Size(depth_b->width, depth_b->height), CV_32FC1, depth_b->data);
            // Create Image from IR Frame
            cv::Mat img_ir_a(cv::Size(ir_a->width, ir_a->height), CV_32FC1, ir_a->data);
            cv::Mat img_ir_b(cv::Size(ir_b->width, ir_b->height), CV_32FC1, ir_b->data);
            // Flip the Image for Aruco Detection

            cv::medianBlur(img_depth_a, img_depth_a, 5);
            cv::medianBlur(img_depth_b, img_depth_b, 5);
            cv::flip(img_color_a, img_color_a, 1);
            cv::flip(img_color_b, img_color_b, 1);

            // Send Image
            sensor_msgs::ImagePtr msg_color_a = cv_bridge::CvImage(std_msgs::Header(), "bgra8", img_color_a).toImageMsg();
            sensor_msgs::ImagePtr msg_color_b = cv_bridge::CvImage(std_msgs::Header(), "bgra8", img_color_b).toImageMsg();
            pub_color_a.publish(msg_color_a);
            pub_color_b.publish(msg_color_b);
            // Send Camera Info
            sensor_msgs::CameraInfo info_camera_color_a = manager_color_a.getCameraInfo();
            sensor_msgs::CameraInfo info_camera_color_b = manager_color_b.getCameraInfo();
            info_camera_color_a.header.stamp = ros::Time::now();
            info_camera_color_b.header.stamp = ros::Time::now();
            pub_camera_info_color_a.publish(info_camera_color_a);
            pub_camera_info_color_b.publish(info_camera_color_b);

            // Flip the Image Back
            cv::flip(img_color_a, img_color_a, 1);
            cv::flip(img_color_b, img_color_b, 1);

            libfreenect2::Frame undistorted_a(512, 424, 4);
            libfreenect2::Frame undistorted_b(512, 424, 4);

            libfreenect2::Frame registered_a(512, 424, 4);
            libfreenect2::Frame registered_b(512, 424, 4);

            kin_dev_a.init_registration();
            kin_dev_b.init_registration();
            libfreenect2::Registration* registration_a = kin_dev_a.get_registration();
            libfreenect2::Registration* registration_b = kin_dev_b.get_registration();
            registration_a->apply(color_a, depth_a, &undistorted_a, &registered_a);
            registration_b->apply(color_b, depth_b, &undistorted_b, &registered_b);
            registration_a->undistortDepth(depth_a, &undistorted_a);
            registration_b->undistortDepth(depth_b, &undistorted_b);

            pcl::PointCloud<pcl::PointXYZRGB> cloud_a;
            for (int i = 0; i < depth_a->height; i += 4) {
                for (int j = 0; j < depth_a->width; j += 4) {
                    float d = ((float*)(undistorted_a.data))[i * depth_a->width + j];

                    pcl::PointXYZRGB point;
                    float rgb;
                    
                    float x_raw = 0;
                    float y_raw = 0;
                    float z_raw = 0;
                    registration_a->getPointXYZRGB(&undistorted_a, &registered_a, i, j, x_raw, y_raw, z_raw, rgb);
                    if (isnan(x_raw) || isnan(y_raw) || isnan(z_raw)) {
                        continue;
                    }
                    point.x = -x_raw;
                    point.y = y_raw;
                    point.z = z_raw;
                    const uint8_t *p = reinterpret_cast<uint8_t*>(&rgb);
                    point.b = p[0];
                    point.g = p[1];
                    point.r = p[2];
                    cloud_a.points.push_back(point);
                }
            }

            sensor_msgs::PointCloud2 cloud_msg_a;
            pcl::toROSMsg(cloud_a, cloud_msg_a);
            cloud_msg_a.header.frame_id = "id1a";
            cloud_msg_a.header.stamp = ros::Time::now();
            pub_cloud_a.publish(cloud_msg_a);

            pcl::PointCloud<pcl::PointXYZRGB> cloud_b;
            for (int i = 0; i < depth_b->height; i += 4) {
                for (int j = 0; j < depth_b->width; j += 4) {
                    float d = ((float*)(undistorted_b.data))[i * depth_b->width + j];

                    pcl::PointXYZRGB point;
                    float rgb;
                    
                    float x_raw = 0;
                    float y_raw = 0;
                    float z_raw = 0;
                    registration_b->getPointXYZRGB(&undistorted_b, &registered_b, i, j, x_raw, y_raw, z_raw, rgb);
                    if (isnan(x_raw) || isnan(y_raw) || isnan(z_raw)) {
                        continue;
                    }
                    point.x = -x_raw;
                    point.y = y_raw;
                    point.z = z_raw;
                    const uint8_t *p = reinterpret_cast<uint8_t*>(&rgb);
                    point.b = p[0];
                    point.g = p[1];
                    point.r = p[2];
                    cloud_b.points.push_back(point);
                }
            }

            sensor_msgs::PointCloud2 cloud_msg_b;
            pcl::toROSMsg(cloud_b, cloud_msg_b);
            cloud_msg_b.header.frame_id = "id1b";
            cloud_msg_b.header.stamp = ros::Time::now();
            pub_cloud_b.publish(cloud_msg_b);

            kin_dev_a.release_frames();
            kin_dev_b.release_frames();
            
        }
    } catch (std::exception e) {
        exit(-1);
    }
}
