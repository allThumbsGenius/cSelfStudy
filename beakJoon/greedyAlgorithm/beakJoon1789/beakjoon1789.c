#include<stdio.h>

int main(){
	int sum = 0;
	unsigned int S;

	scanf("%d", &S);

	int n = 1;
	for(;;++n){
		sum += n;
   		if(S - sum <= n){
			break;
		}
	}

	printf("%d", n);

	return 0;
}
