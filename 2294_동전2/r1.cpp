#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

int coins[102];
int dp[10001];
int n;

int DFS(int k) {
    if (k==0) {
        return dp[k] = 0;
    }
    if (k < 0) {
        return 1e9;
    }
    if (dp[k] != 0) return dp[k];
    int i;
    int val=1e9;
    for(i=0; i<n; i++) {
        val = min(val, DFS(k-coins[i] ) + 1);
    }
    return dp[k] = val;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int k;
    cin >> n >> k;
    int i;
    for(i=0; i<n; i++) {
        cin >> coins[i];
    }
    int ans = DFS(k);
    ans==1e9 ? cout << -1 << endl : cout << dp[k] << endl;
    //cout << DFS(k) << endl;
    return 0;    
}