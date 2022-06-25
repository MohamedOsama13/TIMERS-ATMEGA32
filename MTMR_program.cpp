/**
 * @file         MTMR_PROGRAM.cpp
 *
 * \b Description :
 * This file includes Timer Driver implementation
 *
 * @author      Mohamed Osama
 * @date        20/6/2022
 * @version     V1.0
 * @copyright   IMT_SCHOOL 2022
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "MTMR_interface.h"
#include "MTMR_register.h"
#include "MTMR_private.h"
#include "MTMR_config.h"


/**Global pointer to function to hold OVF0 INT ISR address*/
static void (*MTMR_pvOVF0CallBackFUNC)(void) = NULL;

/**Global pointer to function to hold OVF2 INT ISR address*/
static void (*MTMR_pvOVF2CallBackFUNC)(void) = NULL;

/**Global pointer to function to hold CTC0 INT ISR address*/
static void (*MTMR_pvCTC0CallBackFUNC)(void) = NULL;


void Timer0::MTMR_voidTimer0Init(void)
{

#if   TIMER0_OPERATION_MODE == TIMER0_NORMAL

	/*Setting waveform generation mode bits to NORMAL mode*/
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	/*Setting compare match output mode bits to NORMAL PORT OPERATION (OC0 disconnected)*/
	CLR_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);

	/*Timer0 overflow interrupt enable*/
	SET_BIT(TIMSK,TIMSK_TOIE0);

#elif   TIMER0_OPERATION_MODE == TIMER0_CTC_MODE

	/*Setting waveform generation mode bits to CTC mode*/
		CLR_BIT(TCCR0,TCCR0_WGM00);
		SET_BIT(TCCR0,TCCR0_WGM01);

	/*Setting compare match output mode bits to NORMAL PORT OPERATION (OC0 disconnected)*/
		CLR_BIT(TCCR0,TCCR0_COM00);
		CLR_BIT(TCCR0,TCCR0_COM01);

	/*Timer0 compare match interrupt enable*/
		SET_BIT(TIMSK,TIMSK_OCIE0);

#elif   TIMER0_OPERATION_MODE == TIMER0_PHASE_CORRECT_NONINVERTED_PWM

	/*Setting waveform generation mode bits to PWM,Phase correct mode*/
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	/*Setting compare match output mode bits to Clear OC0 on compare match when up-counting. Set OC0 on compare
      match when downcounting */
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

#elif TIMER0_OPERATION_MODE == TIMER0_FAST_NONINVERTED_PWM

	/*Setting waveform generation mode bits to Fast PWM mode*/
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/*Setting compare match output mode bits to Clear OC0 on compare match, set OC0 at TOP */
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

#elif   TIMER0_OPERATION_MODE == TIMER0_FAST_INVERTED_PWM

	/*Setting waveform generation mode bits to Fast PWM mode*/
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/*Setting compare match output mode bits to Set OC0 on compare match, clear OC0 at TOP */
	SET_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

#elif TIMER0_OPERATION_MODE == TIMER0_PHASE_CORRECT_INVERTED_PWM

	/*Setting waveform generation mode bits to PWM,Phase correct mode*/
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	/*Setting compare match output mode bits to Set OC0 on compare match when up-counting. Clear OC0 on compare
      match when downcounting  */
	SET_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
#else
#error "Wrong Timer0 Mode Selection.."
#endif



#if   TIMER0_SET_PRESCALER == TIMER0_NO_PRESCALER

	/*Setting Clock bits to (No prescaling)*/
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

#elif TIMER0_SET_PRESCALER == TIMER0_8_PRESCALER

	/*Setting Clock bits to clk/8 */
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

#elif TIMER0_SET_PRESCALER == TIMER0_64_PRESCALER

	/*Setting Clock bits to clk/64 */
	SET_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

#elif TIMER0_SET_PRESCALER == TIMER0_256_PRESCALER

	/*Setting Clock bits to clk/256 */
	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);

