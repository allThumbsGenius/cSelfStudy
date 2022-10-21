#include<stdio.h>
#include<stdlib.h>

int compareGreater(const void *a, const void *b){
	int *pa = (int*)a;
	int *pb = (int*)b;

	if(*pa < *pb){
		return 1;
	}
	else if(*pa > *pb){
		return -1;
	}
	else{
		return 0;
	}
}

int main(){
	int N;
	int *maxWeightPerRope;

	scanf("%d", &N);

	maxWeightPerRope = (int*)malloc(N * sizeof(int));

	for(int i = 0; i < N; ++i){
		int weight;
		scanf("%d", &weight);
		maxWeightPerRope[i] = weight;
	}

	qsort(maxWeightPerRope, N, sizeof(int), compareGreater);

	int max = maxWeightPerRope[0];
	for(int i = 1; i < N; ++i){
		int maxWeightSum = maxWeightPerRope[i] * (i+1);
		if(maxWeightSum > max){
			max = maxWeightSum;
		}
	}

	printf("%d", max);

	free(maxWeightPerRope);
	return 0;
}
