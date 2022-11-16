#include<stdio.h>
#include<stdlib.h>

typedef struct _JewelInfo{
	int weight;
	int price;
}JewelInfo;

int compareJewelWeight(const void *a, const void *b){
	int pa = ((JewelInfo*)a)->weight;
	int pb = ((JewelInfo*)b)->weight;

	if(pa > pb){
		return 1;
	}
	else if(pa < pb){
		return -1;
	}
	else{
		return 0;
	}
}

int compareBagWeight(const void *a, const void *b){
	int wa = *((int*)a);
	int wb = *((int*)b);

	if(wa > wb){
		return 1;
	}
	else if(wa < wb){
		return -1;
	}
	else{
		return 0;
	}
}

int HEAP[300001];
int heapSize = 0;

void heapInsert(int element){
	int tempIndex = ++heapSize;

	while(tempIndex/2 != 0 && (element > HEAP[tempIndex/2])){
		HEAP[tempIndex] = HEAP[tempIndex/2];
		tempIndex /= 2;
	}

	HEAP[tempIndex] = element;
}

int getMaxFromHeap(){
	int returnValue = HEAP[1];
	HEAP[1] = HEAP[heapSize--];

	int element = HEAP[1];
	int index = 1;
	while(index <= heapSize){
		int biggest = index;
		if((index * 2 <= heapSize) && (HEAP[biggest] <= HEAP[index * 2])){
			biggest = index * 2;
		}
		else if((index * 2 + 1 <= heapSize) && (HEAP[biggest] < HEAP[index * 2 + 1])){
			biggest = index * 2 + 1;
		}

		if(biggest != index){
			HEAP[index] = HEAP[biggest];
			index = biggest;
		}
		if(biggest == index){
			break;
		}
	}
	HEAP[index] = element;

	return returnValue;
}



int main(){
	int jewelCount, bagCount;
	JewelInfo *jewelInfoArray;
	int *bagWeightArray;
	long long int answer = 0;

	scanf("%d%d", &jewelCount, &bagCount);
	jewelInfoArray = (JewelInfo*)malloc(jewelCount * sizeof(JewelInfo));
	bagWeightArray = (int*)malloc(bagCount * sizeof(int));

	for(int i = 0; i < jewelCount; i++){
		scanf("%d%d", &jewelInfoArray[i].weight, &jewelInfoArray[i].price);
	}
	for(int i = 0; i < bagCount; i++){
		scanf("%d", &bagWeightArray[i]);
	}

	qsort(jewelInfoArray, jewelCount, sizeof(JewelInfo), compareJewelWeight);
	qsort(bagWeightArray, bagCount, sizeof(int), compareBagWeight);

	int j = 0;
	for(int i = 0; i < bagCount; i++){
		while(jewelInfoArray[j].weight <= bagWeightArray[i]){
			heapInsert(jewelInfoArray[j].price);
			j++;
		}
		if(heapSize != 0){
			answer += getMaxFromHeap();
		}
	}


	printf("%lld", answer);

	free(bagWeightArray);
	free(jewelInfoArray);

	return 0;
}
