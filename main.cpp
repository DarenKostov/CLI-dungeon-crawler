#include<iostream>
#include <csignal>

//https://github.com/ShakaUVM/colors
#include "colors/colors.h"


using namespace std;

void bailout() {
	// set_mouse_mode(false);
	set_raw_mode(false);
}

void interrupt_handler(int x) {
	std::exit(0);
}

void swapPositions(char*&, char*&);


int main(){
	atexit(bailout);
	signal(SIGINT,interrupt_handler);

  set_raw_mode(true); //Turns on non-blocking I/O




  int terrainWidth=20;
  int terrainHeight=20;
  cout << "allocating memory\n";
  char*** terrain=new char**[terrainWidth];
  for(int x=0; x<terrainWidth; x++){
    terrain[x]=new char*[terrainHeight];
    for(int y=0; y<terrainHeight; y++){
      terrain[x][y]=new char;
      *terrain[x][y]=' ';
    }
  }
  cout << "done allocating memory\n";


  int myx=5, myy=5;
  *terrain[myx][myy]='&';

  
  bool exitGame=false;
  long gameTick=0;
  while (true){
    gameTick++;
    int input = quick_read();

    switch(input){
      case 119://W
        // cout << "up\n";
        swapPositions(terrain[myx][myy], terrain[myx][myy-1]);
        myy--;
        break;
      case 97://A
        // cout << "left\n";
        swapPositions(terrain[myx][myy], terrain[myx-1][myy]);
        myx--;
        break;
      case 115://S
        // cout << "down\n";
        swapPositions(terrain[myx][myy], terrain[myx][myy+1]);
        myy++;
        break;
      case 100://D
        // cout << "right\n";
        swapPositions(terrain[myx][myy], terrain[myx+1][myy]);
        myx++;
        break;
      case 113://Q
        exitGame=true;
        break;
      case ERR:
        break;
      default:
        cout << "code: " << input << "\n";
    }


    if(gameTick%1000==0){
      for(int i=0; i<100; i++){
        cout << '\n' << flush;
      }

      
      string output="";
      for(int y=0; y<terrainHeight; y++){
        for(int x=0; x<terrainWidth; x++){
          output+=*terrain[x][y];
        }
        output+='\n';
      }
      cout << output;
    }
    
    if(exitGame)
      break;
  }



  cout << "de-allocating memory\n";

  for(int x=0; x<terrainWidth; x++){
    for(int y=0; y<terrainHeight; y++){
      delete terrain[x][y];    
    }
    delete terrain[x];
  }
  delete[] terrain;
  
  cout << "done de-allocating memory\n";
}



void swapPositions(char*& pos1, char*& pos2){
  char* temp=pos1;

  pos1=pos2;
  pos2=temp;

}



