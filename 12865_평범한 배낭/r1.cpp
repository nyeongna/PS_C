#include <bits/stdc++.h>
using namespace std;

int dp[100002];

int main() {
    int n,k;
    cin >> n >> k;
    int i, j, w, v;
    for(i=0; i<n; i++) {
        cin >> w >> v;
        for(j=k; j-w>=0; j--) {
            dp[j] = max(dp[j-w]+v, dp[j]);
        }
    }
    // for(i=1; i<=k; i++) {
    //     cout << dp[i] << " ";
    // }
    cout << dp[k] << endl;
    return 0;
}