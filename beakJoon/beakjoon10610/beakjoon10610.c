#include<stdio.h>
#include<stdlib.h>

int compareLess(const void *a, const void *b){
	char *pa = (char*)a;
	char *pb = (char*)b;
	
	if(*pa < *pb){
		return 1;
	}
	else if(*pa > *pb){
		return -1;
	}
	else{
		return 0;
	}
}

int main(){
	char n[10001];

	gets(n);


	int sum = 0;
	int i;
	for(i = 0; n[i] != '\0'; i++){
		sum += n[i] - '0';
	}

	qsort(n, i, sizeof(char), compareLess); //tip : second parameter of qsort is not maxIndex but sizeOfArray

	if(sum % 3 != 0 || n[i - 1] != '0'){
		printf("-1");
	}
	else{
		for(i = 0; n[i] != '\0'; i++){
			printf("%c", n[i]);
		}
	}

	return 0;
}
