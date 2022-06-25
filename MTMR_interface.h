/**
 * @file         MTMR_INTERFACE.h
 *
 * \b Description :
 * This file includes Timer Driver prototypes and macros
 *
 * @author      Mohamed osama
 * @date        20/6/2022
 * @version     V1.0
 * @copyright   IMT_SCHOOL 2022
 */
#ifndef MTMR_INTERFACE_H_
#define MTMR_INTERFACE_H_

class Timer0
{
	public:

/*===========================================================================================================================*/
	/**
	 * Prototype   : void MTMR_voidTimer0Init(void);
	 *
	 * \b Description :
	 * In this function you will initialization the mode you will work with it in Timer 0
	 * @param   void
	 * @return  void
	 */
	void MTMR_voidTimer0Init(void);
/*===========================================================================================================================*/
	/**
	 * Prototype   : u8 MTMR_u8Timer0Disable(void);
	 *
	 * \b Description :
	 * This function used to disable Timer0
	 * @param   void
	 * @return  u8 for error state
	 */
	u8 MTMR_u8Timer0Disable(void);
/*===========================================================================================================================*/
	/**
	 * Prototype   : u8 MTMR_u8Timer0SetTimerPreload(u8 Copy_u8PreloadValue);
	 *
	 * \b Description :
	 * This function for setting preload value inside TCNT0 Register
	 * @param   Copy_u8PreloadValue passing value to TCNT0 register
	 * @return  u8 for error state
	 */
	u8 MTMR_u8Timer0SetPreloadValue(u8 Copy_u8PreloadValue);
/*===========================================================================================================================*/
	/**
	 * Prototype   : u8 MTMR_u8Timer0GetCounterValue(u8* Copy_pu16CounterValue);
	 *
	 * \b Description :
	 * This function for getting the value of counting inside TCNT0 Register
	 * @param   Copy_pu16CounterValue pointer to get the value of TCNT0
	 * @return  u8 for error state
	 */
	u8 MTMR_u8Timer0GetCounterValue(u8* Copy_pu16CounterValue);
/*===========================================================================================================================*/
	/**
	 * Prototype   : u8 MTMR_u8Timer0SetCompareMatchValue(u8 Copy_u8CTCValue);
	 *
	 * \b Description :
	 * This function for setting compare match value inside OCR0 register
	 * @param   Copy_u8CTCValue passing OCR0 register value
	 * @return  u8 for error state
	 */
	u8 MTMR_u8Timer0SetCompareMatchValue(u8 Copy_u8CTCValue);
/*===========================================================================================================================*/
	/**
	 * Prototype   : u8 MTMR_u8Timer0GeneratePWM(u8 Copy_u8DutyCycle);
	 *
	 * \b Description :
	 * This function for generate a PWM by using Timer0
	 * @param   Copy_u8DutyCycle the value you want in pulse to be high
	 * @return  u8 for error state
	 */
	u8 MTMR_u8Timer0GeneratePWM(u8 Copy_u8DutyCycle);
/*===========================================================================================================================*/
	/**
	 * Prototype   : u8 MTMR_u8Timer0OVFSetCallBack(void (*Copy_pf)(void));
	 *
	 * \b Description :
	 * This function for communication between application and Timer0 without destroying the layered architecture
	 * @param   void (*Copy_pf)(void) pointer to function for the application function
	 * @return  u8 for error state
	 */
	u8 MTMR_u8Timer0OVFSetCallBack(void (*Copy_pf)(void));
/*===========================================================================================================================*/
	/**
	 * Prototype   : u8 MTMR_u8Timer0CTCSetCallBack(void (*Copy_pf)(void));
	 *
	 * \b Description :
	 * This function for communication between application and Timer0 without destroying the layered architecture call back for CTC ISR
	 * @param   void (*Copy_pf)(void) pointer to function for the application function
	 * @return  u8 for error state
	 */
	u8 MTMR_u8Timer0CTCSetCallBack(void (*Copy_pf)(void));
/*===========================================================================================================================*/
};



class Timer2
{
	public:

/*===========================================================================================================================*/
	/**
	 * Prototype   : void MTMR_voidTimer2Init(void);
	 *
	 * \b Description :
	 * In this function you will initialization the mode you will work with it in Timer 2
	 * @param   void
	 * @return  void
	 */
	void MTMR_voidTimer2Init(void);
/*===========================================================================================================================*/
	/**
	 * Prototype   : u8 MTMR_u8Timer2GetCounterValue(u8* Copy_pu16CounterValue);
	 *
	 * \b Description :
	 * This function for getting the value of counting inside TCNT2 Register
	 * @param   Copy_pu16CounterValue pointer to get the value of TCNT2
	 * @return  u8 for error state
	 */
	u8 MTMR_u8Timer2GetCounterValue(u8* Copy_pu16CounterValue);
/*===========================================================================================================================*/
	/**
	 * Prototype   : u8 MTMR_u8Timer2GeneratePWM(u8 Copy_u8DutyCycle);
	 *
	 * \b Description :
	 * This function for generate a PWM by using Timer2
	 * @param   Copy_u8DutyCycle the value you want in pulse to be high
	 * @return  u8 for error state
	 */
	u8 MTMR_u8Timer2GeneratePWM(u8 Copy_u8DutyCycle);
/*===========================================================================================================================*/
	/**
	 * Prototype   : u8 MTMR_u8Timer2OVFSetCallBack(void (*Copy_pf)(void));
	 *
	 * \b Description :
	 * This function for communication between application and Timer2 without destroying the layered architecture
	 * @param   void (*Copy_pf)(void) pointer to function for the application function
	 * @return  u8 for error state
	 */
	u8 MTMR_u8Timer2OVFSetCallBack(void (*Copy_pf)(void));
/*===========================================================================================================================*/
};

#endif
