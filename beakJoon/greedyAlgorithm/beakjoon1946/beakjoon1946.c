#include<stdio.h>
#include<stdlib.h>

typedef struct _grades{
	int paper;
	int interview;
}grades;

int compare(const void *a, const void *b){
	grades *pa = (grades*)a;
	grades *pb = (grades*)b;

	if(pa->paper > pb->paper){
		return 1;
	}
	else if(pa->paper < pb->paper){
		return -1;
	}
	else{
		return 0;
	}
}

int main(){
	int testcaseCount;
	int candidateCount;

	int countPerTest[10000];
	grades grade[10000];
	
	scanf("%d", &testcaseCount);

	for(int i = 0; i < testcaseCount; i++){
		scanf("%d", &candidateCount);
		
		for(int j = 0; j < candidateCount; j++){
			scanf("%d%d", &grade[j].paper, &grade[j].interview);
		}
		
		qsort(grade, candidateCount, sizeof(grades), compare);
		
		int count = 0;
		for(int j = 1; j < candidateCount; j++){
			for(int k = j - 1; k >= 0; k--){
				if(grade[j].interview > grade[k].interview){
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
