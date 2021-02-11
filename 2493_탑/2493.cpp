#include <bits/stdc++.h>
using namespace std;

int n;
int graph[500001];
int visit[500001];
int ans[500001];

void getInput() {
    cin >> n;
}
void Solve() {
    int i, j, idx=1, num;
    stack<pair<int, int>> Stk;
    cin >> num;
    cout << 0 << " ";
    Stk.push({ num, 1 });

    for (i=2; i<=n; i++) {
        cin >> num;
        while (!Stk.empty()) {
            if (Stk.top().first > num) {
                break;
            }
            Stk.pop();
        }
        if (Stk.empty()) cout << 0 << " ";
        else cout << Stk.top().second << " ";
        Stk.push({ num, i });
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    getInput();
    Solve();
    return 0;
}