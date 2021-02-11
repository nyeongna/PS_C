#include <bits/stdc++.h>
using namespace std;

// dp[n]�� n���� 1�� �� �� �ʿ��� �ּ� Ƚ���� ���������.
int dp[1000002];

int F(int n) {
    if (dp[n] != 0) return dp[n];
    if (n==1) return dp[1] = 0;

    int min_val = 2147000000;
    min_val = min(min_val, F(n-1) + 1);
    if (n%3==0) min_val = min(min_val, F(n/3)+1);
    if (n%2==0) min_val = min(min_val, F(n/2)+1);
    
    return dp[n] = min_val;
}
int main() {
    int n;
    cin >> n;

    int i;
    // DFS(n) �� n���� 1�� �� �� �ʿ��� �ּ� Ƚ��
    cout << F(n);
    
    return 0;
}