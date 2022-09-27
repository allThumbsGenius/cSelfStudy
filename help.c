#include<mega128a.h>
#include<delay.h>

void main(void){
	unsigned int led;

	DDRE = 0x0;
	DDRC = 0xFF;
	PORTC = 0xFE;
	int flag = 0;

	key = PINE & 0x10;

	while(1){
		if(key == 0x00){
			//SW1 is pushed
			flag = !flag;
		}

		if(flag == 0){
			PORTC = 0xff;
		}
		else{
			led = 0xFE;
			for(int i = 0; i < 7; ++i){
				led = led << 1;
				led = led | 0x01;
				PORTC = led;
				delay_ms(100);
			}
			for(int i = 0; i < 7; ++i){
				led = led >> 1;
				led = led | 0x80;
				PORTC = led;
				delay_ms(100);
			}
		}
	}
}
