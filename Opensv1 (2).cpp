#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"



using namespace cv;
using namespace std;

int main()
{
	Mat src1;
	src1 = imread("silobear.jpg", CV_LOAD_IMAGE_COLOR);
	namedWindow("Original image", CV_WINDOW_AUTOSIZE);
	imshow("Original image", src1);

	Mat gray, edge;
	cvtColor(src1, gray, CV_BGR2GRAY);
	namedWindow("image", CV_WINDOW_AUTOSIZE);
	imshow("image", gray);

	Mat hsv, edge1, draw;
	cvtColor(src1, hsv, CV_BGR2HSV);
	namedWindow("image hsv", CV_WINDOW_AUTOSIZE);
	imshow("image hsv", hsv);

	Mat binary, edge3, drav2;
	cvtColor(src1, binary, CV_BGR2GRAY);
	threshold(binary, drav2, 100, 255, THRESH_BINARY);
	namedWindow("image binary", CV_WINDOW_AUTOSIZE);
	imshow("image binary", drav2);

	Mat src2;
	src2 = imread("silobear.jpg", CV_LOAD_IMAGE_COLOR);


	Point p1(92, 100), p2(180, 100);              //shirina vorotnika
	Scalar colorLine(0, 0, 255); // Green, teper red
	int thicknessLine = 2;
	line(src2, p1, p2, colorLine, thicknessLine);

	Point centerCircle1(123, 63);       //glaza
	int radiusCircle = 6;
	Scalar colorCircle1(0, 0, 255);
	int thicknessCircle1 = 2;
	circle(src2, centerCircle1, radiusCircle, colorCircle1, thicknessCircle1);
	Point centerCircle12(145, 63);	
	circle(src2, centerCircle12, radiusCircle, colorCircle1, thicknessCircle1);

	Point p3(52, 140), p4(92, 180);   //rykovici
	Scalar colorRectangle1(0, 0, 255);
	int thicknessRectangle1 = 2;
	rectangle(src2, p3, p4, colorRectangle1, thicknessRectangle1);
	
	void MyEllipse(Mat src2, double angle);       //ryka pravaya
	{
		int thickness = 2;
		int lineType = 8;
		ellipse(src2,
			Point(62, 150),
			Size(30, 40),
			-45,
			0,
			360,
			Scalar(255, 0, 0),
			thickness,
			lineType);
	}

	namedWindow("Original image line", CV_WINDOW_AUTOSIZE);
	imshow("Original image line", src2);
	


	waitKey(0);
	return 0;
}