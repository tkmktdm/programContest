import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from collections import deque

# 迷路データ
maze_str = [
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
]

# 迷路のサイズ
N, M = len(maze_str), len(maze_str[0])

# 文字列を数値配列に変換（壁: -1, 通路: 0, スタート: 1, ゴール: 2）
maze = np.zeros((N, M), dtype=int)
sx, sy, gx, gy = 0, 0, 0, 0
for i in range(N):
    for j in range(M):
        if maze_str[i][j] == "#":
            maze[i][j] = -1  # 壁
        elif maze_str[i][j] == "S":
            maze[i][j] = 1
            sx, sy = i, j
        elif maze_str[i][j] == "G":
            maze[i][j] = 2
            gx, gy = i, j

# 4方向（右, 下, 左, 上）
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

# BFSの実装
def bfs():
    queue = deque([(sx, sy)])
    visited = np.full((N, M), np.inf)
    visited[sx, sy] = 0
    frames = [maze.copy()]

    while queue:
        x, y = queue.popleft()

        # ゴールに到達したら終了
        if (x, y) == (gx, gy):
            break

        # 4方向へ移動
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            # 範囲チェック & 移動可能か
            if 0 <= nx < N and 0 <= ny < M and maze[nx][ny] != -1 and visited[nx, ny] == np.inf:
                queue.append((nx, ny))
                visited[nx, ny] = visited[x, y] + 1
                maze[nx, ny] = 3  # 探索したマスを 3 でマーク
                frames.append(maze.copy())

    return frames

# アニメーション用のデータ
frames = bfs()

# アニメーションの描画
fig, ax = plt.subplots(figsize=(6, 6))
cmap = plt.get_cmap("coolwarm", 4)  # 色を設定（0=道, 1=S, 2=G, 3=探索）

def update(frame):
    ax.clear()
    ax.imshow(frame, cmap=cmap, vmin=-1, vmax=3)
    ax.set_xticks([])
    ax.set_yticks([])
    ax.set_title("BFS Maze Search")

ani = animation.FuncAnimation(fig, update, frames=frames, interval=300, repeat=False)

plt.show()

