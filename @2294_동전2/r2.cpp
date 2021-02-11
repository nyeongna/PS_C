#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 101;
const int MAX_K = 10001;
const int IMPOSSIBLE = 100000000;
    int N, K, cost[MAX_N], dp[MAX_N][MAX_K];
 
int main() {
    printf("asd");
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++)
        scanf("%d", cost+i);
    // dp 배열 초기화
    for(int i=0; i<=N; i++)
        for(int j=0; j<=K; j++)
            dp[i][j] = IMPOSSIBLE;
    // dp로 문제 품
    for(int i=0; i<N; i++){
        dp[i][0] = 0;
        for(int j=0; j<=K; j++){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            printf("dp[%d][%d]=%d\n", i+1, j, dp[i+1][j]);
            int jj = j + cost[i];
            if(jj <= K) {
                dp[i][jj] = min(dp[i][jj], dp[i][j] + 1);
                printf("dp[%d][%d]=%d\n", i, jj, dp[i][jj]);
            }
        }
    }
    // 정답 출력
    if(dp[N-1][K] == IMPOSSIBLE) puts("-1");
    else printf("%d\n", dp[N-1][K]);
}


