#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <bits/stdc++.h>
//maybe use a stack
using namespace std;

int main() {
  ifstream reader("data.txt");
  string line;
  map<char, char> map1 = {{'{', '}',},
                          {'[', ']',},
                          {'<', '>',},
                          {'(',')'}};
  map<char, int> map2 = {{'{', 3,},
                          {'[', 2,},
                          {'<', 4,},
                          {'(',1,}};
  vector<char> stack;
  vector<long int> scores;
  bool check1;
  
  long int total=0;


  while(!reader.eof()){
    getline(reader,line);

    stack.clear();
    stack.push_back(line[0]);
    check1 = true;
    total=0;
    for(int i=1;i<line.length();i++){
      if(line[i]=='{'||line[i]=='<'||line[i]=='('||line[i]=='['){
        stack.push_back(line[i]);
      }
      else{
        if(line[i]==map1[stack[stack.size()-1]]){
          stack.pop_back();
        }
        else{
          check1=false;
          break;
        }
      }
    }
    if(check1){
      for(int i=0;i<stack.size();i++){
        total = total*5+map2[stack[stack.size()-1-i]];
        
      }
      scores.push_back(total);
    }
  }
  sort(scores.begin(),scores.end());
  for(int i=0;i<scores.size();i++){
    cout<< i <<" "<<scores[i]<<"\n";
  }
  cout<<scores[scores.size()/2]<<"\n";
  //so large that it goes negative
}