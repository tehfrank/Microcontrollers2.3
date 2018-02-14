/*
 * les1.c
 *
 * Created: 8-2-2018 15:35:33
 * Author : frank
 */ 

#include <avr/io.h>
#include <util/delay.h>

int stateNum = 0;

void opdracht7();
void checkState();
void wait(int);
 
int main(void)
{
	DDRD = 0b11111111;
	DDRC = 0b00000000;
	
    while (1) 
    {
		opdracht7();
    }
	
	return 1;
}

void opdracht7 (){
		if(stateNum == 0){
		PORTD = 0x01;
		}else if(stateNum == 1){
		PORTD = 0x02;
		}else if(stateNum == 2){
		PORTD = 0x04;
		}else if(stateNum == 3){
		PORTD = 0x08;
		}else if(stateNum == 4){
		PORTD = 0x10;
		}	
	checkState();
}

void checkState(){
	if((PINC == 0b01000000 && stateNum == 0 )||(PINC == 0b01000000 && stateNum == 2)){
		stateNum = 1;
	}else if((PINC == 0b10000000 && stateNum == 1 )|| (PINC == 0b10000000 && stateNum == 4) || (PINC == 0b10000000 && stateNum == 3) || (PINC == 0b10000000 && stateNum == 2)){
		stateNum = 0;
	}else if((PINC == 0b00100000 && stateNum == 0 )|| (PINC == 0b00100000 && stateNum == 1)){
		stateNum = 2;
	}else if(PINC == 0b00100000 && stateNum == 2){
		stateNum = 3;
	}else if((PINC == 0b00100000 && stateNum == 3 )|| (PINC == 0b01000000 && stateNum == 3)){
		stateNum = 4;
	}
}

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );
	}
}