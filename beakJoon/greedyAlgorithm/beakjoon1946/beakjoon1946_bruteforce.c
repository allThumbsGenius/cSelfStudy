#include<stdio.h>
#include<stdlib.h>

typedef struct _grades{
	int paper;
	int interview;
}grades;

int main(){
	int testcaseCount;
	int candidateCount;

	int countPerTest[20];
	grades grade[100000];
	
	scanf("%d", &testcaseCount);

	for(int i = 0; i < testcaseCount; i++){

		scanf("%d", &candidateCount);
		
		for(int j = 0; j < candidateCount; j++){
			scanf("%d%d", &grade[j].paper, &grade[j].interview);
		}

		int count = 0;

		for(int j = 0; j < candidateCount; j++){
			for(int k = 0; k < candidateCount; k++){
				if(grade[j].paper > grade[k].paper && grade[j].interview > grade[k].interview){
					count++;
					break;
				}
			}
		}
		
		countPerTest[i] = candidateCount - count;
	}

	for(int i = 0; i < testcaseCount; i++){
		printf("%d\n", countPerTest[i]);
	}

	return 0;
}
