#include "Task.h"
#include "LinkedList.h"

LinkedList linkedList;
ListElement mainElement;
ListElement firstElement;
ListElement secondElement;

uint8_t taskOneStack[1028];
uint8_t taskTwoStack[1028];

Tcb mainTcb ;
Tcb taskOneTcb ;
Tcb taskTwoTcb ;
Tcb *runningTcb ;

void taskOne()
{
	asm
	(
		"ldr r0,=#0xFFFFFFFF\n\t"
	);

	while(1);
}

void taskTwo()
{
	asm
		(
			"ldr r0,=#0xEEEEEEEE\n\t"
		);
	while(1);
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

	CpuContext *context1 = (CpuContext *)((uint32_t)&taskTwoStack[1024] - sizeof(CpuContext));
	taskTwoTcb.sp =  (uint32_t)context1;

	context1 ->	xPSR	=	0x01000000 ;
	context1 ->	PC		=	(uint32_t)taskTwo ;
	context1 ->	LR		=	0XABCDEFFF;
	context1 ->	R0		=	0X01010101;
	context1 ->	R1		=	0X12121212;
	context1 ->	R2		=	0X23232323;
	context1 ->	R3		=	0X34343434;
	context1 ->	R4		=	0X45454545;
	context1 ->	R5		=	0X56565656;
	context1 ->	R6		=	0X67676767;
	context1 ->	R7		=	0X78787878;
	context1 ->	R8		=	0X89898989;
	context1 ->	R9		=	0X9a9a9a9a;
	context1 ->	R10		=	0Xabababab;
	context1 ->	R11		=	0Xbcbcbcbc;
	context1 ->	R12		=	0Xcdcdcdcd;


	initLinkedList(&linkedList);
	listElementCreate(&firstElement,(uint32_t)&taskOneTcb);
	listElementCreate(&secondElement,(uint32_t)&taskTwoTcb);
	listElementCreate(&mainElement,(uint32_t)mainTcb);
	listAddTail(&linkedList,&firstElement);
	listAddTail(&linkedList,&secondElement);


	runningTcb = &mainTcb ;
}
