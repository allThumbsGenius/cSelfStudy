#include<stdio.h>
#include<stdlib.h>

typedef struct _HEAP{
	int array[51];
	int heapSize;
}HEAP;

void heapInit(HEAP *h){
	h->heapSize = 0;
}

void minHeapInsert(HEAP *h, int key){
	int index = ++(h->heapSize);
	while(index != 1 && key < h->array[index/2]){
		h->array[index] = h->array[index/2];
		index /= 2;
	}
	h->array[index] = key;
}

int main(){
	HEAP *packagePriceHeap;
	HEAP *eachPriceHeap;
	packagePriceHeap = (HEAP*)malloc(1 * sizeof(HEAP));
	eachPriceHeap = (HEAP*)malloc(1 * sizeof(HEAP));

	int answer = 0;

	int N, M;
	scanf("%d%d", &N, &M);
	
	heapInit(packagePriceHeap);
	heapInit(eachPriceHeap);

	for(int i = 0; i < M; i++){
		int packagePrice;
		int eachPrice;
		scanf("%d%d", &packagePrice, &eachPrice);

		minHeapInsert(packagePriceHeap, packagePrice);
		minHeapInsert(eachPriceHeap, eachPrice);
	}
	int minPackagePrice = packagePriceHeap->array[1];
	int minEachPrice = eachPriceHeap->array[1];

	if(minPackagePrice < (minEachPrice * 6)){
		answer += (minPackagePrice * (N / 6));
	}
	else{
		answer += ((minEachPrice * 6) * (N / 6));
	}

	if(minPackagePrice < (minEachPrice * (N % 6))){
		answer += minPackagePrice;
	}
	else{
		answer += (minEachPrice * (N % 6));
	}

	printf("%d", answer);

	free(packagePriceHeap);
	free(eachPriceHeap);

	return 0;
}
