#include <bits/stdc++.h>
using namespace std;

int deq[100002];
int f_idx;
int b_idx;

void Push(int num) {
    int i, j;
    for (i = b_idx; i > f_idx; i--) {
        deq[i] = deq[i - 1];
    }
    b_idx++;
    deq[f_idx] = num;
    //cout << deq[f_idx] << endl;
}

void Pull() {
    if (b_idx == 0) {
        cout << -1 << endl;
        return;
    }
    cout << deq[0] << endl;
    int i, j;
    for (i = 0; i < b_idx - 1; i++) {
        deq[i] = deq[i + 1];
    }
    b_idx--;
}
int main() {
    int n, i, j;

    string order;
    int num;
    cin >> n;

    for (i = 1; i <= n; i++) {
        cin >> order;
        //cout << order;
        if (order == "push_front") {
            cin >> num;
            Push(num);
        }
        else if (order == "push_back") {
            cin >> num;
            deq[b_idx++] = num;
        }
        else if (order == "pop_front") {
            Pull();
        }
        else if (order == "pop_back") {
            if (b_idx == 0) cout << -1 << endl;
            else {
                cout << deq[b_idx - 1] << endl;
                b_idx--;
            }
        }
        else if (order== "size") {
            cout << b_idx << endl;
        }
        else if (order == "empty") {
            int emp = b_idx==0 ? 1 : 0;
            cout << emp << endl;
        }
        else if (order=="front") {
            if (b_idx==0) cout << -1 << endl;
            else cout << deq[0] << endl;
        }
        else if (order=="back") {
            if (b_idx==0) cout << -1 << endl;
            else cout << deq[b_idx-1] << endl;
        }
        
        // for(int i=0; i<b_idx; i++) {
        //     cout << deq[i] << " ";
        // }
        // cout << endl;
    }
    return 0;
}