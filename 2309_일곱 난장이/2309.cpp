#include <bits/stdc++.h>
using namespace std;

int a[10];
int rec[10];

void getInput() {
    int i;
    for (i = 0; i < 9; i++) {
        cin >> a[i];
    }
}
void DFS(int s, int level) {
    int i;
    if (level == 7) {
        int total = 0;
        for (i = 0; i < 7; i++) {
            total += rec[i];
        }
        if (total == 100) {
            sort(rec, rec + 7);
            //cout << endl;
            for (i = 0; i < 7; i++) {
                cout << rec[i] << "\n";
            }
            exit(0);
        }
        return;
    }
    for (i = s; i < 9; i++) {
        rec[level] = a[i];
        DFS(i + 1, level + 1);
    }
}
void Solve() {
    DFS(0, 0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    getInput();
    Solve();
    return 0;
}