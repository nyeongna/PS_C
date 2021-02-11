#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

long long int dp[1000001][2];
long long int dp2[1000001];
int n;

long long int F(int n, int status) {
    //cout << n << " " << status << endl;
    if (n==1 && status==0) return 1;
    if (n==1 && status==1) return 0;
    if (n==2 && status==0) return 1;
    if (n==2 && status==1) return 1;

    if (dp[n][status]!=-1) return dp[n][status];
    if (status==0) {
        return dp[n][status] = (F(n-2, 0)%15746 + F(n-1, 0)%15746) % 15746;
    }
    else {
        return dp[n][status] = (F(n-2, 1)%15746 + F(n-1, 1)%15746) % 15746;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(dp, -1, sizeof(dp));
    cin >> n;
    cout << (F(n, 0) + F(n,1))%15746 << endl;

    // dp2[0] = 1;
    // dp2[1] = 1;
    // dp2[2] = 2;
    // int i;
    // for(i=3; i<=n; i++) {
    //     dp2[i] = (dp2[i-1] % 15746 + dp2[i-2] % 15746)%15746;
    // }
    // cout << dp2[n] << endl;

    return 0;
}