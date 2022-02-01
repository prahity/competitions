// http://www.usaco.org/index.php?page=viewproblem2&cpid=1059

#include <bits/stdc++.h>
using namespace std;

int main() {

  vector<int> numbers;

  for(int i=0; i<7; i++) {
    int temp;
    cin >> temp;
    numbers.push_back(temp);
    //cout << temp << endl;
  }
  sort(numbers.begin(), numbers.end());

  int abc = numbers[6];
  int bc = numbers[5];
  int ac = numbers[4];
  int a = abc - bc;
  int b = abc - ac;
  int c = abc - a - b;
  cout << a << " " << b << " " << c << endl;
  
}
