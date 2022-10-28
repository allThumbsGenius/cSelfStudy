#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b){
	int *pa = (int*)a;
	int *pb = (int*)b;

	if(*pa > *pb){
		return 1;
	}
	else if(*pa < *pb){
		return -1;
	}
	else{
		return 0;
	}
}

int main(){
	int cardCount[100000];
	int N;

	scanf("%d", &N);
	
	for(int i = 0; i < N; i++){
		scanf("%d", &cardCount[i]);
	}

	qsort(cardCount, N, sizeof(int), compare);

	if(N == 1){
		printf("%d", cardCount[0]);
		return 0;
	}

	if(N == 2){
		printf("%d", cardCount[0] + cardCount[1]);
		return 0;
	}
	
	int sum = 0;
	sum += (N - 1) * (cardCount[0] + cardCount[1]);
	for(int i = 2; i < N; i++){
		sum += (N - i) * cardCount[i];
	}

	printf("%d", sum);
	
	return 0;
}
