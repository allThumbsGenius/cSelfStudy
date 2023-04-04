#include<stdio.h>

int main(){
	float a, b;
	int selectedOperator;
	int continueSelect;
	int continueVal = 1;

	while(continueVal){
		printf("--------------------\n");
		printf("숫자 2개를 입력해 주세요: ");
		scanf("%f%f", &a, &b);
		if(a - (int)(a) != 0 || b - (int)(b) != 0){
		// 둘중 한개라도 실수 면 
			printf("1.+ 2.- 3.* 4./ \n");
			printf("연산을 선택하세요 : ");
			scanf("%d", &selectedOperator);
			printf("--------------------\n");
			switch(selectedOperator){
				case(1):
					printf("%f + %f = %f\n", a, b, a + b);
					break;
				case(2):
					printf("%f - %f = %f\n", a, b, a - b);
					break;
				case(3):
					printf("%f * %f = %f\n", a, b, a * b);
					break;
				case(4):
					if(b == 0){
						printf("can't divided by zero\n");
						break;
					}
					printf("%f / %f = %f\n", a, b, a / b);
					break;
				default:
					printf("잘못된 연산을 입력했어요\n");
			}
		}
		else{
			printf("1.+ 2.- 3.* 4./ 5. %%\n");
			printf("연산을 선택하세요 : ");
			scanf("%d", &selectedOperator);
			printf("--------------------\n");
			switch(selectedOperator){
				case(1):
					printf("%d + %d = %d\n", (int)a, (int)b, (int)a + (int)b);
					break;
				case(2):
					printf("%d - %d = %d\n", (int)a, (int)b, (int)a - (int)b);
					break;
				case(3):
					printf("%d * %d = %d\n", (int)a, (int)b, (int)a * (int)b);
					break;
				case(4):
					if(b == 0){
						printf("can't divided by zero\n");
						break;
					}
					printf("%d / %d = %d\n", (int)a, (int)b, (int)a / (int)b);
					break;
				case(5):
					if(b == 0){
						printf("can't divided by zero\n");
						break;
					}
					printf("%d %% %d = %d\n", (int)a, (int)b, (int)a % (int)b);
					break;
				default:
					printf("잘못된 연산을 입력했어요\n");
			}
		}
		printf("--------------------\n");
		printf("continue? 1. yes 2. no\n");
		scanf("%d", &continueSelect);
		if(continueSelect == 2){
			continueVal = 0;
		}
	}
	return 0;
}
