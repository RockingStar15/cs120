#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using std::cout, std::endl, std::string;

void initializeImage(Pixel image[][MAX_HEIGHT]) {
  // iterate through columns
  for (unsigned int col = 0; col < MAX_WIDTH; col++) {
    // iterate through rows
    for (unsigned int row = 0; row < MAX_HEIGHT; row++) {
      // initialize pixel
      image[col][row] = {0, 0 ,0};
      
    }
  }
}

void loadImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int& height) {
  // TODO: implement (part 1)
   std :: ifstream file;
   file.open(filename);
   string file_type;

   if (!file.is_open()) {
    throw std :: runtime_error("Failed to open " + filename);
      
   }
  
file >> file_type;
if(file_type != "P3" && file_type != "p3"){
  throw std :: runtime_error("Invalid type " + file_type);
}
file >> width;
file >> height;

if(width>MAX_WIDTH || width<=0) {
  throw std :: runtime_error ("Invalid demensions");
}
if(height>MAX_HEIGHT || height<=0){
    throw std :: runtime_error ("Invalid demensions");
}
//Get the maximum value
int maximum_value;
file >> maximum_value;
int value = width * height;


int value_check =0;


for(unsigned int i =0; i<height; ++i){
  for(unsigned int j=0; j<width; ++j){
    file>>image[j][i].r;
    file>>image[j][i].g;
    file>>image[j][i].b;
    int R;
    int G;
    int B;
     R = image[j][i].r;
     G = image[j][i].g;
     B= image [j][i].b;
  if(R<0 || R>maximum_value){
      throw std :: runtime_error("Invalid color value");
  }
  if(G<0 || G>maximum_value){
    throw std :: runtime_error("Invalid color value");
  }
  if(B<0 || B>maximum_value){
    throw std :: runtime_error("Invalid color value");
  }
  
  value_check+=1;
  }
  
  

}

if(value_check>value)
{
   throw std :: runtime_error("Too many values");
}
else if(value_check<value){
  throw std :: runtime_error("Invalid color values");
}


file.close();
}
void outputImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height) {
  // TODO: implement (part 1)
  std :: ofstream file;
  file.open(filename);
  if(!file.is_open()){
    cout << "Failed to open " + filename;
  }
  file << "P3" << endl;

  file << width << " " << height << endl;

  file << 255 <<endl;

  for(unsigned int i =0; i<height; ++i){
    for(unsigned int j =0; j<width; ++j){
      file << image[j][i].r << " ";
      file << image[j][i].g << " ";
      file << image[j][i].b << endl;
    }
    
  }
    file.close();
}

