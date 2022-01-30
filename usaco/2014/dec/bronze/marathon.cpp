#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void openstreams(){
  freopen("marathon.in","r",stdin);
  freopen("marathon.out","w",stdout);
}
class Point{
  public:
    int x;
    int y;

    Point(int xValue, int yValue){
      x = xValue;
      y = yValue;
    }
};
int distance(Point p1, Point p2){
  return abs(p1.x-p2.x) + abs(p1.y - p2.y);
}
int main() {
  openstreams();
  int checkpoints;
  cin >> checkpoints;
  vector<Point> points;
  for(int i=0; i < checkpoints;  i++){
    int x,y;
    cin >> x;
    cin >> y;
    points.push_back(Point(x,y));
  }
  /*for(int i = 0; i < checkpoints; i++){
    cout << points[i].x << " " << points[i].y << endl;
  }*/
  int saved = distance(points[0],points[1]) + distance(points[1],points[2]) - distance(points[0],points[2]);
  int index=0;
  int count = 0;
  for(int i = 1; i < checkpoints-2; i++){
    count++;
    int nextSaved = distance(points[i],points[i + 1]) + distance(points[i + 1],points[i + 2]) - distance(points[i],points[i + 2]);
    if (nextSaved > saved){
      index = count;
      saved = nextSaved;
    }
  }
  int totDist=0;
  for(int i = 0; i < checkpoints-1; i++){
    totDist += distance(points[i],points[i + 1]);
  }
  int dist = totDist - saved;
  cout << dist << endl;
  
}

