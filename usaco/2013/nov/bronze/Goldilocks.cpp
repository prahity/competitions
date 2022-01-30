
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void openstreams(){
  freopen("milktemp.in","r",stdin);
  freopen("milktemp.out","w",stdout);
}

class Temp {
  public:
    int value;
    bool low_med; // True if this is the low-med boundary. 
                  // False if this is the med-high boundary.
    Temp(int v, bool l) : value(v), low_med(l) {}

    bool operator < (Temp other) {
      if (value == other.value) {
        if ( low_med == true ) {
          return true;
        }
      }
      return (value < other.value);
    }

};


int main() 
{
  int numCows, lowTempProd, midTempProd, highTempProd;
  map<int, string> temp;
  vector<Temp> temps;
  openstreams();
  cin >> numCows >> lowTempProd >> midTempProd >> highTempProd;

  for (int i = 0; i < numCows; i++) {
    int lowT, highT;
    cin >> lowT >> highT;
    temps.push_back(Temp(lowT, true));
    temps.push_back(Temp(highT, false));
  }
  sort(temps.begin(), temps.end());

  int prod = numCows*lowTempProd;
  int maxProd = prod;
  for (auto temp : temps) {
    if (temp.low_med) {
      prod = prod - lowTempProd + midTempProd;
    } else {
      prod = prod - midTempProd + highTempProd;
    }
    if (maxProd < prod) {
      maxProd = prod;
    }
  }
  cout << maxProd << endl;
}

