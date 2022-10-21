#include<stdio.h>

int main(){
	int t;
	int countA = 0, countB = 0, countC = 0;


	scanf("%d", &t);

	if(t % 10 != 0){
		printf("-1");
	}
	else{
		countA += t/300;
		t %= 300;

		countB += t/60;
		t %= 60;

		countC += t/10;
		t %= 10;
	
		printf("%d %d %d", countA, countB, countC);
	}

	return 0;
}


