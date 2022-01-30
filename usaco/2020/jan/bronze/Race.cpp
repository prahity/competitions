#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void openstreams(){
  freopen("race.in","r",stdin);
  freopen("race.out","w",stdout);
}

long int case1(long int travelled,long int speed,long int X,long int distance){
  long int k;
  k = ceil((-1 + sqrt(1+ 8 * distance))/2);
  return k;
}

long int case2(long int travelled,long int speed,long int X,long int distance){
  long int k;
  k = X*(X-1)/2;
  long int count = X;
  long int time = X-1;
  while(k < distance){
    if ((k + count) >= distance ){
      time = time +1;
      break;
    } else {
      k  += count;
      time += 1;
    }
    if ((k + count) >=distance ){
      time += 1;
      break;
    } else {
      k  = k + count;
      count += 1;
      time+=1;
    }
  }
  return time;
}

int main(){
  openstreams();
  long int distance;
  long int inputs;
  cin >> distance >> inputs;
  for (long int i=0; i < inputs; i++){
    long int time = 0; long int speed = 0; long int travelled = 0;long int X;
    cin >> X;
    if(X*(X+1) > (2 * distance)){
      time = case1(travelled,speed,X,distance);
    }
    else{
      time = case2(travelled,speed,X,distance);
    }
    cout << time << endl;
  }
}
