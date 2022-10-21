#include<stdio.h>

int main(){
	int price;
	int changeMoney;

	int countChnageBill = 0;

	scanf("%d", &price);
	changeMoney = 1000 - price;

	countChnageBill += changeMoney / 500;
	changeMoney = changeMoney % 500;

	
	countChnageBill += changeMoney / 100;
	changeMoney = changeMoney % 100;

	countChnageBill += changeMoney / 50;
	changeMoney = changeMoney % 50;

	countChnageBill += changeMoney / 10;
	changeMoney = changeMoney % 10;

	countChnageBill += changeMoney / 5;
	changeMoney = changeMoney % 5;

	countChnageBill += changeMoney / 1;

	printf("%d", countChnageBill);

	return 0;
}
