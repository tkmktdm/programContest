#include<iostream>
using namespace std;

const int MAX_N = 100;
int a[MAX_N];
int n, k;

bool dfs(i, sum) {
  if (i == n) return sum == k;
  if (dfs(i+1, sum)) return true;
  if (dfs(i+1, sum+a[i])) return true;
  return false;
}


void solve() {
  if (dfs(0,0)) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main() {
  n = 4;
  k = 13;
  a = [1,2,4,7];
  solve();
  return 0;
}
