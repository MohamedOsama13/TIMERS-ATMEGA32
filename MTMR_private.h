/**
 * @file         MTMR_PRIVATE.h
 *
 * \b Description :
 * This file includes Timer Driver private macros
 *
 * @author      Mohamed Osama
 * @date        20/6/2022
 * @version     V1.0
 * @copyright   IMT_SCHOOL 2022
 */


#ifndef MTMR_PRIVATE_H_
#define MTMR_PRIVATE_H_

/*====================================================================================*/
/**Timer0 Waveform Generation Mode
 */

#define TIMER0_NORMAL                                           1
#define TIMER0_CTC_MODE                                         2
#define TIMER0_PHASE_CORRECT_NONINVERTED_PWM                    3
#define TIMER0_FAST_NONINVERTED_PWM                             4
#define TIMER0_FAST_INVERTED_PWM                                5
#define TIMER0_PHASE_CORRECT_INVERTED_PWM                       6

/*====================================================================================*/
/**Timer0 Prescaler Options
 */

#define TIMER0_NO_PRESCALER                                     2
#define TIMER0_8_PRESCALER                                      3
#define TIMER0_64_PRESCALER                                     4
#define TIMER0_256_PRESCALER                                    5
#define TIMER0_1024_PRESCALER                                   6
#define TIMER0_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE               7
#define TIMER0_EXTERNAL_CLOCK_SOURCE_RISING_EDGE                8
/*====================================================================================*/

/*####################################################################################*/

/*====================================================================================*/
/**Timer2 Waveform Generation Mode
 */

#define TIMER2_NORMAL                                           1
#define TIMER2_PHASE_CORRECT_NONINVERTED_PWM                    2
#define TIMER2_FAST_NONINVERTED_PWM                             3
#define TIMER2_FAST_INVERTED_PWM                                4
#define TIMER2_PHASE_CORRECT_INVERTED_PWM                       5

/*====================================================================================*/
/**Timer2 Prescaler Options
 */

#define TIMER2_NO_PRESCALER                                     2
#define TIMER2_8_PRESCALER                                      3
#define TIMER2_32_PRESCALER                                     4
#define TIMER2_64_PRESCALER                                     5
#define TIMER2_128_PRESCALER                                    6
#define TIMER2_256_PRESCALER                                    7
#define TIMER2_1024_PRESCALER                                   8
/*====================================================================================*/
#endif
