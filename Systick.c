/*This is the Strage API for storing data either on SPI flash or onchip flas*/
#include "Systick.h"
#include "Common.h"
#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
static unsigned long SysTick_Val=0;
void Systick_init(void)
{
	WKCON=0x00;//Setting Wakeup timer Clock at 10 KHZ
	clr_WKTF;//Clearing the Overflow Flag;
	RWK=(0xFF-0x09);//Loading 10 to the Preload register
	set_EWKT;//Selfwake Timer Flag.
	set_WKTR;//Run SelfWake Timer
}
void SLF_WK_INT (void) interrupt 17
{
	clr_WKTF;
	SysTick_Val++;
	if(SysTick_Val>MAX_SYSTICK)
	{
		SysTick_Val=0;
		//Perform System Reset approx after 50 days;
	}
}

unsigned long Systick(void)
{
	return SysTick_Val;
}
