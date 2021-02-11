#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000

string s;
int n;
string a[101];
int visit[101];

void F(int idx) {
    if (idx==s.size()) {
        visit[idx]=1;
        return;
    }
    if (visit[idx] != 0) return;
    if (idx > s.size()) return;
    int i, j, flag = 1;

    for (i = 0; i < n; i++) {
        flag = 1;
        if (s.size()-idx < a[i].size()) continue;
        for (j = 0; j < a[i].size(); j++) {
            if (s[idx + j] != a[i][j]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            visit[idx] = 1;
            F(idx + a[i].size());
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> s;
    cin >> n;
    int i, j, k, flag = 1;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    F(0);
    if (visit[s.size()] == 1) cout << 1 << endl;
    else cout << 0 << endl;


    return 0;
}