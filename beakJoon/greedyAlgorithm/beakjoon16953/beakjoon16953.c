#include<stdio.h>

int main(){
	unsigned int A, B;
	int count = 0;

	scanf("%d%d", &A, &B);

	while(A != B){
		if(B % 10 == 1){
			B /= 10;
			count++;
			continue;
		}
		else if((A > B) || (B % 10) % 2 != 0){
			printf("-1");
			return 0;
		}
		else{
			count++;
			B /= 2;
		}
	}

	printf("%d", ++count);
	return 0;
}
