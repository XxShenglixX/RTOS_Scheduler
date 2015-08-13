#ifndef Task_H
#define Task_H

#include <stdint.h>

typedef struct
{
	char 		*name ;
	uint32_t 	sp ;

}Tcb;

typedef struct
{
	uint32_t R4;
	uint32_t R5;
	uint32_t R6;
	uint32_t R7;
	uint32_t R8;
	uint32_t R9;
	uint32_t R10;
	uint32_t R11;
	uint32_t R0;
	uint32_t R1;
	uint32_t R2;
	uint32_t R3;
	uint32_t R12;
	uint32_t LR;
	uint32_t PC;
	uint32_t xPSR ;
}CpuContext;

extern  uint8_t taskOneStack[1028];
extern  uint8_t taskTwoStack[1028];

#endif // Task_H
