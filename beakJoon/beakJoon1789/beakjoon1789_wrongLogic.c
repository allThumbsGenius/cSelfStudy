#include<stdio.h>

int main(){
	int sum = 0;
	unsigned int S;

	scanf("%d", &S);

	int n = 1;
	for(;S - sum > n; ++n){
		sum += n;
		fprintf(stderr, "n = %d, S-sum = %d\n", n, S-sum);
	}

	printf("%d", n - 1);

	return 0;
}
