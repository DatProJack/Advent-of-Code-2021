#include <vector>
#include <iostream>
#include <fstream>
#include <array>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unordered_map>
#include <cmath>


using namespace std;

int main() {
  FILE *data = fopen("data.txt","r");
  char line[100];
  int index;
  int len;
  int sum;
  int total = 0;

  unordered_map<int,int> trans;
  trans[500] = 5;
  trans[501] = 2;
  trans[496] = 3;
  trans[597] = 9;
  trans[603] = 6;
  trans[598] = 0;
  trans[295] = 7;
  trans[700] = 8;
  trans[195] = 1;
  trans[398] = 4;
    
  
  while(fgets(line,100,data)!=NULL){//space 61 to the end
    index=61;
    sum=0;
    while(line[index-1] != NULL){
      cout << line[index];
      sum+=line[index];
      if(line[index]==32 || line[index]==NULL){//last one has an extra...
        total+=trans[sum-32];
        cout<<trans[sum-32];
        sum=0;
        }
      index++;
      }
    cout <<"\n";
    }
  cout << total;
}