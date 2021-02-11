#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int a[3][100002];
int dy[100002][3];
int n;

// status
// 0: 왼쪽 col 에서 아무것도 안 뗀 상태
// 1: 왼쪽 col 에서 위 쪽을 뗀 상태
// 2: 왼쪽 col 에서 밑 쪽을 뗸 상태

// Top-down에서
// dp[col][status] = 제일 오른쪽에서부터 col까지 스티커를 떼서 얻을 수 있는 가장 큰 수

// Bottom-up에서
// dp[col][status] = 제일 왼쪽부터 col개의 열에서 스티커를 떼고 오른쪽에서 status한 상태에서 얻을 수 있는 가장 큰 수
int F(int col, int status) {
    if (col == n + 1) return 0;
    if (dy[col][status] != -1) return dy[col][status];

    int ans = F(col + 1, 0);
    if (status != 1) ans = max(ans, F(col + 1, 1) + a[1][col]);
    if (status != 2) ans = max(ans, F(col + 1, 2) + a[2][col]);
    return dy[col][status] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int i, j, t;
    cin >> t;

    for (int z = 0; z < t; z++) {
        memset(dy, -1, sizeof(dy));
        cin >> n;
        for (i = 1; i <= 2; i++) {
            for (j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }
        //       (열, 상태)
        cout << F(1, 0) << endl;
    }

    return 0;
}