#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	int *distanceBetweenCity;
	int *oilPricePerCity;

	scanf("%d", &n);

	distanceBetweenCity = (int*)malloc(n - 1 * sizeof(int));
	oilPricePerCity = (int*)malloc(n * sizeof(int));

	for(int i = 0; i < n - 1; ++i){
		scanf("%d", &distanceBetweenCity[i]);
	}
	for(int i = 0; i < n; ++i){
		scanf("%d", &oilPricePerCity[i]);
	}
	
	int minPrice = oilPricePerCity[0];
	long long int totalPrice = 0;
	for(int i = 0; i < n - 1; ++i){
		if(minPrice > oilPricePerCity[i]){
			minPrice = oilPricePerCity[i];
		}
		totalPrice += minPrice * distanceBetweenCity[i];
	}

	printf("%lld", totalPrice);

	free(distanceBetweenCity);
	free(oilPricePerCity);

	return 0;
}
