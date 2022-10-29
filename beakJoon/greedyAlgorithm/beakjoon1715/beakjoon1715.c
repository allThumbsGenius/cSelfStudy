#include<stdio.h>

int main(){
	int card[100000];
	int N;
	int sum = 0;
	const int IS_USED = 1001;
	
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%d", &card[i]);
	}

	if(N == 1){
		printf("%d", card[0]);
		return 0;
	}

	for(int i = 0; i < N - 1; i++){
		int min[2];
		int tempIndex[2] = {-1, -1};

		
		int j = 0;
		min[0] = card[0];
		for(j = 1; j < N; j++){
			if(min[0] > card[j]){
				min[0] = card[j];
				tempIndex[0] = j;
			}
		}
		if(tempIndex[0] == -1){
			card[0] = IS_USED;
			tempIndex[0] = 0;
		}
		card[tempIndex[0]] = IS_USED;

		min[1] = card[0];
		for(j = 1; j < N; j++){
			if(min[1] > card[j]){
				min[1] = card[j];
				tempIndex[1] = j;
			}
		}
		if(tempIndex[1] == -1){
			card[0] = IS_USED;
			tempIndex[1] = 0;
		}
		card[tempIndex[1]] = IS_USED;

		sum += (min[0] + min[1]);

		if(tempIndex[0] > tempIndex[1]){
			card[tempIndex[1]] = min[0] + min[1];
		}
		else{
			card[tempIndex[0]] = min[0] + min[1];
		}

	}
	printf("%d", sum);

	return 0;
}

