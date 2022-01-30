#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void openstreams(){
  freopen("scramble.in","r",stdin);
  freopen("scramble.out","w",stdout);
}

class cow {
public:
  string name;
  bool is_name_reversed;
  int original_index;

  cow(string n, bool r, int i) {
    name = n;
    is_name_reversed = r;
    original_index = i;
  }
  bool operator < (struct cow other) {
    return ( name < other.name);
  }
};

int main(){
  openstreams();
  int numCows;
  vector<cow> cows;
  cin >> numCows;
  for(int i=0; i<numCows; i++) {
    string name;
    cin >> name;
    sort(name.begin(),name.end());
    cow tmp1(name, false, i);
    cows.push_back(tmp1);
    reverse(name.begin(), name.end());
    cow tmp2(name, true, i);
    cows.push_back(tmp2);
  }
  sort(cows.begin(), cows.end());

  int min[numCows];
  int max[numCows];

  int numSortedCowsSeen = 0;
  int numReverseSortedCowsSeen = 0;
  for (int i=0; i<2*numCows; i++) {
    int index = cows[i].original_index;
    bool reversed = cows[i].is_name_reversed;
    if (reversed) {
      numReverseSortedCowsSeen++;
    } else {
      numSortedCowsSeen++;
    }
    if (reversed) {
      max[index] = numSortedCowsSeen;
    } else {
      min[index] = numReverseSortedCowsSeen + 1;
    }
  }
  for (int i=0; i<numCows; i++) {
    cout << min[i] << " " << max[i] << endl;
  }
}
