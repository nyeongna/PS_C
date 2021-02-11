#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

int n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> k;
    queue<int> Q;
    int i,j;
    for(i=1; i<=n; i++) {
        Q.push(i);
    }
    cout << "<";
    int cnt = k;
    while(Q.size()!=1) {
        cnt = k;
        while(--cnt) {
            Q.push(Q.front());
            Q.pop();
        }
        cout << Q.front() << ", ";
        Q.pop();
    }
    cout << Q.front() << ">" << endl;
    return 0;
}