#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

int coins[100];
int dp[100];
int n, k;

int F(int k) {
    int i, coin;
    if (k<0) return 0;
    if (k==0) return 1;
    if (dp[k]!=0) return dp[k];
    int ans = 0;
    for(i=0; i<n; i++) {
        coin = coins[i];
        dp[k] = dp[k] + F(k-coin);
    }
    return dp[k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> k;
    cin >> n;
    int i;
    for(i=0; i<n; i++) {
        cin >> coins[i];
    }
    cout << F(k) << endl;
    return 0;
}