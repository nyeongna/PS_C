#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

int n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    int i, a;
    deque<pair<int,int>> Q;
    for(i=1; i<=n; i++) {
        cin >> a;
        Q.push_back({i,a});
    }
    while (!Q.empty()) {
        int step = Q.front().second;
        cout << Q.front().first << " ";
        Q.pop_front();
        if (step>0) {
            while(--step) {
                Q.push_back(Q.front());
                Q.pop_front();
            }
        }
        else {
            while(step++ < 0) {
                Q.push_front(Q.back());
                Q.pop_back();
            }
        }
    }


    return 0;
}