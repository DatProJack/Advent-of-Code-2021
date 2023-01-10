#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  ifstream file("data.txt");
  int horizontalPos=0;
  int depth=0;
  int aim=0;
  int x;
  string str;  

  
  while(file.eof()==false)
  {
    file >> str >> x;
    if(str == "forward")
    {
      horizontalPos+=x;
      depth+=aim*x;
    }
    else if(str == "down")
      aim+=x;
    else
      aim -=x;
  }

  cout << depth*horizontalPos;
}