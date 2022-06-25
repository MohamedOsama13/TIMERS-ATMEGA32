/**
 * @file         MTMR_CONFIG.h
 *
 * \b Description :
 * This file includes Timer Driver configuration
 *
 * @author      Mohamed Osama
 * @date        20/6/2022
 * @version     V1.0
 * @copyright   IMT_SCHOOL 2022
 */

#ifndef MTMR_CONFIG_H_
#define MTMR_CONFIG_H_

/**Timer0 Operation Mode Options
 *
 *                  1-TIMER0_NORMAL
 *                  2-TIMER0_CTC_MODE
 *                  3-TIMER0_PHASE_CORRECT_NONINVERTED_PWM
 *                  4-TIMER0_FAST_NONINVERTED_PWM
 *                  5-TIMER0_FAST_INVERTED_PWM
 *                  6-TIMER0_PHASE_CORRECT_INVERTED_PWM
 */
#define TIMER0_OPERATION_MODE                   TIMER0_CTC_MODE
/*====================================================================================*/

/**Timer0 Prescaler value Options
*
*                   1-TIMER0_NO_PRESCALER
*                   2-TIMER0_8_PRESCALER
*                   3-TIMER0_64_PRESCALER
*                   4-TIMER0_256_PRESCALER
*                   5-TIMER0_1024_PRESCALER
*                   6-TIMER0_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE
*                   7-TIMER0_EXTERNAL_CLOCK_SOURCE_RISING_EDGE
*/
#define TIMER0_SET_PRESCALER                    TIMER0_8_PRESCALER

/*====================================================================================*/
/*####################################################################################*/
/*====================================================================================*/

/**Timer2 Operation Mode Options
 *
 *                  1-TIMER2_NORMAL
 *                  2-TIMER2_PHASE_CORRECT_NONINVERTED_PWM
 *                  3-TIMER2_FAST_NONINVERTED_PWM
 *                  4-TIMER2_FAST_INVERTED_PWM
 *                  5-TIMER2_PHASE_CORRECT_INVERTED_PWM
 */
#define TIMER2_OPERATION_MODE                    TIMER2_NORMAL
/*====================================================================================*/

/**Timer2 Prescaler value Options
*
*                   1-TIMER2_NO_PRESCALER
*                   2-TIMER2_8_PRESCALER
*                   3-TIMER2_32_PRESCALER
*                   4-TIMER2_64_PRESCALER
*                   5-TIMER2_128_PRESCALER
*                   6-TIMER2_256_PRESCALER
*                   7-TIMER2_1024_PRESCALER
*/
#define TIMER2_SET_PRESCALER                     TIMER2_8_PRESCALER
#endif
