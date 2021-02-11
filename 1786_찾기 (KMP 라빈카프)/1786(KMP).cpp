#include <bits/stdc++.h>
using namespace std;

/*
        KMP
    1. �Ϲ������� ���ڿ� T�� ���� P�� �����ϴ��� naive�ϰ� ã�´ٸ�
       O(n * m), where n=length of T, m = length of P �ɸ���.
    2. �̰��� ȹ�������� ���̴� �˰��� KMP �� O(N+M)���� �����ϴ�.
    3. O(M)�� ��ó�� LPS(Longest Prefix Suffix)
    4. O(N)�� T�� ���̸�ŭ�� �񱳰˻縦 �ؾ��ϹǷ�.

        ���ī��(Rabin-Karp)
    1. �ؽ��� �̿��� �Ȱ��� O(N)�� ������ "���ڿ� ã��"�� �� �� �ִ�.
    2. �ؽ̰��� �̿��ϴµ�, T[i]:T[i+M]�� �ؽ̰��� P[0]:P[m]�� ���� ���ؼ� ������ �ܼ��� ����, �ٸ��� �׳� pass
    3. �ٸ� ���ڿ� A, B�� ���� �ؽ̰��� ���� ���� ������, ���� ���ڿ� A, B��� "������" ���� �ؽ̰��� ���� �� �ۿ� ����.
    4. ����, �ؽ̰��� ������ �ܼ��� ����, �ٸ��� pass�ϴµ� �ؽ̰� ������ "�����ۿ��� ����"�� �����ϹǷ�
       �ؽ��Լ�(H(x))�� �� ������ �� ��ŭ �ؽ̰��� ���� ���ϰ� ���� ȿ���� ���� �� �ִ�.
    5. H[i] = (S[i] * 2^M-1) + (S[i+1] * 2^M-2) + (...) + (S[i+M-1] * 2^0) �� ���� ����.
    6. �� �� �Լ��� ���ĸ� H[i]�� ���ϸ� H[i+1]�� ���� O(1) �� ���� �� �ֱ� ����!
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
                // 0 1 0 1 2 2 0  �����غ��� len=LPS[len-1] �� �����. len�� �ٲٰ� �ٽ� P[len], P[idx] ���ؾ���.
                len = LPS[len-1];
            }
        }
    }
}
void KMP() {
    // i= T�� index
    // j= P�� index
    int i = 0, j = 0;
    getLPS();
    // �߰��� ��ġ�� ������ vector
    vector<int> loc;

    while (i < N) {
        // ���ڰ� ���ٸ�
        if (T[i] == P[j]) {
            i++, j++;
        }
        // ���ڰ� �ٸ���
        else {
            if (j == 0) i++;
            else j = LPS[j - 1];
        }
        // Pattern ã����
        if (j == M) {
            loc.push_back(i - j + 1);
            // �� pattern�� ������ �� �����Ƿ� j�� 0���� ������ ���� LPS[j-1]�� ������.
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