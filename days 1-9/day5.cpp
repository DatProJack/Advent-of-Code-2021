#include <iostream>
#include <fstream>
#include <array>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cmath>

using namespace std;

int main() {
  FILE *data = fopen("data.txt", "r");
  char line[20];
  int coords[4];//x1,y1,x2,y2
  char *c;

  int floor[1000][1000];
  
  for(int i=0;i<1000;i++){
    for(int j=0;j<1000;j++){
      floor[i][j]=0;
    }
    }
  while(fgets(line,20,data) != NULL){
    c =  strtok(line,",->");
    coords[0] = atoi(c);
    for(int i=1;i<4;i++){
      coords[i] = atoi(strtok(NULL,",->"));
    }
    /*for(int i=0;i<4;i++){
      cout<<coords[i]<<" ";
    }
    cout<<"\n"; */

    
    int temp;
    int changex,changey;
    
    if(coords[0]==coords[2]) {
      if(coords[1]>coords[3]){
        temp=coords[1];
        coords[1]=coords[3];
        coords[3]=temp;
      }
      for(int i = coords[1]; i <= coords[3]; i++) {
        if(coords[0]==7){
          //cout << i <<"\n";
        }
        floor[coords[0]][i] = floor[coords[0]][i]+1;
      }
    }
    else if(coords[1]==coords[3]) {
      if(coords[0]>coords[2]){
        temp=coords[0];
        coords[0]=coords[2];
        coords[2]=temp;
      }
      for(int i = coords[0]; i <= coords[2]; i++) {
        floor[i][coords[1]] = floor[i][coords[1]]+1;
      }
    }
    else {//considering diagonal lines 
      // 9,7 to 7,9
      if(coords[0]<coords[2]){
        changex = 1;
      }
      else{
        changex =-1;
      }
      if(coords[1]<coords[3]){
        changey = 1;
      }
      else{
        changey =-1;
      }
      for(int i=0; i<=abs(coords[1]-coords[3]); i++){
        floor[coords[0]+i*changex][coords[1]+i*changey] = floor[coords[0]+i*changex][coords[1]+i*changey]+1;
      }
      
    }

    
  }

  int count = 0;
  for(int i=0;i<1000;i++){
    for(int j=0;j<1000;j++){
      if(floor[i][j]>=2){
        count++;
      }
      //cout << floor[j][i] << " ";
    }
    //cout<<"\n";
  }
  cout<<count;
  
}

//make an array w all values starting at 0. add 1 every time a horizontal or vertical line goes over it. at the end count how many are equal to or more than 2