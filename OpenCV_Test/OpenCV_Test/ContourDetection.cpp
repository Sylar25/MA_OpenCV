#include<opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	// read the image
	Mat image = imread("Wuerste_auf_grill.jpg");

	//convert image to grayscale
	Mat imagegray,imgblurred;

	cvtColor(image, imagegray, COLOR_BGR2GRAY);

	//apply binary thresholding
	Mat thresh;
	threshold(imagegray, thresh, 155, 255, THRESH_BINARY);
	GaussianBlur(imagegray, imgblurred, Size(), 9);
	imagegray.setTo(255, imgblurred);
	imshow("Binary image", thresh);
	waitKey(0);
	//imwrite("image_thres1.jpg", thresh);
	destroyAllWindows();

	//detect the contours on the binary image using CHAIN_APPROX_NONE

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(thresh, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
	//draw contours on the original image
	Mat image_copy = image.clone();
	drawContours(image_copy, contours, -1, Scalar(0, 255, 0), 2);
	imshow("None approx", image_copy);
	waitKey(0);
	imwrite("contours_none_image1_wuerste.jpg", image_copy);
	destroyAllWindows();



}