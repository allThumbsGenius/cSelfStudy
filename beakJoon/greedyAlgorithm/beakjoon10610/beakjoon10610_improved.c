#include<stdio.h>

int main(){
	int digitNumberCount[10] = {0};
	char ch;

	while((ch = getchar()) != '\n'){
		digitNumberCount[ch - '0']++;
	}

	if(digitNumberCount[0] == 0 || (((digitNumberCount[2] + digitNumberCount[5] + digitNumberCount[8]) * 2) + digitNumberCount[1] + digitNumberCount[4] + digitNumberCount[7]) % 3 != 0){
		printf("-1");
		return 0;
	}
	
	for(int i = 9; i >= 0; --i){
		for(int j = digitNumberCount[i]; j > 0; --j){
			ch = i + '0';
			putchar(ch);
		}
	}

	return 0;
}
