#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000

int dp[100001];
int w[101];
int v[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    int i, j;
    for (i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    for (i = 1; i <= n; i++) {
        int weight = w[i];
        for (j = k; j - weight >= 0; j--) {
            dp[j] = max(dp[j], dp[j - weight] + v[i]);
        }
    }
    cout << dp[k] << endl;
    return 0;
}