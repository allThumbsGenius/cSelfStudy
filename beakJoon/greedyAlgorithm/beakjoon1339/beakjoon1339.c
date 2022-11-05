#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(const void *a, const void *b){
	unsigned int *pa = (unsigned int *)a;
	unsigned int *pb = (unsigned int *)b;

	if(*pa > *pb){
		return -1;
	}
	else if(*pa < *pb){
		return 1;
	}
	else{
		return 0;
	}
}

unsigned int getPow(int p, int k){
	unsigned int temp = 1;
	for(int i = 0; i < k; i++){
		temp *= p;
	}
	return temp;
}

int main(){
	int n;
	unsigned int alphabet[26] = {0};
	char inputs[8];
	long long int answer = 0;

	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s", inputs);
		int len = strlen(inputs);
		for(int j = 0; j < len; j++){
			alphabet[inputs[j] - 'A'] += getPow(10, len - 1 - j);
		}
	}

	qsort(alphabet, 26, sizeof(unsigned int), compare);

	for(int i = 0; i < 26; i++){
		fprintf(stderr, "%d ", alphabet[i]);
	}
	fprintf(stderr, "\n");

	for(int i = 9, j = 0; i > 0 ; i--, j++){
		answer += (alphabet[j] * i);
	}

	printf("%lld", answer);

	return 0;
}
