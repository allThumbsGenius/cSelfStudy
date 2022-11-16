#include<stdio.h>
#include<stdlib.h>

typedef struct _JewelInfo{
	int weight;
	int price;
}JewelInfo;

int compareJewelWeight(const void *a, const void *b){
	int pa = ((JewelInfo*)a)->price;
	int pb = ((JewelInfo*)b)->price;

	if(pa < pb){
		return 1;
	}
	else if(pa > pb){
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

int main(){
	int jewelCount, bagCount;
	JewelInfo *jewelInfoArray;
	int *bagWeightArray;
	int *bagIsFull;
	int answer = 0;

	scanf("%d%d", &jewelCount, &bagCount);
	jewelInfoArray = (JewelInfo*)malloc(jewelCount * sizeof(JewelInfo));
	bagWeightArray = (int*)malloc(bagCount * sizeof(int));
	bagIsFull = (int*)malloc(bagCount * sizeof(int));

	for(int i = 0; i < jewelCount; i++){
		scanf("%d%d", &jewelInfoArray[i].weight, &jewelInfoArray[i].price);
	}
	for(int i = 0; i < bagCount; i++){
		scanf("%d", &bagWeightArray[i]);
		const int BAG_IS_EMPTY = 0;
		bagIsFull[i] = BAG_IS_EMPTY;
	}

	qsort(jewelInfoArray, jewelCount, sizeof(JewelInfo), compareJewelWeight);
	qsort(bagWeightArray, bagCount, sizeof(int), compareBagWeight);

	for(int i = 0; i < jewelCount; i++){
		for(int j = 0; j < bagCount; j++){
			if((jewelInfoArray[i].weight <= bagWeightArray[j]) && !bagIsFull[j]){
				answer += jewelInfoArray[i].price;
				const int BAG_IS_FULL = 1;
				bagIsFull[i] = BAG_IS_FULL;
				break;
			}
		}
	}

	printf("%d", answer);

	free(bagWeightArray);
	free(bagIsFull);
	free(jewelInfoArray);

	return 0;
}
