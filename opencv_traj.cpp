#include <iostream>
#include <opencv2/opencv.hpp>
#include <boost/filesystem.hpp>

#include "er_helper.h"


std::string dir = "../";

void parseArgs(int argc,char *argv[]){
  for(int i = 1; i < argc; i++){
    std::string arg = std::string(argv[i]);
    std::transform(arg.begin(), arg.end(), arg.begin(), ::tolower);

    if (arg == "-dir" ){
      dir = std::string(argv[++i]);
    }else{
      std::cout << " Unknown arg: " << argv[i] << std::endl;
    }
  }
}    


int main(int argc, char * argv[]){
  parseArgs(argc,argv);
 
}



void homo1(){
     //Old - from akaze.

    
    H = cv::findHomography(points1,points2,cv::RANSAC,error,status);

//    cv::Mat F , E, R, t, mask;
//    recoverPose(H, points1, points2, R, t, 1081.37, cv::Point2d (959.5,539.5), mask);
//    std::cout << "Mat: R\n" << R[0] << std::endl;  
//    std::cout << "Mat: t\n" << t[0] << std::endl;  
    std::cout << std::fixed;
    std::cout.setf( std::ios::fixed, std::ios::floatfield ); 
    std::cout.precision(32); 

    cv::Mat cam = ( cv::Mat1f(3,3) << 
      1081.37, 0, 959.5,
      0,  1081.37, 539.5,
      0, 0, 1 );
    std::vector<cv::Mat> R,T,N;
    cv::decomposeHomographyMat(H, cam , R, T , N);
    int i=0;
//    for(int i = 0 ; i < R.size() ; i++){
      std::cout << "Mat: R\n " << R[i] << std::endl;
      std::cout << "Mat: T\n " << T[i] << std::endl;
      std::cout << "Mat: N\n " << N[i] << std::endl;
//    }
   
    cv::Mat ffs = ( cv::Mat1d(4,4) <<
    R[i].at<double>(0,0), R[i].at<double>(0,1), R[i].at<double>(0,2), T[i].at<double>(0),
    R[i].at<double>(1,0), R[i].at<double>(1,1), R[i].at<double>(1,2), T[i].at<double>(1),
    R[i].at<double>(2,0), R[i].at<double>(2,1), R[i].at<double>(2,2), T[i].at<double>(2),
    0 , 0,  0,  1 );
    
    cv::transpose(ffs,ffs);
//  std::cout << "Mat: FFS\n" << ffs << std::endl;
  
//    std::cout << "Mat H:\n" <<  ffs << std::endl;
    std::cout << "Mat: H" << std::endl;

    for (int y = 0; y < ffs.size().height ; y++){
      for(int x = 0; x < ffs.size().width ; x++){
        std::cout <<  ffs.at<double>(x,y) << " ";
      }
     std::cout << std::endl;
    }
}
