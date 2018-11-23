#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv){
    Mat src, gray, color_edge;
    src = imread("../../data/image/chessboard.png");
    if(!src.data){
        return -1;
    }

    // transfer to gray scale and remove noise
    cvtColor(src, gray, CV_BGR2GRAY);
    GaussianBlur(gray, gray, Size(9, 9), 3, 3);

    Mat corners, dilated_corners;
    preCornerDetect(
        gray,     // source 
        corners,  // output
        5         // ksize
    );

    dilate(corners, dilated_corners, Mat());

    for(int j=0; j<src.rows; ++j){
        const float *dilated_data = (const float*)dilated_corners.ptr(j);
        const float *corners_data = (const float*)corners.ptr(j); 
        for(int i=0; i<src.cols; ++i){
            if(dilated_data[i]>0.027 &&
               dilated_data[i] == corners_data[i]){
                circle(
                    src, 
                    Point(i, j), 
                    5, 
                    Scalar(0, 0, 255), 
                    -1, 
                    8, 
                    0
                );
            }
        }
    }

    imshow("Kitchen-Rosenfeld", src);
    waitKey(0);
 
    destroyAllWindows();
    return 0;
}