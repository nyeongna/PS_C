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
			if (arr[i][2] % atk == 0){		//���ݷ��� ü�¿� ������������
				sv -= arr[i][1] * ((arr[i][2] / atk) - 1);
			}
			else{    //������ �������� ������
				sv -= arr[i][1] * (arr[i][2] / atk);
			}
		}
		else{		//�����̸�
			if (i != N){    //�� ���� �ݷ� ������ ���� ����(N��° �濡 ���� �ִٰ� ���Ҵµ� �ʿ�����?!)
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