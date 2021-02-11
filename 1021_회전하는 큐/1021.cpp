#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

int n, m, a[51];
deque<int> DQ;

void Print() {
    for(int i=0; i<DQ.size(); i++) {
        cout << DQ[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int i, j;
    for (i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for (i = 1; i <= n; i++) {
        DQ.push_back(i);
    }

    int step = 0;
    for (i = 1; i <= m; i++) {
        int target = a[i];
        auto loc = find(DQ.begin(), DQ.end(), a[i]);
        int dist = loc-DQ.begin()+1;
        //cout << dist << endl;
        // 왼쪽으로 움직임
        if (dist <= DQ.size()/2+1) {
            for(j=1; j<=dist-1; j++) {
                DQ.push_back(DQ.front());
                DQ.pop_front();
                step++;
            }
            //Print();
        }
        else {
            for(j=1; j<=DQ.size()-dist+1; j++) {
                DQ.push_front(DQ.back());
                DQ.pop_back();
                step++;
            }
            //Print();
        }
        DQ.pop_front();
        //Print();
    }
    cout << step << endl;



    return 0;
}