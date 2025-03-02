#include<iostream>

using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;
int N, M;
char field[MAX_N][MAX_M+1];

void dfs(int x, int y) {
  field[x][y] = '.';

  for (int dx = -1; dx<= 1; dx++) {
    for (int dy = -1; dy<= 1; dy++) {
      int nx = x + dx, ny = y + dy;
      // 範囲内かつ水たまりなら探索を続ける
      if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W') {
        printf("%d, %d\n", nx, ny);
        dfs(nx, ny);
      }
    }
  }
  return;
}

void solve() {
  int res = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (field[i][j] == 'W') {
        dfs(i, j);
        cout << i << endl;
        cout << j << endl;
        res++;
      }
    }
  }
  cout << res << endl;
}

int main()  {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> field[i];
  }
  solve();

  return 0;
}
