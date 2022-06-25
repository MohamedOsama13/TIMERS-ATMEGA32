/**
 * @file         MTMR_REGISTER.h
 *
 * \b Description :
 * This file includes Timer Driver registers
 *
 * @author      Mohamed Osama
 * @date        20/6/2022
 * @version     V1.0
 * @copyright   IMT_SCHOOL 2022
 */

#ifndef MTMR_REGISTER_H_
#define MTMR_REGISTER_H_

/**Timer0 control register*/
#define TCCR0           *((volatile u8*)0x53)

/**Timer0 Waveform generation mode bit0*/
#define TCCR0_WGM00     6
/**Timer0 Waveform generation mode bit1*/
#define TCCR0_WGM01     3


/**Timer0 Compare Match Output Mode bit0*/
#define TCCR0_COM00     4
/**Timer0 Compare Match Output Mode bit1*/
#define TCCR0_COM01     5


/**Timer0 Prescaler bit0*/
#define TCCR0_CS00      0
/**Timer0 Prescaler bit1*/
#define TCCR0_CS01      1
/**Timer0 Prescaler bit2*/
#define TCCR0_CS02      2

/**Timer0 Output compare register0*/
#define OCR0            *((volatile u8*)0x5c)

/**Timer mask register*/
#define TIMSK           *((volatile u8*)0x59)
/**Timer0 Overflow interrupt enable Bit*/
#define TIMSK_TOIE0     0
/**Timer0 Output compare match interrupt enable bit*/
#define TIMSK_OCIE0     1
/**The Timer0 Register*/
#define TCNT0           *((volatile u8*)0x52)


/*#######################################################################*/


/**Timer2 control register*/
#define TCCR2           *((volatile u8*)0x45)

/**Timer2 Waveform generation mode bit0*/
#define TCCR2_WGM20     6
/**Timer2 Waveform generation mode bit1*/
#define TCCR2_WGM21     3


/**Timer2 Compare Match Output Mode bit0*/
#define TCCR2_COM20     4
/**Timer2 Compare Match Output Mode bit1*/
#define TCCR2_COM21     5


/**Timer2 Prescaler bit0*/
#define TCCR2_CS20      0
/**Timer2 Prescaler bit1*/
#define TCCR2_CS21      1
/**Timer2 Prescaler bit2*/
#define TCCR2_CS22      2

/**Timer2 Output compare register0*/
#define OCR2            *((volatile u8*)0x43)

/**Timer2 Overflow interrupt enable Bit*/
#define TIMSK_TOIE2     6

/**The Timer2 Register*/
#define TCNT2           *((volatile u8*)0x44)



#endif
