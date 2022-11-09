#include<stdio.h>

int main(){
	int answer;
	int l, p, v;
	int caseNum = 1;

	while(scanf("%d%d%d", &l, &p, &v) && l !=0 && p != 0 && v !=0){
		answer = 0;
		answer +=  (v / p * l);
		if( v % p <= l){
			answer += v % p;
		}
		else{
			answer += l;
		}

		printf("Case %d: %d\n", caseNum, answer);
	}

	return 0;
}
