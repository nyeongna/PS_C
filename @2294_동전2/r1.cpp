#include <bits/stdc++.h>
using namespace std;
#define endl "\n";


int coins[101];
int dp[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k, i, j;
    cin >> n >> k;
    int a;

    for (i = 0; i < n; i++) {
        cin >> coins[i];
    }
    for (i = 0; i <= k; i++) {
        dp[i] = 2147000000;
    }
    dp[0] = 0;

    for (i = 0; i < n; i++) {
        int now = coins[i];
        // 동전 값이 k보다 크면 애초에 불가능하다.
        if (now > k) continue;
        for (j = now; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - now] + 1);
        }
        for(a=0; a<=k; a++) {
            cout << dp[a] << " ";
        }
        cout << endl;
    }

    if (dp[k] == 2147000000) cout << -1 << endl;
    if (dp[k] != 2147000000) cout << dp[k] << endl;
    //cout << dp[k] << endl;

    return 0;
}