#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	long long int *distanceBetweenCity;
	int oilPricePerCity;

	scanf("%d", &n);

	distanceBetweenCity = (long long int*)malloc(n - 1 * sizeof(long long int));

	for(int i = 0; i < n - 1; ++i){
		scanf("%lld", &distanceBetweenCity[i]);
	}

	scanf("%d", &oilPricePerCity);
	int minPrice = oilPricePerCity;
	long long int totalPrice = 0;
	for(int i = 0; i < n -1; ++i, scanf("%d", &oilPricePerCity)){
		if(minPrice > oilPricePerCity){
			minPrice = oilPricePerCity;
		}
		totalPrice += minPrice * distanceBetweenCity[i];
	}

	printf("%lld", totalPrice);

	free(distanceBetweenCity);

	return 0;
}
