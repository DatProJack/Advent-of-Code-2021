#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream reader("data.txt");
  string line;
  int grid[12][12];
  bool grid2[12][12];

  
  int r=1;
  while(!reader.eof()){
    getline(reader,line);
    for(int i=1;i<11;i++){
      grid[r][i]=line[i-1]-'0';
    }
    r++;
  }
  
  int count;
  for(int i=0;i<600;i++){
    count=0;
    for(int j=1;j<11;j++){
      for(int k=1;k<11;k++){
        grid[j][k]++;
        grid2[j][k]=true;
      }
    }
    
    bool check;
    check=true;
    while(check){
      check=false;
      for(int j=1;j<11;j++){
        for(int k=1;k<11;k++){
          if(grid[j][k]>9 && grid2[j][k]){
            check=true;
            count++;
            grid2[j][k]=false;
            grid[j-1][k-1]++;
            grid[j][k-1]++;
            grid[j+1][k-1]++;
            grid[j-1][k]++;
            grid[j+1][k]++;
            grid[j-1][k+1]++;
            grid[j][k+1]++;
            grid[j+1][k+1]++;
          }
        }
      }
    }
    if(count==100){
      cout<<i<<"\n";
    }
    for(int j=1;j<11;j++){
      for(int k=1;k<11;k++){
        if(grid[j][k]>9){
          grid[j][k]=0;
        }
      }
    }

  }

}