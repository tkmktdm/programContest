#include <iostream>
using namespace std;

const int MAX_N = 100; // 適当に十分大きな値を設定
int a[MAX_N]; // 数列を格納する配列
int n, k;     // n: 配列の要素数, k: 目標の和

// i までで sum を作って、残り i 以降を調べる
bool dfs(int i, int sum) {
    // n 個決め終わったら、今までの和 sum が k と等しいかを返す
    printf("%d | %d\n", i, sum);
    // printf("%d\n", sum);
    if (i == n) {
      // printf("%d\n", i);
      return sum == k;
    }

    // a[i]を使わない場合
    if (dfs(i + 1, sum)) return true;

    // a[i]を使う場合
    if (dfs(i + 1, sum + a[i])) return true;

    // どちらでも k を作れなかった場合
    return false;
}

void solve() {
    if (dfs(0, 0)) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    // 例: n = 4, a = {1, 2, 4, 7}, k = 13
    n = 4;
    k = 13;
    int input[] = {1, 2, 4, 7};
    for (int i = 0; i < n; i++) a[i] = input[i];

    solve();
    return 0;
}

