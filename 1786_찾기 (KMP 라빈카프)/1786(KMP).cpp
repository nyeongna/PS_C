#include <bits/stdc++.h>
using namespace std;

/*
        KMP
    1. 일반적으로 문자열 T에 패턴 P가 존재하는지 naive하게 찾는다면
       O(n * m), where n=length of T, m = length of P 걸린다.
    2. 이것을 획기적으로 줄이는 알고리즘 KMP 는 O(N+M)만에 가능하다.
    3. O(M)은 전처리 LPS(Longest Prefix Suffix)
    4. O(N)은 T의 길이만큼은 비교검사를 해야하므로.

        라빈카프(Rabin-Karp)
    1. 해싱을 이용해 똑같이 O(N)에 가깝게 "문자열 찾기"를 할 수 있다.
    2. 해싱값을 이용하는데, T[i]:T[i+M]의 해싱값과 P[0]:P[m]의 값을 비교해서 같으면 단순비교 시작, 다르면 그냥 pass
    3. 다른 문자열 A, B가 같은 해싱값을 가질 수는 있지만, 같은 문자열 A, B라면 "무조건" 같은 해싱값을 가질 수 밖에 없다.
    4. 따라서, 해싱값이 같으면 단순비교 시작, 다르면 pass하는데 해싱값 연산이 "연산작용의 절반"을 차지하므로
       해싱함수(H(x))를 잘 만들어야 그 만큼 해싱값을 빨리 구하고 연산 효율을 높힐 수 있다.
    5. H[i] = (S[i] * 2^M-1) + (S[i+1] * 2^M-2) + (...) + (S[i+M-1] * 2^0) 로 보통 쓴다.
    6. 왜 이 함수를 쓰냐면 H[i]를 구하면 H[i+1]의 값을 O(1) 에 구할 수 있기 때문!
        H[i+1] = (H[i] - S[i]*2^M-1) + S[i+M]*2^0

*/

string T, P;
int N, M;
int LPS[1000001];

void getInput() {
    getline(cin, T);
    getline(cin, P);
    N = T.length();
    M = P.length();
}
void getLPS() {
    int len = 0, idx = 1;
    LPS[0] = 0;
    while (idx < M) {
        if (P[len] == P[idx]) {
            LPS[idx] = len + 1;
            len++, idx++;
        }
        else {
            if (len == 0) {
                LPS[idx] = 0;
                idx++;
            }
            else {
                // a a b a a a c
                // 0 1 0 1 2 2 0  생각해보면 len=LPS[len-1] 로 직결됨. len을 바꾸고 다시 P[len], P[idx] 비교해야함.
                len = LPS[len-1];
            }
        }
    }
}
void KMP() {
    // i= T의 index
    // j= P의 index
    int i = 0, j = 0;
    getLPS();
    // 발견한 위치를 저장할 vector
    vector<int> loc;

    while (i < N) {
        // 문자가 같다면
        if (T[i] == P[j]) {
            i++, j++;
        }
        // 문자가 다르면
        else {
            if (j == 0) i++;
            else j = LPS[j - 1];
        }
        // Pattern 찾으면
        if (j == M) {
            loc.push_back(i - j + 1);
            // 또 pattern이 존재할 수 있으므로 j를 0으로 돌리지 말고 LPS[j-1]로 돌린다.
            j = LPS[j - 1];
        }
    }
    cout << loc.size() << "\n";
    for (i = 0; i < loc.size(); i++) {
        cout << loc[i] << " ";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    getInput();
    KMP();
    return 0;
}