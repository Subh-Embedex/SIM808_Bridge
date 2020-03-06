/*Systick will be created using a free timer available for system time keeeping*/ 
#ifndef _SYSTICK_H_
#define _SYSTICK_H_
#include "Common.h"
#include <limits.h>
#define MAX_SYSTICK   ULONG_MAX      
void Systick_init(void);
unsigned long Systick(void);

#endif