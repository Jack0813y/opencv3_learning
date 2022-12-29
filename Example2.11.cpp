// complete program to read in a color video and write out the log-polar-
//transformed video
//

#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	
	cv::namedWindow("Example2_11", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Log_Polar", cv::WINDOW_AUTOSIZE);

	// (Note: could capture from a camera by giving a  camera id as an int.0
	//
	std::string path = "Resources/test_video.mp4";
	cv::VideoCapture capture(path);

	double fps = capture.get(cv::CAP_PROP_FPS);
	cv::Size size(
		(int)capture.get(cv::CAP_PROP_FRAME_WIDTH),
		(int)capture.get(cv::CAP_PROP_FRAME_HEIGHT)
	);

	cv::VideoWriter writer;
	writer.open("Resources/out_video.mp4", cv::CAP_OPENCV_MJPEG, fps, size);

	cv::Mat logpolar_frame, bgr_frame;
	for (;;) {
		
		capture >> bgr_frame;
		if (bgr_frame.empty())	break; // end if done

		cv::imshow("Example2_11", bgr_frame);
		
		cv::logPolar(
			bgr_frame,					//Input color frame
			logpolar_frame,				//Output log-polar frame
			cv::Point2f(				//Centerpoint for log-polar transformation
				bgr_frame.cols / 2,		//x
				bgr_frame.rows / 2		//y
			),
			40,							//Magnitude (scale parameter)
			cv::WARP_FILL_OUTLIERS		//Fill outliers with 'zero'
		);

		cv::imshow("Log_Polar", logpolar_frame);
		writer << logpolar_frame;

		char c = cv::waitKey(10);
		if (c == 27) break;				//allow the user to break out

	}
	capture.release();
}