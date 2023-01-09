#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> grid2;

int sizecheck(vector<string> grid, int x, int y){
  //this will actually modify the grids and return a correct value
  //if the point is invalid return 0, so if its off the grid or its a 9
  if(x<0||x>=grid.size()||y<0||y>=grid[0].length()){
    //cout<< x <<" "<<y <<"\n";
    return 0;
  }
  if(int(grid[x][y])-'0' == 9 || grid2[x][y]==-1){
    //cout<<"1";
    //cout << grid2[x][y];
    return 0;
  }
  grid2[x][y]=-1;
  //cout <<x<<" "<<y <<"\n";
  
  return 1+sizecheck(grid,x+1,y)+sizecheck(grid,x-1,y)+sizecheck(grid,x,y+1)+sizecheck(grid,x,y-1);
}

int main() {
  ifstream reader("data.txt");
  string line;

  vector<string> grid;
  
  
  while(!reader.eof()){
    getline(reader, line);
    grid.push_back(line);
  }
  int cols = grid[0].length();
  int rows = grid.size();

  
  for(int i=0;i<rows;i++){
    vector<int> v1;
    for(int j=0;j<cols;j++){
      v1.push_back(1);
    }
    grid2.push_back(v1);
  }
  
  int total = 0;
  bool check;
  /*
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      check = true;
      if(i>=1){
        if(int(grid[i-1][j])<=int(grid[i][j])){
          check = false;
        }
      }
      if(i<=rows-2){
        if(int(grid[i+1][j])<=int(grid[i][j])){
          check = false;
        }
      }
      if(j>=1){
        if(int(grid[i][j-1])<=int(grid[i][j])){
          check = false;
        }
      }
      if(j<=cols-2){
        if(int(grid[i][j+1])<=int(grid[i][j])){
          check = false;
        }
      }
      if(check){
        //cout << total <<"\n";
        //cout<< i<< " "<<j<<" "<< grid[i][j]<<"\n";
        total+=1+int(grid[i][j])-'0';
      }
    }
  }
  cout<<total<<"\n";*/

  int k;
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      if(grid2[i][j]!=-1 && int(grid[i][j])-'0' != 9){
        
        k=sizecheck(grid,i,j);
        if(k>90){
          cout<<k<<"\n";
        }
      }
    }
  }
}