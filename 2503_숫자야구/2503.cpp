#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

struct Set {
    int num, s, b;
};
vector<Set> a;

int ans = 0;

void Check(int f, int s, int t) {
    int i;
    int F, S, T;
    int strike = 0, ball = 0, flag = 1;
    for (i = 0; i < a.size(); i++) {
        strike=0, ball=0;

        F = (a[i].num / 100) % 10;
        S = (a[i].num / 10) % 10;
        T = (a[i].num / 1) % 10;

        if (f == F) strike++;
        if (f == S) ball++;
        if (f == T) ball++;

        if (s == S) strike++;
        if (s == F) ball++;
        if (s == T) ball++;
        
        if (t == T) strike++;
        if (t == F) ball++;
        if (t == S) ball++;
        if (strike != a[i].s || ball != a[i].b) flag = 0;
        // if (f == 3 && s == 2 && t == 4) {
        //     cout << F << S << T << endl;
        //     cout << strike << " " << a[i].s << " " << ball << " " << a[i].b << endl;
        // }
    }
    //if (f == 3 && s == 2 && t == 4) exit(0);
    if (flag) ans++;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N, i, j, k, z;
    int num, s, b;
    cin >> N;

    for (z = 1; z <= N; z++) {
        cin >> num >> s >> b;
        a.push_back({ num,s,b });
    }

    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= 9; j++) {
            if (i == j) continue;
            for (k = 1; k <= 9; k++) {
                if (k == i || k == j) continue;
                Check(i, j, k);
            }
        }
    }
    cout << ans << endl;
    return 0;
}