unsigned int energy(Pixel image[][MAX_HEIGHT], unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
  // TODO: implement (part 1)
  
 if(x==0 && y==0){
  //X-values
  unsigned int Rx_ans = abs(image[x+1][y].r - image[width-1][y].r);
  unsigned int Gx_ans = abs(image[x+1][y].g - image[width-1][y].g);
  unsigned int Bx_ans = abs(image[x+1][y].b - image[width-1][y].b);
  unsigned int ans_x = pow(Rx_ans,2)+pow(Gx_ans,2) + pow(Bx_ans,2);
//y-values
  unsigned int Ry_ans = abs(image[x][height-1].r - image[x][y+1].r);
  unsigned int Gy_ans = abs(image[x][height-1].g - image[x][y+1].g);
  unsigned int By_ans = abs(image[x][height-1].b - image[x][y+1].b);
  unsigned int ans_y = pow(Ry_ans,2) + pow(Gy_ans,2) + pow(By_ans,2);
  return ans_x + ans_y;
 }
 if(x==0 && y==height-1){
  unsigned int Rx_ans = abs(image[x+1][y].r - image[width-1][y].r);
  unsigned int Gx_ans = abs(image[x+1][y].g - image[width-1][y].g);
  unsigned int Bx_ans = abs(image[x+1][y].b - image[width-1][y].b);
  unsigned int ans_x = pow(Rx_ans,2)+pow(Gx_ans,2) + pow(Bx_ans,2);
 
  unsigned int Ry_ans = abs(image[x][0].r - image[x][y-1].r);
  unsigned int Gy_ans = abs(image[x][0].g - image[x][y-1].g);
  unsigned int By_ans = abs(image[x][0].b - image[x][y-1].b);
  unsigned int ans_y = pow(Ry_ans,2) + pow(Gy_ans,2) + pow(By_ans,2);
  return ans_x + ans_y;
 }
 if(x==width-1 && y==0){
  unsigned int Rx_ans = abs(image[0][y].r - image[x-1][y].r);
  unsigned int Gx_ans = abs(image[0][y].g - image[x-1][y].g);
  unsigned int Bx_ans = abs(image[0][y].b - image[x-1][y].b);
  unsigned int  ans_x = pow(Rx_ans,2)+pow(Gx_ans,2) + pow(Bx_ans,2);
 
  unsigned int Ry_ans = abs(image[x][y+1].r - image[x][height-1].r);
  unsigned int Gy_ans = abs(image[x][y+1].g - image[x][height-1].g);
  unsigned int By_ans = abs(image[x][y+1].b - image[x][height-1].b);
  unsigned int ans_y = pow(Ry_ans,2) + pow(Gy_ans,2) + pow(By_ans,2);
  return ans_x + ans_y;
 }

if(x==width-1 && y==height-1){
  unsigned int Rx_ans = abs(image[0][y].r - image[x-1][y].r);
  unsigned int Gx_ans = abs(image[0][y].g - image[x-1][y].g);
  unsigned int Bx_ans = abs(image[0][y].b - image[x-1][y].b);
  unsigned int ans_x = pow(Rx_ans,2)+pow(Gx_ans,2) + pow(Bx_ans,2);
 
  unsigned int Ry_ans = abs(image[x][0].r - image[x][y-1].r);
  unsigned int Gy_ans = abs(image[x][0].g - image[x][y-1].g);
  unsigned int By_ans = abs(image[x][0].b - image[x][y-1].b);
  unsigned int ans_y = pow(Ry_ans,2) + pow(Gy_ans,2) + pow(By_ans,2);
  return ans_x + ans_y;
 }

 if((x==0 && y!=0 )|| (x==0 && y!=height-1)){
  unsigned int Rx_ans = abs(image[x+1][y].r - image[width-1][y].r);
  unsigned int Gx_ans = abs(image[x+1][y].g - image[width-1][y].g);
  unsigned int Bx_ans = abs(image[x+1][y].b - image[width-1][y].b);
  unsigned int ans_x = pow(Rx_ans,2)+pow(Gx_ans,2) + pow(Bx_ans,2);
  
  unsigned int Ry_ans = abs(image[x][y-1].r - image[x][y+1].r);
  unsigned int Gy_ans = abs(image[x][y-1].g - image[x][y+1].g);
  unsigned int By_ans = abs(image[x][y-1].b - image[x][y+1].b);
  unsigned int ans_y = pow(Ry_ans,2) + pow(Gy_ans,2) + pow(By_ans,2);
  return ans_x + ans_y;
 }
 if((y==0 && x!=0) || (y==0 && x!=width-1)){
  unsigned int Rx_ans = abs(image[x+1][y].r - image[x-1][y].r);
  unsigned int Gx_ans = abs(image[x+1][y].g - image[x-1][y].g);
  unsigned int Bx_ans = abs(image[x+1][y].b - image[x-1][y].b);
  unsigned int ans_x = pow(Rx_ans,2)+pow(Gx_ans,2) + pow(Bx_ans,2);
  
  unsigned int Ry_ans = abs(image[x][height-1].r - image[x][y+1].r);
  unsigned int Gy_ans = abs(image[x][height-1].g - image[x][y+1].g);
  unsigned int By_ans = abs(image[x][height-1].b - image[x][y+1].b);
  unsigned int ans_y = pow(Ry_ans,2) + pow(Gy_ans,2) + pow(By_ans,2);
  return ans_x + ans_y;
 }
 if((x==width-1 && y!=0) || (x==width-1 && y!=height-1)){
  unsigned int Rx_ans = abs(image[x-1][y].r - image[0][y].r);
  unsigned int Gx_ans = abs(image[x-1][y].g - image[0][y].g);
  unsigned int Bx_ans = abs(image[x-1][y].b - image[0][y].b);
  unsigned int ans_x = pow(Rx_ans,2)+pow(Gx_ans,2) + pow(Bx_ans,2);
  
  unsigned int Ry_ans = abs(image[x][y-1].r - image[x][y+1].r);
  unsigned int Gy_ans = abs(image[x][y-1].g - image[x][y+1].g);
  unsigned int By_ans = abs(image[x][y-1].b - image[x][y+1].b);
  unsigned int ans_y = pow(Ry_ans,2) + pow(Gy_ans,2) + pow(By_ans,2);
  return ans_x + ans_y;
 }
 if((y==height-1 && x!=0) || (y==height-1 && x!=width-1)){
  unsigned int Rx_ans = abs(image[x-1][y].r - image[x+1][y].r);
  unsigned int Gx_ans = abs(image[x-1][y].g - image[x+1][y].g);
  unsigned int Bx_ans = abs(image[x-1][y].b - image[x+1][y].b);
  unsigned int ans_x = pow(Rx_ans,2)+pow(Gx_ans,2) + pow(Bx_ans,2);
  
  unsigned int Ry_ans = abs(image[x][0].r - image[x][y-1].r);
  unsigned int Gy_ans = abs(image[x][0].g - image[x][y-1].g);
  unsigned int By_ans = abs(image[x][0].b - image[x][y-1].b);
  unsigned int ans_y = pow(Ry_ans,2) + pow(Gy_ans,2) + pow(By_ans,2);
  return ans_x + ans_y;
 }
  
  unsigned int Rx_ans =  abs(image[x+1][y].r - image[x-1][y].r);
  unsigned int Gx_ans = abs(image[x+1][y].g - image[x-1][y].g);
  unsigned int Bx_ans = abs(image[x+1][y].b - image[x-1][y].b);
  unsigned int ans_x = pow(Rx_ans,2) + pow(Gx_ans,2) + pow(Bx_ans,2);
  //y 
  
  unsigned int Ry_ans = abs(image[x][y+1].r - image[x][y-1].r);
  unsigned int Gy_ans = abs(image[x][y+1].g - image[x][y-1].g);
  unsigned int By_ans = abs(image[x][y+1].b- image[x][y-1].b);

  unsigned int ans_y = pow(Ry_ans,2) + pow(Gy_ans,2) + pow(By_ans,2);

  return (ans_x + ans_y);
}

// uncomment functions as you implement them (part 2)

// unsigned int loadVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int start_col, unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
//   return 0;
// }

// unsigned int loadHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int start_row, unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
//   return 0;
// }

// void findMinVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
// }

// void findMinHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
// }

// void removeVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int height, unsigned int verticalSeam[]) {
//   // TODO: implement (part 2)
// }

// void removeHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int& height, unsigned int horizontalSeam[]) {
//   // TODO: implement (part 2)
// }
