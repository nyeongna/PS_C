#include <bits/stdc++.h>
using namespace std;

int N;
int a[21][21];

void getInput() {
    cin >> N;
    int i, j;
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            cin >> a[i][j];
        }
    }

}
int Divide(int x1, int y1, int x2, int y2, int dir) {
    vector<pair<int, int>> dirty;
    int i, j, k, cnt = 0;
    // 지금 x1~x2, y1~y2 공간에 불순물 개수와 위치 저장.
    for (i = x1; i <= x2; i++) {
        for (j = y1; j <= y2; j++) {
            if (a[i][j] == 1) dirty.push_back({ i,j });
            if (a[i][j] == 2) cnt++;
        }
    }
    // 결정체 없으면 0
    if (cnt == 1 && dirty.size() == 0) return 1;
    // 결정체 개수 = 불순물 + 1  이 아니면 return 0이다.ㅛ
    if (cnt != dirty.size() + 1) return 0;

    // 여기까지 온 경우면 나눠본다.
    int ans = 0;
    for (k = 0; k < dirty.size(); k++) {
        int _x = dirty[k].first;
        int _y = dirty[k].second;
        int flag;
        // dir 0 아니면 2 일때 (처음 자르거나, 전에 자른게 세로였을 때)
        if (dir != 1) {
            flag = 1;
            for (int i = y1; i <= y2; i++) {
                if (a[_x][i] == 2) flag = 0;
            }
            if (flag) ans = ans + Divide(x1, y1, _x - 1, y2, 1) * Divide(_x + 1, y1, x2, y2, 1);
        }
        // dir 0 아니면 1일때 (처음 자르거나, 전에 자른게 가로 였을 때)
        if (dir != 2) {
            flag = 1;
            for (int i = x1; i <= x2; i++) {
                if (a[i][_y] == 2) flag = 0;
            }
            if (flag) ans = ans + Divide(x1, y1, x2, _y - 1, 2) * Divide(x1, _y + 1, x2, y2, 2);
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    getInput();
    int ans = Divide(1, 1, N, N, 0);
    if (ans == 0) cout << -1 << endl;
    else cout << ans << endl;
}