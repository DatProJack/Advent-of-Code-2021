#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string,vector<string>> grid;
int totall=0;

int traverse(vector<string> path, string current, bool hasvisitedtwice) {
  if(current == "end"){
    totall+=1;
/*
    for(int i=0;i<path.size();i++){
      cout<<path[i]<<" ";
    }
    cout<<current<<"\n";*/
    
    return 1;
  }
  else if(96<int(current[0])&&int(current[0])<123&& find(path.begin(), path.end(), current)!= path.end()){
    if(hasvisitedtwice){
      return 0;
    }
    hasvisitedtwice = true;
  }
  //return all paths w current added to the path
  path.push_back(current);
  int toreturn;
  for(int i=0;i<grid[current].size();i++){
    toreturn += traverse(path,grid[current][i],hasvisitedtwice);
  }
  return toreturn;
}

int main() {
  ifstream reader("data.txt");
  string input, loc1, loc2;

  while(!reader.eof()){
    getline(reader,input,'-');
    loc1 = input;
    getline(reader,input);
    loc2 = input;

    if(loc1 != "start"){
      grid[loc2].push_back(loc1);
    }
    if(loc2 != "start"){
      grid[loc1].push_back(loc2);
    }
  }

  int toreturn=0;
  vector<string> path;
  int count = traverse(path,"start",false);
  cout<<totall<<"\n";
  
}