#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void openstreams(){
  freopen("greetings.in","r",stdin);
  freopen("greetings.out","w",stdout);
}

int main(){
  openstreams();
  int Bmove,Emove;
  cin >> Bmove >> Emove ;
  vector<int> B;
  vector<int> E;
  int bt =0,et =0;
  for(int i=0; i < Bmove; i++){
    int num;
    char ch;
    cin >> num >> ch;
    if (ch == 'L'){
      for(int i=0; i < num; i++){
        B.push_back(-1);
        bt++;
      }
    }
    if (ch == 'R'){
      for(int i=0; i < num; i++){
        B.push_back(1);
        bt++;
      }
    }
  }
  for(int i=0; i < Emove; i++){
    int num;
    char ch;
    cin >> num >> ch;
    if (ch == 'L'){
      for(int i=0; i < num; i++){
        E.push_back(-1);
        et++;
      }
    }
    if (ch == 'R'){
      for(int i=0; i < num; i++){
        E.push_back(1);
        et++;
      }
    }
  }
  int Bpos = 0, Epos = 0, count = 0;
  bool together = true;
  int maxt = max(et, bt);
  for(int i = 0; i < maxt; i++) {
    if ( i < bt) {
      Bpos += B[i];
    }
    if (i < et) {
      Epos += E[i];
    }
    if (together) {
      if (Bpos != Epos) {
        together = false;
      }
    } else {
      if (Bpos == Epos) {
        together = true;
        count++;
      }
    }
  }
  cout << count;
}
