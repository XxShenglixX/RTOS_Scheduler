#include "Task.h"

uint8_t taskOneStack[1028];
uint8_t taskTwoStack[1028];

Tcb mainTcb ;
Tcb taskOneTcb ;
Tcb taskTwoTcb ;

void taskOne()
{
	asm
	(
		"ldr r0,=#0x11111110\n\t"
	);

	return ;
}

/**
 *  Initialize all the TCBs
 */
void initTcb()
{
	mainTcb.name = "main_thread";
	mainTcb.sp = 0 ;

	taskOneTcb.name = "thread #1";

	CpuContext *context = (CpuContext *)((uint32_t)&taskOneStack[1024] - sizeof(CpuContext));
	taskOneTcb.sp =  (uint32_t)context;

	context	->	xPSR	=	0x01000000 ;
	context	->	PC		=	(uint32_t)taskOne ;
	context ->	LR		=	0XABCDEFFF;
	context ->	R0		=	0X10101010;
	context ->	R1		=	0X21212121;
	context ->	R2		=	0X32323232;
	context ->	R3		=	0X43434343;
	context ->	R4		=	0X54545454;
	context ->	R5		=	0X65656565;
	context ->	R6		=	0X76767676;
	context ->	R7		=	0X87878787;
	context ->	R8		=	0X98989898;
	context ->	R9		=	0XA9A9A9A9;
	context ->	R10		=	0XBABABABA;
	context ->	R11		=	0XCBCBCBCB;
	context ->	R12		=	0XDCDCDCDC;


}
