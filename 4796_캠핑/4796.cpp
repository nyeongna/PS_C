#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

long long int L, P, V;
void getInput() {
    long long int total = 0;
    long long int cnt = 1;
    while (1) {
        total = 0;
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0) break;

        // V 값을 P로 "나눌수 있는 만큼 나눈값에 L을 곱한 것"을 카운트한다
        total = total + (V / P) * L;

        // 남은 휴가일수 V = (V를 P로 나눈 것) * (P)
        V = V - P * (V / P);

        // V가 더 크다면 정답에 L만큼 더해준다.
        if (V >= L) {
            total = total + L;
        }
        // L이 더 크다면 정담에 V만큼만 더해준다.
        else {
            total = total + V;
        }
        cout << "Case " << cnt << ": " << total << endl;
        cnt++;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    getInput();
    return 0;
}