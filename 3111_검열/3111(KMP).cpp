#include <bits/stdc++.h>
using namespace std;

string target;
string s;

deque<char> DQ;
int LPS[30];

void getInput() {
    cin >> target;
    cin >> s;
}

void CreateLPS() {
    int len=0, i= 1;
    LPS[0] = 1;
    while (i < target.size()) {
        if (target[i] == target[len]) {
            LPS[i] = len+1;
            len++;
            i++;
        }
        else {
            LPS[i] = 0;
            i++;
        }
    }
    // cout << "CREATED LPS" << endl;
    // for(i=0; i<target.size(); i++) {
    //     cout << LPS[i] << " ";
    // }
    // cout << endl;
}

int KMPSearch() {
    int t_size = target.size();
    int s_size = s.size();
    int i=0, j=0;
    while (i < s_size) {
        if (s[i] == target[j]) {
            i++, j++;
        }
        else {
            if (j!=0)
                j = LPS[j-1];
            else
                i++;
        }
        if (j==t_size) {
            return i-j;
        }
    }
    return -1;
}
int KMPSearchBack() {
    int t_size = target.size();
    int s_size = s.size();
    int i=s_size-1, j=0;
    while (i >= 0) {
        if (s[i] == target[j]) {
            i--, j++;
        }
        else {
            if (j!=0)
                j = LPS[j-1];
            else
                i--;
        }
        if (j==t_size) {
            return ++i;
        }
    }
    return -1;
}

void Delete(int idx) {
    //cout << idx << endl;
    s.replace(idx, target.size(), "");
    //cout << s << endl;
}
void Solve() {
    int res;
    while(1) {
        
        res = KMPSearch();
        if (res==-1) break;
        else Delete(res);

        res = KMPSearchBack();
        if (res==-1) break;
        else Delete(res);

        break;
    }
    cout << s << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    getInput();
    CreateLPS();
    Solve();
    return 0;
}