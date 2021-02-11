#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

int T, n;
int board[3][100001];
int dp[100001][3];

// Top-down����
// dp[col][status] = ���� �����ʿ������� col���� ��ƼĿ�� ���� ���� �� �ִ� ���� ū ��(status�� col�ٷ� ������ ����)

// status: 0, ���� col���� �ƹ��͵� ���� ����
// status: 1, ���� col���� ���� ����
// status: 2, ���� col���� �Ʒ� ����
int F(int col, int status) {
    if (dp[col][status] != -1) return dp[col][status];
    if (col == n) return 0;
    
    int ans = F(col + 1, 0);
    if (status != 1)  ans = max(ans, F(col + 1, 1) + board[0][col]);
    if (status != 2)  ans = max(ans, F(col + 1, 2) + board[1][col]);
    
    return dp[col][status] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    int i, j;

    while (T--) {
        cin >> n;
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        for (i = 0; i < 2; i++) {
            for (j = 0; j < n; j++) {
                cin >> board[i][j];
            }
        }
        cout << F(0, 0) << endl;
    }
    for(i=0; i<=n; i++) {
        for(j=0; j<=2; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}