#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

int board[2][100001];
int dp[3][1000001];
int n;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    int i, j,k;
    for(i=0; i<t; i++) {
        cin >> n;
        memset(dp, -1, sizeof(dp));
        for(j=0; j<2; j++) {
            for(k=0; k<n; k++) {
                cin >> board[j][k];
            }
        }
        dp[0][0] = board[0][0];
        dp[1][0] = board[1][0];
        dp[0][1] = board[1][0] + board[0][1];
        dp[1][1] = board[0][0] + board[1][1]; 
        for(k=2; k<n; k++) {
            dp[0][k] = max(dp[1][k-1], dp[1][k-2]) + board[0][k];
            dp[1][k] = max(dp[0][k-1], dp[0][k-2]) + board[1][k];
        }
        cout << max(dp[0][n-1], dp[1][n-1]) << endl;
    }

    return 0;
}