#elif TIMER0_SET_PRESCALER == TIMER0_1024_PRESCALER

	/*Setting Clock bits to clk/1024 */
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);

#elif TIMER0_SET_PRESCALER == TIMER0_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE

	/*External clock source on T0 pin. Clock on falling edge*/
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);

#elif TIMER0_SET_PRESCALER == TIMER0_EXTERNAL_CLOCK_SOURCE_RISING_EDGE

	/*External clock source on T0 pin. Clock on rising edge*/
	SET_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);
#else
#error "Wrong Timer0 Prescaler Selection.."
#endif

}

u8 Timer0::MTMR_u8Timer0Disable(void)
{
	u8 Local_u8ErrorState = OK ;

	/*Setting clock bits to NO clock source */
	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);


	return Local_u8ErrorState ;
}

u8 Timer0::MTMR_u8Timer0SetPreloadValue(u8 Copy_u8PreloadValue)
{
	u8 Local_u8ErrorState = OK ;

	if ( (Copy_u8PreloadValue <= 255) && (Copy_u8PreloadValue >=0 ) )
	{
		TCNT0 = Copy_u8PreloadValue;
	}
	else
	{
		Local_u8ErrorState = NOK ;
	}

	return Local_u8ErrorState ;
}

u8 Timer0::MTMR_u8Timer0GetCounterValue(u8* Copy_pu16CounterValue)
{
	u8 Local_u8ErrorState = OK;


	/*checking if passed pointer is NULL*/
	if (Copy_pu16CounterValue != NULL)
	{
		/*Passing counter register TCNT0 value through sent pointer*/
		*Copy_pu16CounterValue=TCNT0;
	}

	else
	{
		/*setting error state to NULL pointer*/
		Local_u8ErrorState=NULL_POINTER;
	}

	/*returning error state*/
	return Local_u8ErrorState;
}

u8 Timer0::MTMR_u8Timer0SetCompareMatchValue(u8 Copy_u8CTCValue)
{
	u8 Local_u8ErrorState = OK;

	if ( (Copy_u8CTCValue <= 255) && (Copy_u8CTCValue >=0) )
	{
		OCR0 = Copy_u8CTCValue ;
	}
	else
	{
		Local_u8ErrorState = NOK ;
	}

	return Local_u8ErrorState ;
}



u8 Timer0::MTMR_u8Timer0GeneratePWM(u8 Copy_u8DutyCycle)
{
	u8 Local_u8ErrorState = OK;


	if ( (Copy_u8DutyCycle >= 0) && (Copy_u8DutyCycle <= 255) )
	{
		/*putting sent value in Output Compare Register OCR0 */
		OCR0 = Copy_u8DutyCycle;
	}
	else
	{
		Local_u8ErrorState = NOK ;
	}

	/*returning error state*/
	return Local_u8ErrorState;
}

u8 Timer0::MTMR_u8Timer0OVFSetCallBack(void (*Copy_pf)(void))
{
	u8 Local_u8ErrorState = OK;


	/*checking if passed pointer is NULL*/
	if(Copy_pf != NULL)
	{
		MTMR_pvOVF0CallBackFUNC = Copy_pf;
	}
	else
	{
		/*setting error state to NULL pointer*/
		Local_u8ErrorState = NULL_POINTER;
	}

	/*returning error state*/
	return Local_u8ErrorState ;
}

u8 Timer0::MTMR_u8Timer0CTCSetCallBack(void (*Copy_pf)(void))
{
	u8 Local_u8ErrorState = OK;


		/*checking if passed pointer is NULL*/
		if(Copy_pf != NULL)
		{
			MTMR_pvCTC0CallBackFUNC = Copy_pf;
		}
		else
		{
			/*setting error state to NULL pointer*/
			Local_u8ErrorState = NULL_POINTER;
		}

		/*returning error state*/
		return Local_u8ErrorState ;
}

