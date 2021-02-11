#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int dy[2000000];

int F(int n) {
    if (dy[n]!=0) return dy[n];
    if (n==1) return 0;

    int min_ans = F(n-1)+1;
    if (n%3==0) min_ans = min(min_ans, F(n/3)+1);
    if (n%2==0) min_ans = min(min_ans, F(n/2)+1);
    
    return dy[n] = min_ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    cout << F(n) << endl;

    return 0;
}