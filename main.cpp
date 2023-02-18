#include<iostream>

//https://github.com/ShakaUVM/colors
#include "colors/colors.h"


using namespace std;

int main(){
  set_raw_mode(true); //Turns on non-blocking I/O


  while (true){
    int input = quick_read();
    if(input!=ERR)
      cout << input;
    // if(input=='w'){
    //   cout << "w";
    // }


    
    
  }

}
