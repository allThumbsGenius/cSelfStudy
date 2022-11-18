#include<stdio.h>
#include<stdlib.h>

typedef struct _JewelInfo{
	long long int weight;
	long long int price;
}JewelInfo;

int compareJewelWeight(const void *a, const void *b){
	long long int pa = ((JewelInfo*)a)->weight;
	long long int pb = ((JewelInfo*)b)->weight;

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
	long long int wa = *((long long int*)a);
	long long int wb = *((long long int*)b);

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

long long int HEAP[300001];
int heapSize = 0;

void heapInsert(long long int element){
	int tempIndex = ++heapSize;

	while(tempIndex != 1 && (element > HEAP[tempIndex/2])){
		HEAP[tempIndex] = HEAP[tempIndex/2];
		tempIndex /= 2;
	}

	HEAP[tempIndex] = element;
}

long long int getMaxFromHeap(){
	long long int returnValue = HEAP[1];
	HEAP[1] = HEAP[heapSize--];

	int index = 1;
	while(index <= heapSize){
		int biggest = index;
		if((index * 2 <= heapSize) && (HEAP[biggest] <= HEAP[index * 2])){
			biggest = index * 2;
		}
		if((index * 2 + 1 <= heapSize) && (HEAP[biggest] < HEAP[index * 2 + 1])){
			biggest = index * 2 + 1;
		}

		if(biggest != index){
			long long int temp = HEAP[index];
			HEAP[index] = HEAP[biggest];
			HEAP[biggest] = temp;
			index = biggest;
		}
		if(biggest == index){
			break;
		}
	}

	return returnValue;
}



int main(){
	long long int jewelCount, bagCount;
	JewelInfo *jewelInfoArray;
	long long int *bagWeightArray;
	long long int answer = 0;

	scanf("%lld%lld", &jewelCount, &bagCount);
	jewelInfoArray = (JewelInfo*)malloc(jewelCount * sizeof(JewelInfo));
	bagWeightArray = (long long int*)malloc(bagCount * sizeof(long long int));

	for(int i = 0; i < jewelCount; i++){
		scanf("%lld%lld", &jewelInfoArray[i].weight, &jewelInfoArray[i].price);
	}
	for(int i = 0; i < bagCount; i++){
		scanf("%lld", &bagWeightArray[i]);
	}

	qsort(jewelInfoArray, jewelCount, sizeof(JewelInfo), compareJewelWeight);
	qsort(bagWeightArray, bagCount, sizeof(long long int), compareBagWeight);

	int j = 0;
	for(int i = 0; i < bagCount; i++){
		while((j < jewelCount) && (jewelInfoArray[j].weight <= bagWeightArray[i])){
			heapInsert(jewelInfoArray[j].price);
			j++;
		}
		if(heapSize != 0){
			answer += (long long int)getMaxFromHeap();
		}
	}


	printf("%lld", answer);

	free(bagWeightArray);
	free(jewelInfoArray);

	return 0;
}
