#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int a[1001];
int visit[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N, L;
    cin >> N >> L;
    int i, j;
    for(i=0; i<N; i++) {
        cin >> a[i];
    }
    sort(a, a+N);
    int cnt=0;
    for(i=0; i<N; i++) {
        if (visit[a[i]]==0) {
            int limit = a[i]+L-1;
            for(j=a[i]; j <= min(limit, 1000); j++) {
                visit[j]=1;
            }
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}