#include <iostream>
#include <stdio.h>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
       int fps     = 25;  // or 30
       Mat img;
       char* filename=new char[100];

       int i=1;
       sprintf( filename, "%04d.exr", i );

       img = imread(filename,CV_LOAD_IMAGE_COLOR); //imagem b&w

       VideoWriter video("data3",CV_FOURCC('X','2','6','4'),fps,img.size());
       namedWindow( "Display window", CV_WINDOW_AUTOSIZE );// Create a window for display.
       imshow("Display window",img);
       waitKey(0);

      do
      {
          sprintf( filename, "%04d.exr", i );
          img.release();
          img = imread(filename,1); //imagem b&w
          if(img.empty()) break;
          video.write(img);
           i++;
       }
       while(!img.empty());
       return 0;
}


