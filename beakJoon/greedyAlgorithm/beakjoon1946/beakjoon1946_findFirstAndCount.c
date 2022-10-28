#include<stdio.h>
#include<stdlib.h>

typedef struct _grades{
	int paper;
	int interview;
}grades;

int main(){
	int testcaseCount;
	int candidateCount;

	int countPerTest[100000];
	grades grade[100000];
	
	scanf("%d", &testcaseCount);

	for(int i = 0; i < testcaseCount; i++){

		int whoIsOut[100000] = {0};

		scanf("%d", &candidateCount);
		
		for(int j = 0; j < candidateCount; j++){
			scanf("%d%d", &grade[j].paper, &grade[j].interview);
		}

		grades paperFirst;
		grades interviewFirst;
		int count = 0;

		for(int j = 0; j < candidateCount; j++){
			if(grade[j].paper == 1){
				paperFirst = grade[j];
				break;
			}
		}

		for(int j = 0; j < candidateCount; j++){
			if(paperFirst.interview < grade[j].interview){
				whoIsOut[j] = 1;
			}
		}
		
		for(int j = 0; j < candidateCount; j++){
			if(grade[j].interview == 1){
				interviewFirst = grade[j];
				break;
			}
		}

		for(int j = 0; j < candidateCount; j++){
			if(interviewFirst.paper < grade[j].paper){
				whoIsOut[j] = 1;
			}
		}
		
		for(int j = 0; j < candidateCount; j++){
			if(whoIsOut[j]){
				count++;
			}
		}
		
		countPerTest[i] = candidateCount - count;
	}

	for(int i = 0; i < testcaseCount; i++){
		printf("%d\n", countPerTest[i]);
	}

	return 0;
}
