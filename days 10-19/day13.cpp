#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream reader("data.txt");

  int grid[20][20];
  string input;
  int x,y;
  
  while(!ryeader.eof()){
    getline(reader,input,',');
    if(int(input[0])<=57 && int(input[0])>=48){
      x=stoi(input);
      getline(reader,input);
      y=stoi(input);
      grid[x][y]=1;
    }
    else{//use the string find function on '='
      cout << input << "\n";
    }
  }
}