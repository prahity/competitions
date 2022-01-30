#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void openstreams(){
  freopen("photo.in","r",stdin);
  freopen("photo.out","w",stdout);
}

int main(){
  openstreams();
  int cows;
  vector<int> bValues;
  vector<int> arrange;
  set<int> values;
  int nextA = 0;

  cin >> cows;
  for (int i=0; i < cows - 1; i++){
    int temp;
    cin >> temp;
    bValues.push_back(temp);
  }

  for (int i = 1; i < bValues[0];i++) {
    int a = i;
    arrange.clear();
    values.clear();
    values.insert(i);
    arrange.push_back(i);
    int length = 1;
    for(auto b : bValues){
      if (values.size() !=length) {
        break;
      }
      nextA = b - a;
      a = nextA;
      
      if(a > cows or a <= 0){
        break;
      }
      values.insert(nextA);
      length = length + 1;
      arrange.push_back(nextA);
    }
    if (values.size() == cows){
      break;
    }
  }
    for (int i=0; i < cows-1; i++){
    cout << arrange[i] << " ";
  }
  cout<< arrange[cows-1];
}