#ifdef __cplusplus
extern "C"
{
#endif


void __vector_11 (void)        __attribute__((signal));
void __vector_11 (void)
{

	/*checking if passed pointer is NULL*/
	if (MTMR_pvOVF0CallBackFUNC != NULL)
	{
		MTMR_pvOVF0CallBackFUNC();
	}

}

void __vector_10 (void)        __attribute__((signal));
void __vector_10 (void)
{

	/*checking if passed pointer is NULL*/
	if (MTMR_pvCTC0CallBackFUNC != NULL)
	{
		MTMR_pvCTC0CallBackFUNC();
	}

}
#ifdef __cplusplus
}
#endif

/*##############################################################################################################*/
/*##############################################################################################################*/
/*##############################################################################################################*/


void Timer2::MTMR_voidTimer2Init(void)
{

#if   TIMER2_OPERATION_MODE == TIMER2_NORMAL

	/*Setting waveform generation mode bits to NORMAL mode*/
	CLR_BIT(TCCR2,TCCR2_WGM20);
	CLR_BIT(TCCR2,TCCR2_WGM21);

	/*Setting compare match output mode bits to NORMAL PORT OPERATION (OC2 disconnected)*/
	CLR_BIT(TCCR2,TCCR2_COM20);
	CLR_BIT(TCCR2,TCCR2_COM21);

	/*Timer2 overflow interrupt enable*/
	SET_BIT(TIMSK,TIMSK_TOIE2);


#elif   TIMER2_OPERATION_MODE == TIMER2_PHASE_CORRECT_NONINVERTED_PWM

	/*Setting waveform generation mode bits to PWM,Phase correct mode*/
	SET_BIT(TCCR2,TCCR2_WGM20);
	CLR_BIT(TCCR2,TCCR2_WGM21);

	/*Setting compare match output mode bits to Clear OC0 on compare match when up-counting. Set OC0 on compare
      match when downcounting */
	CLR_BIT(TCCR2,TCCR2_COM20);
	SET_BIT(TCCR2,TCCR2_COM21);

#elif TIMER2_OPERATION_MODE == TIMER2_FAST_NONINVERTED_PWM

	/*Setting waveform generation mode bits to Fast PWM mode*/
	SET_BIT(TCCR2,TCCR2_WGM20);
	SET_BIT(TCCR2,TCCR2_WGM21);

	/*Setting compare match output mode bits to Clear OC0 on compare match, set OC0 at TOP */
	CLR_BIT(TCCR2,TCCR2_COM20);
	SET_BIT(TCCR2,TCCR2_COM21);

#elif   TIMER2_OPERATION_MODE == TIMER2_FAST_INVERTED_PWM

	/*Setting waveform generation mode bits to Fast PWM mode*/
	SET_BIT(TCCR2,TCCR2_WGM20);
	SET_BIT(TCCR2,TCCR2_WGM21);

	/*Setting compare match output mode bits to Set OC2 on compare match, clear OC0 at TOP */
	SET_BIT(TCCR2,TCCR2_COM20);
	SET_BIT(TCCR2,TCCR2_COM21);

#elif TIMER2_OPERATION_MODE == TIMER2_PHASE_CORRECT_INVERTED_PWM

	/*Setting waveform generation mode bits to PWM,Phase correct mode*/
	SET_BIT(TCCR2,TCCR2_WGM20);
	CLR_BIT(TCCR2,TCCR2_WGM21);

	/*Setting compare match output mode bits to Set OC2 on compare match when up-counting. Clear OC0 on compare
      match when downcounting  */
	SET_BIT(TCCR2,TCCR2_COM20);
	SET_BIT(TCCR2,TCCR2_COM21);
#else
#error "Wrong Timer2 Mode Selection.."
#endif



#if   TIMER2_SET_PRESCALER == TIMER2_NO_PRESCALER

	/*Setting Clock bits to (No prescaling)*/
	SET_BIT(TCCR2,TCCR2_CS20);
	CLR_BIT(TCCR2,TCCR2_CS21);
	CLR_BIT(TCCR2,TCCR2_CS22);

#elif TIMER2_SET_PRESCALER == TIMER2_8_PRESCALER

	/*Setting Clock bits to clk/8 */
	CLR_BIT(TCCR2,TCCR2_CS20);
	SET_BIT(TCCR2,TCCR2_CS21);
	CLR_BIT(TCCR2,TCCR2_CS22);

#elif TIMER2_SET_PRESCALER == TIMER2_32_PRESCALER

	/*Setting Clock bits to clk/32 */
	SET_BIT(TCCR2,TCCR2_CS20);
	SET_BIT(TCCR2,TCCR2_CS21);
	CLR_BIT(TCCR2,TCCR2_CS22);

#elif TIMER2_SET_PRESCALER == TIMER2_64_PRESCALER

	/*Setting Clock bits to clk/64 */
	CLR_BIT(TCCR2,TCCR2_CS20);
	CLR_BIT(TCCR2,TCCR2_CS21);
	SET_BIT(TCCR2,TCCR2_CS22);

#elif TIMER2_SET_PRESCALER == TIMER2_128_PRESCALER

	/*Setting Clock bits to clk/128 */
	SET_BIT(TCCR2,TCCR2_CS20);
	CLR_BIT(TCCR2,TCCR2_CS21);
	SET_BIT(TCCR2,TCCR2_CS22);

#elif TIMER2_SET_PRESCALER == TIMER2_256_PRESCALER

	/*Setting Clock bits to clk/256 */
	CLR_BIT(TCCR2,TCCR2_CS20);
	SET_BIT(TCCR2,TCCR2_CS21);
	SET_BIT(TCCR2,TCCR2_CS22);

#elif TIMER2_SET_PRESCALER == TIMER2_1024_PRESCALER

	/*Setting Clock bits to clk/1024 */
	SET_BIT(TCCR2,TCCR2_CS20);
	SET_BIT(TCCR2,TCCR2_CS21);
	SET_BIT(TCCR2,TCCR2_CS22);
#else
#error "Wrong Timer2 Prescaler Selection.."
#endif

}

