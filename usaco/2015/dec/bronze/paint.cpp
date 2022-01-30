#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void openstreams(){
  freopen("paint.in","r",stdin);
  freopen("paint.out","w",stdout);
}
int getLength(int a, int b, int c,int d){
  if((c <= a and d <= a) or (c >= b and d >=b)){
    return ((b-a + d-c));
  }
  if((a <= d and b <= d) and (a >= c and b >=c)){
    return ((d-c));
  }
  if(c >= a and d <= b){
    return ( b-a);
  }
  if(c <= b and c >= a){
    return (d-a);
  }
  if(d <= b and d >= a){
    return (b-c);
  }
  return 0;
}

int main() {
  int a,b,c,d;
  openstreams();
  cin >> a;
  cin >> b;
  cin >> c;
  cin >> d; 
  int length = getLength(a,b,c,d);
  cout << length;
}
