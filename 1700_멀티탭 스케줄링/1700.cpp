#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int N, K;
int use_order[101];
int socket[101];
int visit[101];
int cnt;

void getInput() {
    cin >> N >> K;
    int i, j;
    for (i = 0; i < K; i++) {
        cin >> use_order[i];
    }
}
void Print() {
    int i;
    for(i=1; i<=K; i++) {
        if (socket[i]==1) cout << i << " ";
    }
    cout << endl;
}
void Solve() {
    int i, j, current, total=0;
    for (i = 0; i < K; i++) {
        current = use_order[i];
        //cout << i << endl;
        
        // 이미 콘센트에 꽂혀 있다면 continue
        if (socket[current] == 1) {
            int a =1;
        }

        // 빈 콘센트가 있다면
        else if (cnt < N) {
            socket[current] = 1;
            cnt++;
        }

        // 콘센트가 꽉 차서 하나를 뽑아야 하는 상황이라면
        else if (cnt == N) {
            total++;
            vector<int> history;
            memset(visit, 0, sizeof(visit));
            for (j = i + 1; j < K; j++) {
                int cur = use_order[j];
                if (socket[cur] == 1 && visit[cur] == 0) {
                    visit[cur] = 1;
                    history.push_back(cur);
                }
            }
            if (history.size() != cnt) {
                for (j = 1; j <= K; j++) {
                    if (socket[j]==1 && visit[j]==0) {
                        socket[j] = 0;
                        socket[current] = 1;
                        break;
                    }
                }
            }
            else {
                socket[history[cnt-1]] = 0;
                socket[current] = 1;
            }
        }
        //Print();
    }
    cout << total << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    getInput();
    Solve();
    return 0;
}