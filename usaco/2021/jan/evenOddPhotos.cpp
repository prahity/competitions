// http://www.usaco.org/index.php?page=viewproblem2&cpid=1084

#include <bits/stdc++.h>
#include <string>
using namespace std;


int main() {
  int numCows;
  cin >> numCows;
  int numOdd = 0;
  int numEven = 0;

  for (int i =0; i < numCows;i++){
    int temp;
    cin >> temp;
    if(temp % 2 == 0){
      numEven++;
    }else{
      numOdd++;
    }
  }
  //cout << "numEven = " << numEven << " numOdd = " << numOdd << endl;
  while (numEven < numOdd - 1){
    numOdd = numOdd -2;
    numEven = numEven + 1;
  }
  if (numEven >= numOdd + 1){
    cout << 2* numOdd +1;
    return 0;
  }
  if (numEven == numOdd){
    cout << 2 * numEven;
    return 0;
  }
  if (numEven == numOdd -1){
    cout << 2 * numEven -1;
    return 0;
  }
}