#include "sys/alt_stdio.h"
#include "altera_avalon_pio_regs.h"
#include "altera_avalon_timer_regs.h"
#include "system.h"
#include "stdio.h"

static unsigned leds = 0;
int sec0;
int sec1;
int min0;
int min1;
int hour0;
int hour1;

static void initial_timer(){
	volatile unsigned long * seg0= (short *) 0x30b0;
	volatile unsigned long * seg1= (short *) 0x30a0;
	volatile unsigned long * seg2= (short *) 0x3090;
	volatile unsigned long * seg3= (short *) 0x3080;
	volatile unsigned long * seg4= (short *) 0x3070;
	volatile unsigned long * seg5= (short *) 0x3060;

	*seg0 = 1000000;
	*seg1 = 1000000;
	*seg2 = 1000000;
	*seg3 = 1000000;
	*seg4 = 1000000;
	*seg5 = 1000000;


	sec1=5;
	min0=9;
	min1=5;
	hour0=9;
	hour1=1;

	*seg1 = 18;
	*seg2 = 16;
	*seg3 = 18;
	*seg4 = 16;
	*seg5 = 79;

}

static void timer_isr(void *context){
	(void) context;

	leds = leds << 1 | (IORD_ALTERA_AVALON_PIO_DATA(KEY_1_BASE)&1);
	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, leds);
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0);

	volatile unsigned long * seg0= (short *) 0x30b0;
	volatile unsigned long * seg1= (short *) 0x30a0;
	volatile unsigned long * seg2= (short *) 0x3090;
	volatile unsigned long * seg3= (short *) 0x3080;
	volatile unsigned long * seg4= (short *) 0x3070;
	volatile unsigned long * seg5= (short *) 0x3060;

	static int count = 0;

	//Clear the interrupt
		IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0);
		/*
		 * 0 = 1000000
		 * 1 = 79
		 * 2 = 36
		 * 3 = 48
		 * 4 = 25
		 * 5 = 18
		 * 6 = 2
		 * 7 = 120
		 * 8 = 0011000
		 * 9 = 16
		 */
		int data[] = {1000000, 79, 36, 48, 25, 18, 2, 120, 0011000, 16};

		if (sec0/1000 < 10){
			sec0 ++;
			*seg0 = data[sec0/1000];
		}else{
			if(sec1 < 5){
				sec0 = 0;
				*seg0 = data[sec0];
				sec1 ++;
				*seg1 = data[sec1];
			}else{
				if(min0 < 9){
					sec1 = 0;
					*seg1 = data[sec1];
					sec0 = 0;
					*seg0 = data[sec0];
					min0 ++;
					*seg2 = data[min0];
			}else{
				if(min1<5){
					sec1 = 0;
					*seg1 = data[sec1];
					sec0 = 0;
					*seg0 = data[sec0];
					min0 = 0;
					*seg2 = data[min0];
					min1 ++;
					*seg3 = data[min1];
				}else{
					if(hour1 == 2 && hour0 == 3){
						sec1 = 0;
						*seg1 = data[sec1];
						sec0 = 0;
						*seg0 = data[sec0];
						min0 = 0;
						*seg2 = data[min0];
						min1 = 0;
						*seg3 = data[min1];
						hour0 = 0;
						*seg4 = data[hour0];
						hour1 = 0;
						*seg5 = data[hour1];

					}else{
						if((hour1 == 0||hour1 == 1) && hour0 == 9){
							sec1 = 0;
							*seg1 = data[sec1];
							sec0 = 0;
							*seg0 = data[sec0];
							min0 = 0;
							*seg2 = data[min0];
							min1 = 0;
							*seg3 = data[min1];
							hour0 = 0;
							*seg4 = data[hour0];
							hour1 ++;
							*seg5 = data[hour1];
						}else{
							sec1 = 0;
							*seg1 = data[sec1];
							sec0 = 0;
							*seg0 = data[sec0];
							min0 = 0;
							*seg2 = data[min0];
							min1 = 0;
							*seg3 = data[min1];
							hour0 ++;
							*seg4 = data[hour0];
						}
					}
				}
			}
		}
	}

		count++;

}

int main()
{ 
  alt_putstr("Hello from Nios II!\n");
  initial_timer();

  alt_ic_isr_register(
		  TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID,
		  TIMER_0_IRQ,
		  timer_isr,
		  NULL,
		  NULL);

  IOWR_ALTERA_AVALON_TIMER_CONTROL(
  		  TIMER_0_BASE,
  		  ALTERA_AVALON_TIMER_CONTROL_ITO_MSK
  		  | ALTERA_AVALON_TIMER_CONTROL_CONT_MSK);

 //Son amigos para siempre y por siempre
  while (1);
  return 0;
 //En las buenas y en las malaaaas
}

