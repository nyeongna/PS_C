#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int a[3][100002];
int dy[100002][3];
int n;

// status
// 0: ���� col ���� �ƹ��͵� �� �� ����
// 1: ���� col ���� �� ���� �� ����
// 2: ���� col ���� �� ���� �� ����

// Top-down����
// dp[col][status] = ���� �����ʿ������� col���� ��ƼĿ�� ���� ���� �� �ִ� ���� ū ��

// Bottom-up����
// dp[col][status] = ���� ���ʺ��� col���� ������ ��ƼĿ�� ���� �����ʿ��� status�� ���¿��� ���� �� �ִ� ���� ū ��
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
        //       (��, ����)
        cout << F(1, 0) << endl;
    }

    return 0;
}