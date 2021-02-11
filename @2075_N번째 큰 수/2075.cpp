#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    int i, j, k = pow(n, 2);
    int c;

    // 내림차순 정렬
    priority_queue<int, vector<int>, greater<int> > pq;

    for (i = 0; i < k; i++) {
        cin >> c;
        pq.push(c);
        if (pq.size() > n) pq.pop();
    }
    cout << pq.top() << endl;
    return 0;
}