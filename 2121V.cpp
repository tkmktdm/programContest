#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

const int INF = 100000000;
typedef pair<int, int> P;

// 迷路のサイズ
const int MAX_N = 10;
const int MAX_M = 10;

// 迷路データ
char maze[MAX_N][MAX_M + 1] = {
    "#S######.#",
    "......#..#",
    ".#.##.##.#",
    ".#........",
    "##.##.####",
    "....#....#",
    ".#######.#",
    "....#.....",
    ".####.###.",
    "....#...G#"
};

int N = 10, M = 10;
int sx, sy, gx, gy;  // スタート地点、ゴール地点の座標
int d[MAX_N][MAX_M]; // 各点までの最短距離

// 移動4方向（右、下、左、上）
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// 幅優先探索（BFS）
int bfs() {
    queue<P> que;

    // すべての点をINFで初期化
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            d[i][j] = INF;
            if (maze[i][j] == 'S') {
                sx = i, sy = j;
            }
            if (maze[i][j] == 'G') {
                gx = i, gy = j;
            }
        }
    }

    // スタート地点をキューに入れ、その点の距離を0にする
    que.push(P(sx, sy));
    d[sx][sy] = 0;

    // キューが空になるまでループ
    while (!que.empty()) {
        P p = que.front();
        que.pop();

        // ゴールにたどり着いたら終了
        if (p.first == gx && p.second == gy) {
            break;
        }

        // 移動4方向をループ
        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            // 範囲チェック、移動可能か、すでに訪問済みか
            if (0 <= nx && nx < N && 0 <= ny && ny < M &&
                maze[nx][ny] != '#' && d[nx][ny] == INF) {
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }

    return d[gx][gy];
}

// 最短距離表を出力する関数
void print_distance_map() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (d[i][j] == INF) {
                cout << " XX";  // 壁または到達不可
            } else {
                printf("%3d", d[i][j]); // 見やすく整列
            }
        }
        cout << endl;
    }
}

// 解を求める関数
void solve() {
    int res = bfs();
    cout << "最短距離: " << res << endl;
    cout << "探索結果（最短距離マップ）:" << endl;
    print_distance_map();
}

// メイン関数
int main() {
    solve();
    return 0;
}

