#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void openstreams(){
  freopen("cowroute.in","r",stdin);
  freopen("cowroute.out","w",stdout);
}
bool satisfy(vector<int> route, int A, int B){
  bool x = false;
  for(auto i : route){
    if(i == A){
      x = true;
    }
    if (i == B and x == true){
      return true;
    }
    if(i == B and x == false){
      return false;
    }
  }
  return false;
}
int main() {
  openstreams();
  int A,B,N;
  cin >> A >> B >> N;
  int minCost = 1001;
  vector<vector<int>> routes;
  vector<int> route;
  vector<int> cost;
  for(int i=0;i < N; i++){
    int temp;
    cin >> temp;
    cost.push_back(temp);
    cin >> temp;
    for(int j = 0; j < temp; j++){
      int temp2;
      cin >> temp2;
      route.push_back(temp2);
    }
    routes.push_back(route);
    route.clear();
  } 
  for (int i=0; i < N; i++){
    if(satisfy(routes[i],A,B)){
      if (cost[i] < minCost){
        minCost = cost[i];
      }
    }
  }
  if(minCost == 1001){
    minCost = -1;
  }
  cout << minCost;
}