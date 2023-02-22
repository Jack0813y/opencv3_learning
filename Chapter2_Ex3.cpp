//create a program that reads from a camera and stores
//downsampled color images to disk.

#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	
	cv::namedWindow("Camera", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Downsampled color images", cv::WINDOW_AUTOSIZE);

	std::string path = "Resources/test_video.mp4";
	cv::VideoCapture capture(path);

	double fps = capture.get(cv::CAP_PROP_FPS);
	cv::Size size(
		(int)capture.get(cv::CAP_PROP_FRAME_WIDTH)/2,
		(int)capture.get(cv::CAP_PROP_FRAME_HEIGHT)/2
	);

	cv::VideoWriter writer;
	writer.open("Resources/Downsampled_color.mp4", cv::CAP_OPENCV_MJPEG, fps, size);
	cv::Mat frame, dsd_frame;
	for (;;) {

		capture >> frame;
		if (frame.empty())	break; // end if done

		cv::imshow("Camera", frame);
		cv::pyrDown(frame, dsd_frame);


		cv::imshow("Downsampled color images", dsd_frame);
		writer << dsd_frame;
		char c = cv::waitKey(10);
		if (c == 27) break;				//allow the user to break out

	}
	capture.release();
}
