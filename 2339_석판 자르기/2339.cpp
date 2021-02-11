#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    ��������.
    ������ ��ƴ� ����
    8.30 �ٽ�Ǯ��
*/

int n;
int a[21][21];
struct Tile {
    int x, y;
};

void getInput() {
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
}
int Divide(int x1, int y1, int x2, int y2, int dir) {
    int i, j, cnt = 0;
    vector<Tile> dirty;

    for (i = x1; i <= x2; i++) {
        for (j = y1; j <= y2; j++) {
            if (a[i][j] == 1) dirty.push_back({ i,j });
            if (a[i][j] == 2) cnt++;
        }
    }
    // ������ ���� 0
    if (cnt == 0) return 0;

    // ������ ���� 1�� , �Ҽ��� 0��
    if (cnt == 1 && dirty.size() == 0) return 1;

    // ������ ���� 1��, �Ҽ��� 1�� �̻�
    if (cnt == 1 && dirty.size() != 0) return 0;

    // ������ ���� 2�� �̻�, �Ҽ��� 0��
    if (cnt >= 2 && dirty.size() == 0) return 0;

    // ������ ��Ȳ�� �� �������� �ȴ�.
    // ������ �ٸ��� '����'�� �������ٸ� ������ (������ ĭ�� ���� �����ϸ� �ȵ�)
    int res = 0;

    if (dir != 1) {
        int i, j, k;
        for (k = 0; k < dirty.size(); k++) {
            int flag = 1;
            int x_d = dirty[k].x;
            int y_d = dirty[k].y;
            for (i = y1; i <= y2; i++) {
                if (a[x_d][i] == 2) flag = 0;
            }
            if (flag == 1) {
                res = res + Divide(x1, y1, x_d - 1, y2, 1) * Divide(x_d + 1, y1, x2, y2, 1);
            }
        }
    }

    if (dir != 2) {
        int i, j, k;
        for (k = 0; k < dirty.size(); k++) {
            int flag = 1;
            int x_d = dirty[k].x;
            int y_d = dirty[k].y;
            for (i = x1; i <= x2; i++) {
                if (a[i][y_d] == 2) flag = 0;
            }
            if (flag == 1) {
                res = res + Divide(x1, y1, x2, y_d - 1, 2) * Divide(x1, y_d + 1, x2, y2, 2);
            }
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    getInput();
    int ans = Divide(1, 1, n, n, 0);
    if (ans == 0) {
        cout << -1 << endl;
    }
    else cout << ans << endl;

    return 0;
}