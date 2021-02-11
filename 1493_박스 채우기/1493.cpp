#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int l, w, h;
int n;

struct Cube {
    int side, num;
    bool operator<(const Cube& b) const {
        return side > b.side;
    }
};
vector<Cube> a;

void getInput() {
    cin >> l >> w >> h;
    cin >> n;
    int i, j, side, num;
    for (i = 0; i < n; i++) {
        cin >> side, num;
        a.push_back({ side, num });
    }
    sort(a.begin(), a.end());
}

void Solve() {
    int i, j;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    getInput();
    Solve();
    return 0;
}