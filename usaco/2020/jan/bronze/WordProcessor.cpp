// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=987
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void openstreams(){
  freopen("word.in","r",stdin);
  freopen("word.out","w",stdout);
}

int main(){
  openstreams();
  int totalWords,lineWords;
  cin >> totalWords >> lineWords;
  vector<string> words;
  for (int i=0; i < totalWords; i++){
    string temp;
    cin >> temp;
    words.push_back(temp);
  }
  int left = lineWords;
  bool begin = true;
  for(auto word : words){
    if (begin) {
      if(left >= word.size()){
        left = left - word.size();
        cout << word;
        begin = false;
      } else {
        break;
      }
    } else {
      if(left >= (word.size())){
        cout << " " << word;
        left = left - (word.size());
      } else {
        cout << "\n";
        begin = false;
        left = lineWords;
        cout << word;
        left = left - (word.size());
      }
    }
  }
}
