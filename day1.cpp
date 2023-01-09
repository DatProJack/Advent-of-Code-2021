#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ifstream file("data.txt");
  int a,b,c,d;
  int count=0;

  file >> b >> c >> d;
  while(file.eof()==false)
  {
    
    a=b;
    b=c;
    c=d;
    file>>d;
    if(b+c+d>a+b+c)
      count++;
   
    
  }

  cout<<count;
}