#include <iostream>
#include <queue>
using namespace std;

#define MAX_N 10
#define MAX_M 10
const int INF = 100000000;

typedef pair<int, int> P;

// 迷路のデータ
char maze[MAX_N][MAX_M + 1];
int d[MAX_N][MAX_M];

int N = 10, M = 10;
int sx, sy, gx, gy;

// 4方向の移動ベクトル
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

// 幅優先探索（BFS）
int bfs() {
    queue<P> que;

    // すべてのマスを INF で初期化
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            d[i][j] = INF;

    // スタート地点をキューに追加
    que.push(P(sx, sy));
    d[sx][sy] = 0;

    while (!que.empty()) {
        P p = que.front();
        que.pop();

        // ゴールに到達したら終了
        if (p.first == gx && p.second == gy) break;

        // 4方向を試す
        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            // 移動可能かチェック
            if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF) {
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }

    return d[gx][gy];
}

int main() {
    // 迷路の入力
    for (int i = 0; i < N; i++) {
        cin >> maze[i];
    }

    // S と G の座標を取得
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (maze[i][j] == 'S') { sx = i; sy = j; }
            if (maze[i][j] == 'G') { gx = i; gy = j; }
        }
    }

    // BFS を実行
    int res = bfs();

    // 結果を表示
    cout << res << endl;

    return 0;
}

