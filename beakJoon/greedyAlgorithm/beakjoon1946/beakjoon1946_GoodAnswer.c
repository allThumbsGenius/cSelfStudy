#include<stdio.h>
#include<stdlib.h>

int main(){
	int testcaseCount;
	int candidateCount;

	int ranks[100001];
	
	scanf("%d", &testcaseCount);

	for(int i = 0; i < testcaseCount; i++){
		scanf("%d", &candidateCount);
		
		for(int j = 0; j < candidateCount; j++){
			int k;
			scanf("%d", &k);
			scanf("%d", &ranks[k]);
		}
		
		int count = 1;
		int min = ranks[1];
		for(int j = 2; j <= candidateCount; j++){
			if(min > ranks[j]){
				count++;
				min = ranks[j];
			}
		}

		printf("%d\n", count);
	}


	return 0;
}
