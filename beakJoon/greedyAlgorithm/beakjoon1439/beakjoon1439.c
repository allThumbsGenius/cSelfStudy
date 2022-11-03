#include<stdio.h>

int main(){
	char S[1000001];
	int oneOrZero;
	int countChange = 0;

	gets(S);

	int i = 1;
	while(S[i] != '\0'){
		if(S[i - 1] != S[i]){
			countChange++;
		}
		i++;
	}

	printf("%d", (countChange + 1)/2);
}

