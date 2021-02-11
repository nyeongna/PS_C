#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int


// dp[x]는 n에서 x로 가는 최단거리
int dp[3000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n,i;
    cin >> n;
    for(i=2; i<=n; i++) {
        dp[i] = 2147000000;
    }
    dp[1] = 0;
    for(i=1; i<=n; i++) {
        dp[i+1] = min(dp[i+1], dp[i] + 1);
        dp[i*2] = min(dp[i*2], dp[i] + 1);
        dp[i*3] = min(dp[i*3], dp[i] + 1);
    }
    cout << dp[n] << endl;

    return 0;
}