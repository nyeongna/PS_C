#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int dp[1001];
int n;
int cnt;

int F(int col) {
    if (col == 1) return 1;
    if (col == 2) return 2;
    if (dp[col] != 0) return dp[col];
    return dp[col] = (F(col - 1) % 10007 + F(col - 2) % 10007) % 10007;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    cout << F(n) << endl;

    return 0;
}