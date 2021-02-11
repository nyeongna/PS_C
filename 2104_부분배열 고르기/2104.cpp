#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int a[100010];
long long result = 0;

long long Divide(int Start, int End) {


    //기저 사례
    // a 배열은 int 이므로 a[Start]=1000,000 이면 a[Start] * a[Start] 가 터질 수 있다.
    // 따라서 1LL을 곱해준다. 
    if (Start == End) return 1LL * a[Start] * a[Start];

    int mid = (Start + End) / 2;

    // 왼쪽 절반 중 최대 뽑아아고, 오른쪽 절반 중 최대 뽑아와서 비교.
    result = max(Divide(Start, mid), Divide(mid + 1, End));

    int l = mid, r = mid;
    int min_value = a[mid];
    long long total = a[mid];

    int p, q;

    while (r - l <= End - Start) {
        int p = (l > Start) ? a[l - 1] : -1;
        int q = (r < End) ? a[r + 1] : -1;

        //왼쪽으로 확장하는 것이 더 좋다면
        if (p >= q) {
            min_value = min(min_value, a[l - 1]);
            total = total + a[l - 1];
            l--;
        }
        //오른쪽으로 확장하는 것이 더 좋다면
        else {
            min_value = min(min_value, a[r + 1]);
            total = total + a[r + 1];
            r++;
        }

        result = max(result, min_value * total);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    // input값 받기
    int n, i;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // 분할 재귀 함수 Divide호출
    cout << Divide(1, n) << endl;

    return 0;
}