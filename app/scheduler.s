  .syntax unified
  .cpu cortex-m4
  .fpu softvfp
  .thumb

  .global SysTick_Handler
  .extern mainTcb
  .extern taskOneTcb
  .extern taskTwoTcb
  .extern runningTcb
  .extern linkedList

.equ TCB_NAME,0
.equ TCB_SP,4

/*Task switching mechanism*/



// 1) Push the rest of register
// 2) Let R0 points to mainTCB (load mainTcb)
// 3) Store the current SP into mainTcb.sp (through R0) //str r1[r0,#TCB_SP] or ldr r1,[r0,#8]
// 4) Let R0 points to taskOneTcb (load taskOneTcb)
// 5) Load taskOneTcb(throught R0) into current SP
// 6) Pop all register
// 7) return from interrupt
	.align 8
	.type SysTick_Handler, %function
SysTick_Handler:

	push {r4-r11} //Push the rest of register

	ldr r4, =runningTcb //Load address of runningTcb into R4
	ldr r4,	[r4]		//Load content in runningTcb into R4

	ldr r1, =#0	//Clear R1
	add r1, sp //Store current SP into R1

	str r1, [r4,#TCB_SP] //Store SP into runningTcb.sp

	push {lr} //push LR

	ldr r0, =linkedList	//pass in linkedList
	bl listRemoveHead	//remove head from linked list
	pop {lr}			//pop LR

	ldr r5,[r0]		// R5 = listRemoveHead()
	ldr sp, [r5,#TCB_SP]	//load R5.SP into SP

	ldr r3, =runningTcb // Load runningTcb into R3
	ldr r3,	[r3]		//Load content in runningTcb into R3
	mov r3,r5		//Let runningTcb = r5

	push {lr} //push LR
	mov r1,r4
	ldr r0, =linkedList

	bl listAddTail

	pop {lr}
	pop {r4-r11}
 	bx	lr


// 1) Push the rest of register
// 2) Load runningTcb into R4
// 3) Store the current SP into runningTcb.sp
// 3a) Push LR
// 4) R5 = listRemoveHead()
// 5) Load R5.sp into SP
// 6) Let runnningTcb = R5
// 7) listAddTail(R4)
// 7a) Pop LR
// 8) Pop all pushed register
// 9) return from interrupt
