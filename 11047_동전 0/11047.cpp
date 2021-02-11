#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    대표적인 동전 그리디 문제이다.

    동전의 종류가 "서로가 배수" 인 관계이므로 그리디로 풀 수 있다.
    작은 배수의 동전들은 큰 배수의 동전의 약수들이기 때문에,
    언제나 작은 배수의 곱으로 큰 동전을 표현할 수 있다.
    따라서, 작은 동전으로 표현이 가능하다면 큰 동전으로도 표현이 가능하다는 뜻이기 때문에
    먼저 큰 동전으로 표현을 해보고 남는 돈을 작은 돈으로 표현을 하는 식으로 접근을 하면 최소의 동전 개수를 찾을 수 있다.
*/


int N, K;
int coin[11];

void getInput() {
    cin >> N >> K;
    int i, j;
    for(i=0; i<N; i++) {
        cin >> coin[i];
    }
}

void Solve() {
    int i, j;
    int cnt=0;
    for(i=N-1; i>=0; i--) {
        if (K / coin[i] > 0) {
            cnt = cnt + K / coin[i];
            K = K % coin[i];
        }
        if (K==0) break;
    }
    cout << cnt << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    getInput();
    Solve();
    return 0;
}