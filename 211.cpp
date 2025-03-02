#include<cstdio>
#include<vector>
#include<iostream>
#include<queue>
#include<stack>

using namespace std;


int main() {
  int n = 4;
  // vector<int> a = {1,2,4,7};
  vector<int> a = {1,2,4,7};
  //int k=13;
  int k=15;
  //int k=3;

  queue<int> que;
  stack<int> s;
  int ans=k;
  
  for (int i=a.size()-1; i>=0; --i) {
    if (a[i] <= k) {
      ans = ans - a[i];
      cout << a[i] << " ";
      s.push(a[i]);
      if (ans == 0) {
        cout << "Yes" << " ";
        return 0;
      }
    }
  }
  cout << "No" << " ";
  return 0;
}
