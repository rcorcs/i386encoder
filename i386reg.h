/****************************************************/
/* File: i386reg.h                                  */
/* ROCHA, Rodrigo Caetano de Oliveira			    */
/* rcor                                             */
/****************************************************/

#ifndef _I386REG_H_
#define _I386REG_H_

// 8-bit registers
#define REG_AL		0x0
#define REG_CL		0x1
#define REG_DL		0x2
#define REG_BL		0x3
#define REG_AH		0x4
#define REG_CH		0x5
#define REG_DH		0x6
#define REG_BH		0x7

// 16-bit registers
#define REG_AX		0x0
#define REG_CX		0x1
#define REG_DX		0x2
#define REG_BX		0x3
#define REG_SP		0x4
#define REG_BP		0x5
#define REG_SI		0x6
#define REG_DI		0x7

// 32-bit registers
#define REG_EAX		0x0
#define REG_ECX		0x1
#define REG_EDX		0x2
#define REG_EBX		0x3
#define REG_ESP		0x4
#define REG_EBP		0x5
#define REG_ESI		0x6
#define REG_EDI		0x7

//sreg
#define REG_ES		0x0
#define REG_CS		0x1
#define REG_SS		0x2
#define REG_DS		0x3
#define REG_FS		0x4
#define REG_GS		0x5

//Special-Purpose Register (eee)
//Control Registers
#define REG_CR0		0x0
#define REG_CR2		0x2
#define REG_CR3		0x3
#define REG_CR4		0x4

//Special-Purpose Register (eee)
//Debug Registers
#define REG_DR0		0x0
#define REG_DR1		0x1
#define REG_DR2		0x2
#define REG_DR3		0x3
#define REG_DR6		0x6
#define REG_DR7		0x7

#endif
