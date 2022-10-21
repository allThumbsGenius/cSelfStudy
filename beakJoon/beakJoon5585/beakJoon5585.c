#include<stdio.h>

int min2(int a, int b){
	if(a > -1 && b > -1){
		return a>b ? b : a;
	}
	else if(a <= -1){
		return b;
	}
	else{
		return a;
	}
}

int min3(int a, int b, int c){
	return min2(min2(a, b), c);
}

int min4(int a, int b, int c, int d){
	return min2(min3(a, b, c), d);
}

int min5(int a, int b, int c, int d, int e){
	return min2(min4(a, b, c, d), e);
}

int min6(int a, int b, int c, int d, int e, int f){
	return min2(min5(a, b, c, d, e), f);
}

int min7(int a, int b, int c, int d, int e, int f, int g){
	return min2(min6(a, b, c, d, e, f), g);
}


int minusToZero(int n){
	return n < 0 ? 0 : n;
}

int main(){
	int price;
	int changeMoney;

	int BillCount[1001]; 

	scanf("%d", &price);

	const int PAYBILL = 1000;
	changeMoney = PAYBILL - price;

	const int NO_WAY_TO_CHANGE = -1;
	for(int i = 0; i <= 1000; ++i){
		BillCount[i] = NO_WAY_TO_CHANGE;
	}

	const int NEED_JUST_ONE_BILL = 0;
	BillCount[1] = NEED_JUST_ONE_BILL;
	BillCount[5] = NEED_JUST_ONE_BILL;
	BillCount[10] = NEED_JUST_ONE_BILL;
	BillCount[50] = NEED_JUST_ONE_BILL;
	BillCount[100] = NEED_JUST_ONE_BILL;
	BillCount[500] = NEED_JUST_ONE_BILL;

	for(int i = 1; i <= changeMoney; ++i){
		BillCount[i] = min7(BillCount[i], BillCount[minusToZero(i - 500)], BillCount[minusToZero(i - 100)], BillCount[minusToZero(i - 50)], BillCount[minusToZero(i - 10)], BillCount[minusToZero(i - 5)], BillCount[minusToZero(i - 1)]) + 1;
	}

	printf("%d", BillCount[changeMoney]);

	return 0;
}
