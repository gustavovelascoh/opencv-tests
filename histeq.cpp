#include <iostream>
#include <string>
#include <stdio.h>

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/videoio.hpp>

using namespace std;
using namespace cv;


/**  @function main */
int main( int argc, char** argv )
{
  Mat src, dst;

  string source_window = "Source image";
  string equalized_window = "Equalized Image";

  /// Load image
  src = imread( argv[1], 1 );

  if( !src.data )
    { cout<<"Usage: ./Histogram_Demo <path_to_image>"<<endl;
      return -1;}

  /// Convert to grayscale
  //cvtColor( src, src, COLOR_BGR2GRAY);

  /// Apply Histogram Equalization
  equalizeHist( src, dst );

  /// Display results
  namedWindow( source_window, WINDOW_AUTOSIZE );
  namedWindow( equalized_window, WINDOW_AUTOSIZE );

  imshow( source_window, src );
  imshow( equalized_window, dst );

  /// Wait until user exits the program
  waitKey(0);

  return 0;
}
