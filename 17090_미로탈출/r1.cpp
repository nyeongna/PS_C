#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

char board[501][501];
int dp[501][501];
int r, c;

int DFS(int x, int y) {
    if (x < 1 || x > r || y < 1 || y > c) return 1;
    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;
    char c = board[x][y];

    if (c == 'D') {
        return dp[x][y] = DFS(x + 1, y);
    }
    else if (c == 'U') {
        return dp[x][y] = DFS(x - 1, y);
    }
    else if (c == 'L') {
        return dp[x][y] = DFS(x, y - 1);
    }
    else if (c == 'R') {
        return dp[x][y] = DFS(x, y + 1);
    }
}

void Print(int x, int y) {
    int i, j;
    cout << endl;
    cout << x << " " << y << endl;
    for (i = 1; i <= r; i++) {
        for (j = 1; j <= c; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int i, j, ans = 0;
    cin >> r >> c;
    for (i = 1; i <= r; i++) {
        for (j = 1; j <= c; j++) {
            cin >> board[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    for (i = 1; i <= r; i++) {
        for (j = 1; j <= c; j++) {
            // 방문 안 한 타일이면 DFS 실행
            if (dp[i][j] == -1) {
                DFS(i, j);
                //Print(i,j);
                ans += dp[i][j];
            }
            // 방문 이미 해봐서 결과를 아는 타일이면 결과만 더해준다(0이면 불가능, 1이면 가능)
            else ans = ans + dp[i][j];
        }
    }
    cout << ans << endl;


    return 0;
}