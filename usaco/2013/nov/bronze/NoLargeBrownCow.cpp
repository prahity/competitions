#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void openstreams(){
  freopen("nocow.in","r",stdin);
  freopen("nocow.out","w",stdout);
}

int getNoCowsBeforeK (vector<string> &lineAdjs, string kthString) {
   int numNoCows = 0;
   for (auto line: lineAdjs) {
     //cout << line << ":" << kthString << ":" << (line < kthString) << endl;
     if ( line <= kthString) {
       numNoCows++;
     }
   }
   return numNoCows;
 }

vector<int> getKthSpot(vector<int> &positionSetCount, 
                      int totalCombinations, int numPositions,
                      int k) {
  vector<int> result;
  int i=0;
  int batchCount = totalCombinations;
  k = k -1; // Index starts at 0. Cow at Index 0 is 1st cow.
  while (i<numPositions) {
    batchCount = batchCount / positionSetCount[i];
    int offset;
    if (k > 0){
      offset = k / batchCount;
    } else {
      offset = 0;
    }
    result.push_back(offset);
    k = k - (offset * batchCount);
    i++;
  }
  return result;
}

string getKthString(vector<vector<string>> &adjs, vector<int> offsets) {
  string result;
  int pos = 0;
  for (auto offset: offsets) {
    result += adjs[pos][offset] + " ";
    pos++;
  }
  result.pop_back(); // Remove last char
  return result;
}

int main() 
{
  int numLines, indexK, numPositions;
  vector<string> lineAdjs;
  vector<set<string>> posAdjs;
  vector<vector<string>> posAdjsVector;
  int totalCombinations = 1;
  openstreams();

  cin >> numLines >> indexK;

  for (int i=0; i<numLines; i++) {
    string lineAdj = "";
    int position = 0;
    string farmer, john, has, no, adj;
    cin >> farmer >> john >> has >> no >> adj;
    while (adj != "cow.") {
      // If this is the first line, create the set
      if (i == 0) {
        set<string> tmp;
        posAdjs.push_back(tmp);
      }
      posAdjs[position].insert(adj);
      lineAdj += (adj + " ");
      position++;
      cin >> adj;
    }
    lineAdj.pop_back();
    lineAdjs.push_back(lineAdj);
    numPositions = position;
  }
  for (auto posAdj : posAdjs) {
    vector<string> temp;
    for (auto adj : posAdj) {
      temp.push_back(adj);
    }
    posAdjsVector.push_back(temp);
  }

  // At each position, find the set size
  // For the sample example, this will be 2,3,2
  vector<int> positionSetCount;
  for (int i=0; i<numPositions; i++) {
    int count = posAdjs[i].size();
    positionSetCount.push_back(count);
    totalCombinations *= count;
    //cout << posAdjs[i].size() << "\t";
  }
  //cout << endl;
  
  //Check the work so far...
  /*
  for (int k=1; k<=totalCombinations; k++) {
    vector<int> kthSpot;
    kthSpot = getKthSpot(positionSetCount, totalCombinations, numPositions, k);
    cout << k << "\t:\t";
    for(int i=0; i<kthSpot.size(); i++) {
      cout << kthSpot[i] << "\t";
    }
    string kthString = getKthString(posAdjsVector, kthSpot);
    cout << kthString;
    cout << endl;
  }
  */
  int RealK = indexK;
  int numNoCowsBeforeK;
  string kthString;
  bool iterate = false;
  do {
    vector<int> kthSpot;
    kthSpot = getKthSpot(positionSetCount, totalCombinations, numPositions, RealK);
    kthString = getKthString(posAdjsVector, kthSpot);
    numNoCowsBeforeK = getNoCowsBeforeK(lineAdjs, kthString);
    if ((RealK-indexK) < numNoCowsBeforeK) {
      RealK++;
      iterate = true;
    } else {
      iterate = false;
    }
  } while (iterate);
  //cout << numNoCowsBeforeK << endl;
  cout << kthString << endl;
}
