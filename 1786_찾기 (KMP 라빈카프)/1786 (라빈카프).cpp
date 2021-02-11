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
const int MOD_INT = 1000000000;

string T, P;
int N, M;

void getInput() {
    getline(cin, T);
    getline(cin, P);
    N = T.length();
    M = P.length();
}

// ��ȣ ������� "���� n"�� �־����� MOD_INT ���� ���� ����
int MOD(long long int n) {
    if (n >= 0) return n % MOD_INT;
    return ((-n / MOD_INT + 1) * MOD_INT + n) % MOD_INT;
}

void RK() {
    int G = 0, H = 0, power = 1;
    int i, j;
    vector<int> ans;

    // N - M ��ŭ �˻��Ѵ�.
    for (i = 0; i <= N - M; i++) {
        // Pattern ��          �ؽð� G ���ϱ�
        // Text    �� ù ��ġ�� �ؽð� H ���ϱ�
        if (i == 0) {
            for (j = 0; j < M; j++) {
                G = MOD(G + 1LL * P[M - 1 - j] * power);
                H = MOD(H + 1LL * T[M - 1 - j] * power);
                if (j < M - 1) power = MOD(power * 2);
            }
        }
        // i != 0�̸� H[i+1]�� ���� H[i]�� �̿��Ͽ� O(1)�� �ð����� ���Ѵ�.
        else {
            H = MOD(2 * (H - 1LL * T[i - 1] * power) + T[i + M - 1] * 1LL);
        }

        // P�� �ؽð� G�� ���α��� H[i+1] = H�� ���� ���ٸ� �ܼ��񱳸� ���� ���� �Ȱ����� �˻��Ѵ�.
        // �ؽð��� �� ��������� �浹�� �����Ƿ� (G==H) �� ��Ȳ�� �� �ȸ�������Ƿ� ���� �ӵ��� ������.
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