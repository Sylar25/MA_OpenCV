#include <opencv2\imgcodecs.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void main() {

	string path = "Test.jpg";
	Mat img = imread(path);
	Mat imgResize, imgCrop;

	//cout << img.size << endl;

	resize(img, imgResize, Size(),0.5,0.5);

	Rect roi(100, 100, 300, 250);
	imgCrop = img(roi);

	imshow("Image", img);
	imshow("ImageCrop", imgCrop);
	
	waitKey(0);
}