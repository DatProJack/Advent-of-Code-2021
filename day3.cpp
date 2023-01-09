#include <iostream>
#include <fstream>
#include <string>
#include <math.h> 
#include <list>
using namespace std;

int main()
{
  ifstream file("data.txt");

  string str;
  file >> str;

  int arr [str.length()];
  for(int i=0;i<str.length();i++)
  {
    if(str[i] == '0')
      arr[i]++;
    else
      arr[i]--;
  }
  while(file.eof() == false)
  {
    file>>str;
    for(int i=0;i<str.length();i++)
    {
      if(str[i] == '0')
        arr[i]++;
      else
        arr[i]--;
    }
  }


  int gamma=0;
  int n=1;
  for(int i=str.length()-1;i>=0;i--)
  {
    cout<<arr[i]<<"\n";
    if(arr[i]<0)
    {
      gamma+=n;
    }
    n=n*2;
  }

  int beta = pow(2,12)-1-gamma;
  
  cout << gamma*beta;
}