#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    모듈로 성질
    c로 나눈 나머지를 구할 때 곱하기나 더하기 과정에서 몇 번이고 어떤 수든 c로 나눈 나머지를 취해도 상관 없습니다
*/
int Modulo_2(int a, int b, int c) {
    // a = 7, b = 256, c = 13
    if (b==1) {
        return a % c;
    }
    return ( Modulo_2(a, b/2, c) * Modulo_2(a,b/2, c) ) % c;
    
}
//c로 나눈 나머지를 구할 때 곱하기나 더하기 과정에서 몇 번이고 어떤 수든 c로 나눈 나머지를 취해도 상관 없습니다
        // 따라서 (tmp * tmp * (a%c) ) % c에서
        // ==>    (tmp * tmp % c * (a%c)) % c 해도 결과는 같다.
        // ==>    오히려 이렇게 "% c"를 추가함으로서 lld를 초고화는 오버플로우를 막을 수 있다.

long long int Modulo_1(long long int a, long long int b, long long int c) {
    // a = 7, b = 100, c = 13 ==> 답 9
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