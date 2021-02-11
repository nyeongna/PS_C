#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int T;
int tri[1001];

void Check(int target) {
    int i, j, k;
    for(i=1; i<=50; i++) {
        for(j=1; j<=50; j++) {
            for(k=1; k<=50; k++) {
                if (tri[i] + tri[j] + tri[k] == target) {
                    cout << 1 << endl;
                    return;
                }
            }
        }
    }
    cout << 0 << endl;
    return;
}

void Init() {
    int i, j;
    for (i = 1; i <= 1000; i++) {
        tri[i] = i * (i + 1) / 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    Init();
    
    cin >> T;
    int target;
    for (i = 0; i < T; i++) {
        cin >> target;
        Check(target);
    }
    return 0;
}