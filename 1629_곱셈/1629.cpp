#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    ���� ����
    c�� ���� �������� ���� �� ���ϱ⳪ ���ϱ� �������� �� ���̰� � ���� c�� ���� �������� ���ص� ��� �����ϴ�
*/
int Modulo_2(int a, int b, int c) {
    // a = 7, b = 256, c = 13
    if (b==1) {
        return a % c;
    }
    return ( Modulo_2(a, b/2, c) * Modulo_2(a,b/2, c) ) % c;
    
}
//c�� ���� �������� ���� �� ���ϱ⳪ ���ϱ� �������� �� ���̰� � ���� c�� ���� �������� ���ص� ��� �����ϴ�
        // ���� (tmp * tmp * (a%c) ) % c����
        // ==>    (tmp * tmp % c * (a%c)) % c �ص� ����� ����.
        // ==>    ������ �̷��� "% c"�� �߰������μ� lld�� �ʰ�ȭ�� �����÷ο츦 ���� �� �ִ�.

long long int Modulo_1(long long int a, long long int b, long long int c) {
    // a = 7, b = 100, c = 13 ==> �� 9
    if (b==1) return a % c;
    if (b==0) return 1;
    long long tmp = Modulo_1(a,b/2,c);
    if ( b % 2 == 0) {
        return ( tmp %c* tmp%c ) % c;
    }
    else {
        
        return ( tmp%c * tmp%c * (a%c) ) % c;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    long long int a, b, c;
    cin >> a >> b >> c;

    //cout << Modulo_2(a,b,c);
    cout << Modulo_1(a,b,c);

    return 0;
}