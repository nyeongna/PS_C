#include <stdio.h>					

long long int N, atk;
long long int arr[150000][3];

int main(void)

{
	int i, j, k;
	long long int sv = 0;

	scanf("%lld %lld", &N, &atk);

	for (i = 1; i <= N; ++i){
		scanf("%lld %lld %lld", &arr[i][0], &arr[i][1], &arr[i][2]);
	}

	for (i = 1; i <= N; ++i){
		if (arr[i][0] == 1){
			if (arr[i][2] % atk == 0){		//공격력이 체력에 나눠떨어지면
				sv -= arr[i][1] * ((arr[i][2] / atk) - 1);
			}
			else{    //나누어 떨어지지 않으면
				sv -= arr[i][1] * (arr[i][2] / atk);
			}
		}
		else{		//포션이면
			if (i != N){    //밑 질문 반례 때문에 넣은 조건(N번째 방에 용이 있다고 보았는데 필요한지?!)
				atk += arr[i][1];
				sv += arr[i][2];
				if (sv > 0){
					sv = 0;
				}
			}
		}
	}

	printf("%lld", (sv * -1) + 1);
	return 0;
}