u8 Timer2::MTMR_u8Timer2GetCounterValue(u8* Copy_pu16CounterValue)
{
	u8 Local_u8ErrorState = OK;


	/*checking if passed pointer is NULL*/
	if (Copy_pu16CounterValue != NULL)
	{
		/*Passing counter register TCNT2 value through sent pointer*/
		*Copy_pu16CounterValue=TCNT2;
	}

	else
	{
		/*setting error state to NULL pointer*/
		Local_u8ErrorState=NULL_POINTER;
	}

	/*returning error state*/
	return Local_u8ErrorState;
}

u8 Timer2::MTMR_u8Timer2GeneratePWM(u8 Copy_u8DutyCycle)
{
	u8 Local_u8ErrorState = OK;


	if ( (Copy_u8DutyCycle >= 0) && (Copy_u8DutyCycle <= 255) )
	{
		/*putting sent value in Output Compare Register OCR2 */
		OCR2 = Copy_u8DutyCycle;
	}
	else
	{
		Local_u8ErrorState = NOK ;
	}

	/*returning error state*/
	return Local_u8ErrorState;
}

u8 Timer2::MTMR_u8Timer2OVFSetCallBack(void (*Copy_pf)(void))
{
	u8 Local_u8ErrorState = OK;


	/*checking if passed pointer is NULL*/
	if(Copy_pf != NULL)
	{
		MTMR_pvOVF2CallBackFUNC = Copy_pf;
	}
	else
	{
		/*setting error state to NULL pointer*/
		Local_u8ErrorState = NULL_POINTER;
	}

	/*returning error state*/
	return Local_u8ErrorState ;
}

#ifdef __cplusplus
extern "C"
{
#endif
void __vector_5 (void)        __attribute__((signal));
void __vector_5 (void)
{

	/*checking if passed pointer is NULL*/
	if (MTMR_pvOVF2CallBackFUNC != NULL)
	{
		MTMR_pvOVF2CallBackFUNC();
	}
}
#ifdef __cplusplus
}
#endif

