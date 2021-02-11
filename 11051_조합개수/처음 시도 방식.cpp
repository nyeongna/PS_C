#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 10007

int n, r;
long long dp[1001];

int F(int n) {
    if (dp[n] != 0) return dp[n];
    if (n == 1) return 1;
    if (n == 2) return 2;

    return dp[n] = ((n % MOD) * (F(n - 1) % MOD)) % MOD;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> r;
    int up = F(n);
    int down = F(r);
    int down2 = F(n - r);

    cout << (up / down / down2) << endl;
    return 0;
}