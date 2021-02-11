#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    그리디 문제이다.
    컴퓨터 스케쥴링과 똑같은 알고리즘이다.
    1. 만약 콘센트가 모두 꽂힌 상태라면,
       콘센트에 꽂힌 기기 중에서 제일 마지막에 쓰이는 '기기'를 뽑으면 된다.
*/

int N, K;
int Order[101];
int socket[101];
int use[101];
int cnt;

void getInput() {
    cin >> N >> K;
    int i, j;
    for (i = 0; i < K; i++) {
        cin >> Order[i];
    }
}
void Print() {
    int i;
    for (i = 0; i < N; i++) {
        cout << socket[i] << " ";
    }
    cout << endl;
}
void Solve() {
    int i, j, k, idx = 0;
    int ans = 0;
    // K번 만큼 loop
    for (i = 0; i < K; i++) {
        // 기기가 콘센트에 이미 꽂혀 있다면 continue
        if (use[Order[i]] == 1) {
            int a = 1;
        }
        // 콘센트에 빈자리가 있다면
        else if (idx < N) {
            socket[idx] = Order[i];
            use[Order[i]] = 1;
            idx++;
            //continue;
        }
        // 콘센트에서 기기 교체를 해야함. 즉 ans++
        else {
            ans++;
            int FarDist = 0;
            int device = 0;

            // 콘센트에 꽂혀 있는 모든 기기에 대해서 "제일 마지막에 쓰이는 기기"를 찾아야함.
            for (j = 0; j < N; j++) {
                // 다음 순번이 없어서 또 안쓰인다면 dist = INF 로 되야함.
                int dist = 2147000000;
                for (k = i + 1; k < K; k++) {
                    // 기기가 또 쓰인다면 dist를 갱신
                    if (socket[j] == Order[k]) {
                        dist = k;
                        break;
                    }
                }
                // 만약 dist가 지금까지 발견한 최대 거리보다 길다면 FarDist를 갱신
                if (dist > FarDist) {
                    FarDist = dist;
                    // 콘센트의 교체 되어야할 자리가 "j" 이므로 기록해준다.
                    device = j;
                }
            }

            // 제일 늦게 쓰인(거리가 길어던) 기기를 뽑고
            use[socket[device]] = 0;

            // 새로운 기기를 꽂는다.
            use[Order[i]] = 1;
            socket[device] = Order[i];

        }
        //Print();
    }

    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    getInput();
    Solve();
    return 0;
}