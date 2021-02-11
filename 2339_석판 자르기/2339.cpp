#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    분할정복.
    종나게 어렵다 ㅋㅋ
    8.30 다시풀자
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
    // 보석의 갯수 0
    if (cnt == 0) return 0;

    // 보석의 개수 1개 , 불순물 0개
    if (cnt == 1 && dirty.size() == 0) return 1;

    // 보석의 개수 1개, 불순물 1개 이상
    if (cnt == 1 && dirty.size() != 0) return 0;

    // 보석의 개수 2개 이상, 불순물 0개
    if (cnt >= 2 && dirty.size() == 0) return 0;

    // 나머지 상황은 더 나눠봐야 안다.
    // 이전과 다르게 '가로'로 나눠진다면 나눈다 (나누는 칸에 보석 존재하면 안됨)
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