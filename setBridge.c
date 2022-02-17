#include<stdio.h>
#include<stdlib.h>

int calculateCaseOfNumber(int, int);
int conbination(int, int);

typedef struct _TWOINT{
	int	leftSide; 
	int rightSide;
}twoInt;

int combination(int n, int r){
	int middle = n/2;
	int result; 
	int **combinationMemo; 

	r = (r > middle)?(n-r):r;

	combinationMemo = (int **)calloc(n + 1, sizeof(int*));//row is n col is r, nCr -> combinationMemo[n][r], combinationMemo[0][0] is trash node
	for(int i = 0; i <= n; i++){
		combinationMemo[i] = (int *)calloc(i + 1, sizeof(int));// n is always bigger than r
		combinationMemo[i][0] = 1;
		combinationMemo[i][i] = 1;
	}


	for(int i = 2; i <= n; i++){
		for(int j = 1; j < i; j++){
			combinationMemo[i][j] = combinationMemo[i-1][j-1] + combinationMemo[i-1][j];
		}
	}

	result = combinationMemo[n][r];

	for(int i = 0; i < n; i++){
		free(combinationMemo[i]);
	}
	free(combinationMemo);

	return result;
}

int calculateCaseOfNumber(int leftSide, int rightSide){
	return combination(leftSide, rightSide);
}

int main(){
	twoInt *cases;
	int howManyCases;

	scanf("%d", &howManyCases);
	cases = (twoInt*)malloc(sizeof(twoInt) * howManyCases);

	for(int i = 0; i < howManyCases; i++){
		scanf("%d", &(cases[i].leftSide));
		scanf("%d", &(cases[i].rightSide));
	}

	for(int i = 0; i < howManyCases; i++){
		printf("%d\n", calculateCaseOfNumber(cases[i].rightSide, cases[i].leftSide));
	}
	
	free(cases);
	return 0;
}
