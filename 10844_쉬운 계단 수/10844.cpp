#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000

int dp[101][10];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    int i, L;

    /*
        dp[n][L] = n자리의 숫자에서 L로 끝나는 숫자의 갯수
        dp[n][L] = dp[n-1][L-1] + dp[n-1][L+1] for L = 1~8
        dp[n][L] = dp[n-1][1] for L = 0
        dp[n][L] = dp[n-1][8] for L = 9
    */
    for (i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }
    dp[1][0] = 0;

    for (i = 2; i <= n; i++) {
        for (L = 0; L <= 9; L++) {
            if (L == 0) dp[i][L] = (dp[i - 1][1]) % MOD;
            else if (L == 9) dp[i][L] = (dp[i - 1][8]) % MOD;
            else           dp[i][L] = (dp[i - 1][L - 1] + dp[i - 1][L + 1]) % MOD;
        }
    }

    int ans = 0;
    for (i = 0; i <= 9; i++) {
        ans = (ans + dp[n][i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}