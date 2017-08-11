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
