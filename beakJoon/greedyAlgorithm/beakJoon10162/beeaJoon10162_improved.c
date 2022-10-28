#include<stdio.h>

int main(){
	int t;

	scanf("%d", &t);

	printf(t % 10 ? "-1" : "%d %d %d", t/300, t/60%5, t/10%6);

	return 0;
}


