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
const int MOD_INT = 1000000000;

string T, P;
int N, M;

void getInput() {
    getline(cin, T);
    getline(cin, P);
    N = T.length();
    M = P.length();
}

// 부호 상관없이 "정수 n"이 주어지면 MOD_INT 속의 값을 리턴
int MOD(long long int n) {
    if (n >= 0) return n % MOD_INT;
    return ((-n / MOD_INT + 1) * MOD_INT + n) % MOD_INT;
}

void RK() {
    int G = 0, H = 0, power = 1;
    int i, j;
    vector<int> ans;

    // N - M 만큼 검사한다.
    for (i = 0; i <= N - M; i++) {
        // Pattern 의          해시값 G 구하기
        // Text    의 첫 위치의 해시값 H 구하기
        if (i == 0) {
            for (j = 0; j < M; j++) {
                G = MOD(G + 1LL * P[M - 1 - j] * power);
                H = MOD(H + 1LL * T[M - 1 - j] * power);
                if (j < M - 1) power = MOD(power * 2);
            }
        }
        // i != 0이면 H[i+1]의 값을 H[i]을 이용하여 O(1)의 시간으로 구한다.
        else {
            H = MOD(2 * (H - 1LL * T[i - 1] * power) + T[i + M - 1] * 1LL);
        }

        // P의 해시값 G와 새로구한 H[i+1] = H의 값과 같다면 단순비교를 통해 정말 똑같은지 검사한다.
        // 해시값을 잘 만들었으면 충돌이 적으므로 (G==H) 인 상황이 잘 안만들어지므로 연산 속도가 빠르다.
        if (G == H) {
            bool same = true;
            for (int k = 0; k < M; k++) {
                if (T[i + k] != P[k]) {
                    same = false;
                    break;
                }
            }
            if (same == true) {
                ans.push_back(i + 1);
            }
        }
    }
    cout << ans.size() << endl;
    for (i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    getInput();
    RK();
    return 0;
}