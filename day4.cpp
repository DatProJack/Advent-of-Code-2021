#include <iostream>
#include <fstream>
#include <array>
#include <ctype.h>
#include <stdio.h>

using namespace std;


int main()
{
  FILE *d4 = fopen("data.txt", "r");
  char line[20];
  int board[5][5];
  int row = 0;
  int i = 0;
  int minturns = 0;
  int score;
  int sum;
  bool toRun;
  
  array<int,100> calledNumbers {26,38,2,15,36,8,12,46,88,72,32,35,64,19,5,66,20,52,74,3,59,94,45,56,0,6,67,24,97,50,92,93,84,65,71,90,96,21,87,75,58,82,14,53,95,27,49,69,16,89,37,13,1,81,60,79,51,18,48,33,42,63,39,34,62,55,47,54,23,83,77,9,70,68,85,86,91,41,4,61,78,31,22,76,40,17,30,98,44,25,80,73,11,28,7,99,29,57,43,10};
  
  while(fgets(line, 20, d4) != NULL) {
    if(line[0] == '\n') continue;
    for(int col = 0; col < 5; col++){
      int tens = line[i] - '0';
      if(line[i] == ' '){
        tens = 0;
      }
      
      
      int ones = line[i+1] - '0';
      board[row][col] = 10*tens + ones;
      //cout << tens << " " << ones << " "<< board[row][col] <<"\n";
      i+=3;
    }
    i=0;
    row++;
    if(row == 5){//when you have a full board
      row=0;
      toRun=true;
      //now we must check how many turns for this board
      for(int n = 0; n < calledNumbers.size(); n++){
        if(!toRun){
          break;
        }
        //cout << n << "\n";
        //iterate through all 25 numbers
        for(int j=0;j<5;j++){
          for(int k=0;k<5;k++){
            if(board[j][k]==calledNumbers[n]){
              board[j][k]=-1;
            }
          }
        }

        //check if the board has 5 in a row
        bool check1,check2;
        for(int j=0;j<5;j++){
          check1 = true;
          check2 = true;
          for(int k=0;k<5;k++){
            if(board[j][k]!=-1){
              check1 = false;
            }
            if(board[k][j]!=-1){
              check2 = false;
            }
          }

          if(check1||check2){
            if(n>minturns){
              minturns = n;
              sum = 0;
              for(int j=0;j<5;j++){
                for(int k=0;k<5;k++){
                  if(board[j][k]!=-1){
                    sum+=board[j][k];
                  }
                }
              }
              score = calledNumbers[n]*sum;
              //cout << n<<" "<< sum << " "<< calledNumbers[n]<< " "<< score<<"\n";
            }
            toRun=false;
          }
          
          }
        }
      cout << "\n"<<score;
      }
    }
  }