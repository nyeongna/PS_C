#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

int coin[101];
int dp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int i, j;
    for (i = 1; i <= n; i++) {
        cin >> coin[i];
    }
    for (i = 1; i <= k; i++) {
        dp[i] = 2147000000;
    }

    dp[0] = 0;
    for (i = 1; i <= n; i++) {
        int value = coin[i];
        for (j = value; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - value] + 1);
        }
    }

    dp[k] == 2147000000 ? cout << -1 << endl : cout << dp[k] << endl;
    //cout << dp[n] << endl;

    return 0;
}