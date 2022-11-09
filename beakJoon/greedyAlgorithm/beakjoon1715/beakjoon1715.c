#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int array[100001];
	int size;
}Heap;

void initHeap(Heap* heap, int size){
	heap->size = size;
}

void minHeapify(Heap *heap, int index){
	int smallest = index;
	int leftChild = index * 2;
	int rightChild = index * 2 + 1;

	if(leftChild <= heap->size && heap->array[smallest] > heap->array[leftChild]){
		smallest = leftChild;
	}
	if(rightChild <= heap->size && heap->array[smallest] > heap->array[rightChild]){
		smallest = rightChild;
	}
	if(smallest != index){
		int temp = heap->array[index];
		heap->array[index] = heap->array[smallest];
		heap->array[smallest] = temp;
		minHeapify(heap, smallest);
	}
}

int minExtract(Heap *heap){
	int ret = heap->array[1];
	heap->array[1] = heap->array[(heap->size)--];
	minHeapify(heap, 1);

	return ret;
}

void heapInsert(Heap *heap, int value){
	int index = ++(heap->size);
	int parent = index / 2;

	while((index != 1) && (value < heap->array[parent])){
		heap->array[index] = heap->array[parent];
		index = parent;
		parent /= 2;
	}
	heap->array[index] = value;
}

int main(){
	int N;
	long long int sum = 0;
	Heap *heap;
	
	heap = (Heap *)malloc(sizeof(Heap) * 1);

	scanf("%d", &N);

	initHeap(heap, N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &heap->array[i]);
	}
	
	if(N == 1){
		printf("0");
		return 0;
	}

	//build heap
	for(int i = N / 2; i >= 1; i--){
		minHeapify(heap, i);
	}


	for(int i = 0; i < N - 1; i++){
		int min[2];
		
		min[0] = minExtract(heap);
		min[1] = minExtract(heap);
		heapInsert(heap, min[0] + min[1]);
		sum += (min[0] + min[1]);
	}
	printf("%lld", sum);

	free(heap);

	return 0;
}

