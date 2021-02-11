#include <bits/stdc++.h>
using namespace std;

int m, n, l;
int shot[100001];
pair<int, int> animal[100001];

void getInput() {
    cin >> m >> n >> l;
    int i, j;
    for (i = 1; i <= m; i++) {
        cin >> shot[i];
    }
    for (i = 1; i <= n; i++) {
        cin >> animal[i].first >> animal[i].second;
    }
    sort(shot + 1, shot + m + 1);
    sort(animal + 1, animal + n + 1);
}
int Calc(int g_left, int a_x, int a_y) {
    return abs(g_left - a_x) + a_y;
}
void Solve() {
    int i, j;
    int g_left = 1, g_right = 1;
    int cnt=0;
    for (i = 1; i <= n; i++) {
        while (g_left != m && shot[g_left + 1] < animal[i].first) {
            g_left++;
        }
        if (Calc(shot[g_left], animal[i].first, animal[i].second) <= l) {
            cnt++;
            continue;
        }
        if (g_left ==m) continue;
        if (Calc(shot[g_left+1], animal[i].first, animal[i].second) <= l) {
            cnt++;
            continue;
        }
    }
    cout << cnt << endl;
}
int main() {
    getInput();
    Solve();
    return 0;
}