#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

// F(n)의 return값은 n이 1로 가는데 필요한 최소 횟수이다.
int dp[1000001];

int F(int n) {
    if (dp[n] != -1) return dp[n];
    if (n == 1) return dp[1] = 0;

    int ans = 2147000000;
    ans = min(ans, F(n - 1) + 1);
    if (n % 3 == 0) ans = min(ans, F(n / 3) + 1);
    if (n % 2 == 0) ans = min(ans, F(n / 2) + 1);

    return dp[n] = ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << F(n) << endl;

    return 0;
}