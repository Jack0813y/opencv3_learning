//sing cv::pyrDown() to create a new image that is half the width and
//height of the input image
//
#include <opencv2/opencv.hpp>
int main(int argc, char** argv) {
	cv::Mat img1, img2;
	cv::namedWindow("Example1", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example2", cv::WINDOW_AUTOSIZE);
	img = cv::imread(argv[1]);
	cv::imshow("Example1", img1);
	cv::pyrDown(img1, img2);
	cv::imshow("Example2", img2);
	cv::waitKey(0);
	return 0;
}