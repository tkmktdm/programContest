#include<stack>
#include<queue>
#include<cstdio>

using namespace std;

int main() {
  stack<int> s;
  s.push(1);
  s.push(2);
  printf("%d\n", s.top());
  s.pop();
  printf("%d\n", s.top());
  s.pop();

  queue<int> que;
  que.push(1);
  que.push(2);
  printf("%d\n", que.front());
  que.pop();
  printf("%d\n", que.front());
  que.pop();


  return 0;
}
