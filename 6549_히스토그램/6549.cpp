#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    히스토그램 문제.
    - 다양한 풀이법이 존재하지만 여기서는, 분할정복 (Divid and Conquer)로 한다.
*/

long long int a[100001];

// [S, E] 까지의 히스토그램에서 최대 직사각형 찾기 (S포함, E포함)
long long int Histogram(int S, int E) {

    // base case(기저사례)
    // 직사각형 1개일 때, 너비=1, 넓이=a[S]
    if (S == E) return a[S];
    // 직사각형 0개일 때, 너비=0, 넓이=0
    //if (S==E) return 0;

    long long int result = 0;
    int mid = (S + E) / 2;
    result = max(Histogram(S, mid), Histogram(mid + 1, E));

    // 정답이 왼쪽 영역, 오른쪽 영역 둘다 포함할 때
    long long int h = a[mid], l = mid, r = mid;
    while (r - l <= E - S) {
        // 왼쪽으로 확장했을 시
        int p = l > S ? min(h, a[l - 1]) : -1;
        // 오른쪽으로 확장했을 시
        int q = r < E ? min(h, a[r + 1]) : -1;
        //왼쪽으로 확장한 결과가 더 큰 경우
        if (p >= q) {
            l--;
            h = p;
        }
        //오른쪽으로 확장한 결과가 더 큰 경우
        else {
            r++;
            h = q;
        }
        result = max(result, h * (r - l + 1));
    }
    return result;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);


    int n, i, j;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << Histogram(1, n) << endl;

    return 0;
}