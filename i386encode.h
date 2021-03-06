/****************************************************/
/* File: i386encoder.cpp                            */
/* ROCHA, Rodrigo Caetano de Oliveira			    */
/* rcor                                             */
/****************************************************/
#ifndef _I386ENCODE_H_
#define _I386ENCODE_H_

#include <fstream>
using std::ofstream;

//Encoding of Conditional Test (tttn) Field
#define TTTN_O		0x0		//Overflow
#define TTTN_NO		0x1		//No Overflow
#define TTTN_B		0x2		//Below = TTTN_NAE
#define TTTN_NAE	0x2		//Not Above or Equal  = TTTN_B
#define TTTN_NB		0x3		//Not Below = TTTN_AE
#define TTTN_AE		0x3		//Above or Equal  = TTTN_NB
#define TTTN_E		0x4		//Equal
#define TTTN_Z		0x4		//Zero
#define TTTN_NE		0x5		//Not Equal
#define TTTN_NZ		0x5		//Not Zero
#define TTTN_BE		0x6		//Below or Equal
#define TTTN_NA		0x6		//Not Above
#define TTTN_NBE	0x7		//Not Below or Equal
#define TTTN_A		0x7		//Above
#define TTTN_S		0x8		//Sign
#define TTTN_NS		0x9		//Not Sign
#define TTTN_P		0xA		//Parity
#define TTTN_PE		0xA		//Parity Even
#define TTTN_NP		0xB		//Not Parity
#define TTTN_PO		0xB		//Parity Odd
#define TTTN_L		0xC		//Less than
#define TTTN_NGE	0xC		//Not Greater than or Equal to
#define TTTN_NL		0xD		//Not Less than
#define TTTN_GE		0xD		//Greater than or Equal to
#define TTTN_LE		0xE		//Less than or Equal to
#define TTTN_NG		0xE		//Not Greater than
#define TTTN_NLE	0xF		//Not Less than or Equal to
#define TTTN_G		0xF		//Greater than

///Prefix Bytes
//address size 0110 0111
#define PB_ADDRESS_SIZE         0x67

//LOCK 1111 0000
#define PB_LOCK                 0xF0

//operand size 0110 0110
#define PB_OPERAND_SIZE         0x66

//CS segment override 0010 1110
#define PB_CS_SEGMENT_OVERRIDE 0x2E

//DS segment override 0011 1110
#define PB_DS_SEGMENT_OVERRIDE 0x3E

//ES segment override 0010 0110
#define PB_ES_SEGMENT_OVERRIDE 0x26

//FS segment override 0110 0100
#define PB_FS_SEGMENT_OVERRIDE 0x64

//GS segment override 0110 0101
#define PB_GS_SEGMENT_OVERRIDE 0x65

//SS segment override 0011 0110
#define PB_SS_SEGMENT_OVERRIDE 0x36

/**********************************
* STRUCTURES
**********************************/

typedef struct {
	char p;  		//present in the instruction
	char mod;
	char reg;
	char rm;
} ModRM;

typedef struct {
	char p;			//present in the instruction
	char scale;
	char index;
	char base;
} SIB;


typedef struct {
	char p;			//present in the instruction
	char w;
} Wbit;

//Sign-Extend (s) Bit
typedef struct {
	char p;			//present in the instruction
	char s;
} Sbit;

//Direction (d) Bit
typedef struct {
	char p;			//present in the instruction
	char d;
} Dbit;

//Displacement Byte
typedef struct {
	char p;			//present in the instruction
	int disp;
	int n_byte;
} Displacement;

//Immediate Byte
typedef struct {
	char p;			//present in the instruction
	int imm;
	int n_byte;
} Immediate;

typedef struct {
	char p;
	char op;
}Opcode;

typedef struct {
	char p;
	char tttn;
}Condition;

typedef struct {
	Opcode			op1;
	Opcode			op2;
	Wbit			wbit;
	Sbit			sbit;
	Dbit			dbit;
	ModRM			modrm;
	SIB				sib;
	Displacement	dispb;
	Immediate 		immb;
	Condition       cond;
} IEncode;

#define _IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn) \
    IEncode ie;             \
	ie.op1.p = _op1;        \
	ie.op2.p = _op2;        \
	ie.wbit.p = _wbit;      \
	ie.sbit.p = _sbit;      \
	ie.modrm.p = _modrm;    \
	ie.sib.p = _sib;        \
	ie.dispb.p = _dispb;    \
	ie.immb.p = _immb;      \
	ie.dbit.p = _dbit;      \
	ie.cond.p = _tttn;

#define _SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm) \
    ie.op1.op = _op1;       \
    ie.op2.op = _op2;       \
	ie.wbit.w = _wbit;      \
	ie.modrm.mod = _mod;    \
	ie.modrm.reg = _reg;    \
	ie.modrm.rm = _rm;

#define _SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte) \
    ie.op1.op = _op1;               \
    ie.op2.op = _op2;               \
	ie.wbit.w = _wbit;              \
	ie.sbit.s = _sbit;              \
	ie.modrm.mod = _mod;            \
	ie.modrm.reg = _reg;            \
	ie.modrm.rm = _rm;              \
	ie.dispb.disp = _disp;          \
	ie.dispb.n_byte = _n_disp_byte; \
	ie.immb.imm = _imm;             \
	ie.immb.n_byte = _n_imm_byte;   \

#define _SET_TTTN(_tttn)    ie.cond.tttn = _tttn;

#define _END_IENCODE    return(ie);

/***********************************************************************/
/****                     INSTRUCTION ENCODINGS                    *****/
/***********************************************************************/


///AAA : ASCII Adjust after Addition = 0011 0111
IEncode aaa();

///AAD : ASCII Adjust AX before Division = 1101 0101 0000 1010
IEncode aad();

///AAD : ASCII Adjust AX before Division = 1101 0100 0000 1010
IEncode aam();

///AAS : ASCII Adjust AL after Subtraction = 0011 1111
IEncode aas();

/****************************
* ADC : ADD with Carry
****************************/
//register1 to register2 = 0001 000w : 11 reg1 reg2
IEncode adc_r1_r2(char w, char reg1, char reg2);

//register2 to register1 = 0001 001w : 11 reg1 reg2
IEncode adc_r2_r1(char w, char reg1, char reg2);

//memory to register = 0001 001w : mod reg r/m
IEncode adc_m_r(char w, char mod, char reg, char rm);

//register to memory = 0001 000w : mod reg r/m
IEncode adc_r_m(char w, char mod, char reg, char rm);

//immediate to register = 1000 00sw : 11 010 reg : immediate data
IEncode adc_i_r(char s, char w, char reg, int imm, int n_byte=sizeof(int));

//immediate to AL, AX, or EAX = 0001 010w : immediate data
IEncode adc_i_ra(char w, int imm, int n_byte=sizeof(int));

//immediate to memory = 1000 00sw : mod 010 r/m : immediate data
IEncode adc_i_m(char s, char w, char mod, char rm, int imm, int n_byte=sizeof(int));

/****************************
* ADD : Add
****************************/
//register1 to register2 = 0000 000w : 11 reg1 reg2
IEncode add_r1_r2(char w, char reg1, char reg2);

//register2 to register1 = 0000 001w : 11 reg1 reg2
IEncode add_r2_r1(char w, char reg1, char reg2);

//memory to register = 0000 001w : mod reg r/m
IEncode add_m_r(char w, char mod, char reg, char rm);

//register to memory = 0000 000w : mod reg r/m
IEncode add_r_m(char w, char mod, char reg, char rm);

//immediate to register = 1000 00sw : 11 000 reg : immediate data
IEncode add_i_r(char s, char w, char reg, int imm, int n_byte=sizeof(int));

//immediate to AL, AX, or EAX = 0000 010w : immediate data
IEncode add_i_ra(char w, int imm, int n_byte=sizeof(int));

//immediate to memory = 1000 00sw : mod 000 r/m : immediate data
IEncode add_i_m(char s, char w, char mod, char rm, int imm, int n_byte=sizeof(int));

/**********************************
* AND : Logical AND
**********************************/
//register1 to register2 = 0010 000w : 11 reg1 reg2
IEncode and_r1_r2(char w, char reg1, char reg2);

//register2 to register1 = 0010 001w : 11 reg1 reg2
IEncode and_r2_r1(char w, char reg1, char reg2);

//memory to register = 0010 001w : mod reg r/m
IEncode and_m_r(char w, char mod, char reg, char rm);

//register to memory = 0010 000w : mod reg r/m
IEncode and_r_m(char w, char mod, char reg, char rm);

//I AM NOT SURE IF THIS INTRUCTION IS RIGHT
//immediate to register = 1000 00sw : 11 100 reg : immediate data
IEncode and_i_r(char s, char w, char reg, int imm, int n_byte=sizeof(int));

//immediate to AL, AX, or EAX = 0010 010w : immediate data
IEncode and_i_ra(char w, int imm, int n_byte=sizeof(int));

//immediate to memory = 1000 00sw : mod 100 r/m : immediate data
IEncode and_i_m(char s, char w, char mod, char rm, int imm, int n_byte=sizeof(int));

/***************************************
* ARPL : Adjust RPL Field of Selector
***************************************/
//from register = 0110 0011 : 11 reg1 reg2
IEncode arpl_r(char reg1, char reg2);

//from memory = 0110 0011 : mod reg r/m
IEncode arpl_m(char mod, char reg, char rm);

///BOUND : Check Array Against Bounds = 0110 0010 : mod reg r/m
IEncode bound(char mod, char reg, char rm);

/***************************************
* BSF : Bit Scan Forward
***************************************/
//register1, register2 = 0000 1111 : 1011 1100 : 11 reg2 reg1
IEncode bsf_r_r(char reg1, char reg2);

//memory, register = 0000 1111 : 1011 1100 : mod reg r/m
IEncode bsf_m_r(char mod, char reg, char rm);

/***************************************
* BSR : Bit Scan Reverse
***************************************/
//register1, register2 = 0000 1111 : 1011 1101 : 11 reg2 reg1
IEncode bsr_r_r(char reg1, char reg2);

//memory, register = 0000 1111 : 1011 1101 : mod reg r/m
IEncode bsr_m_r(char mod, char reg, char rm);

///BSWAP : Byte Swap = 0000 1111 : 11 001 reg
IEncode bswap(char reg);

/********************************************
* BT : Bit Test
********************************************/
//register, immediate = 0000 1111 : 1011 1010 : 11 100 reg: imm8 data
IEncode bt_r_i(char reg, int imm8);

//memory, immediate = 0000 1111 : 1011 1010 : mod 100 r/m : imm8 data
IEncode bt_m_i(char mod, char rm, int imm8);

//register1, register2 = 0000 1111 : 1010 0011 : 11 reg2 reg1
IEncode bt_r_r(char reg1, char reg2);

//memory, reg = 0000 1111 : 1010 0011 : mod reg r/m
IEncode bt_m_r(char mod, char reg, char rm);

/********************************************
* BTC : Bit Test and Complement
********************************************/
//register, immediate = 0000 1111 : 1011 1010 : 11 111 reg: imm8 data
IEncode btc_r_i(char reg, int imm8);

//memory, immediate = 0000 1111 : 1011 1010 : mod 111 r/m : imm8 data
IEncode btc_m_i(char mod, char rm, int imm8);

//register1, register2 = 0000 1111 : 1011 1011 : 11 reg2 reg1
IEncode btc_r_r(char reg1, char reg2);

//memory, reg = 0000 1111 : 1011 1011 : mod reg r/m
IEncode btc_m_r(char mod, char reg, char rm);

/********************************************
* BTR : Bit Test and Reset
********************************************/
//register, immediate = 0000 1111 : 1011 1010 : 11 110 reg: imm8 data
IEncode btr_r_i(char reg, int imm8);

//memory, immediate = 0000 1111 : 1011 1010 : mod 110 r/m : imm8 data
IEncode btr_m_i(char mod, char rm, int imm8);

//register1, register2 = 0000 1111 : 1011 0011 : 11 reg2 reg1
IEncode btr_r_r(char reg1, char reg2);

//memory, reg = 0000 1111 : 1011 0011 : mod reg r/m
IEncode btr_m_r(char mod, char reg, char rm);

/********************************************
* BTS : Bit Test and Set
********************************************/
//register, immediate = 0000 1111 : 1011 1010 : 11 101 reg: imm8 data
IEncode bts_r_i(char reg, int imm8);

//memory, immediate = 0000 1111 : 1011 1010 : mod 101 r/m : imm8 data
IEncode bts_m_i(char mod, char rm, int imm8);

//register1, register2 = 0000 1111 : 1010 1011 : 11 reg2 reg1
IEncode bts_r_r(char reg1, char reg2);

//memory, reg = 0000 1111 : 1010 1011 : mod reg r/m
IEncode bts_m_r(char mod, char reg, char rm);

/********************************************
* CALL : Call Procedure (in same segment)
********************************************/
//direct = 1110 1000 : full displacement
IEncode call_ss(int disp);

//register indirect = 1111 1111 : 11 010 reg
IEncode call_ss_r(char reg);

//memory indirect = 1111 1111 : mod 010 rm
IEncode call_ss_m(char mod, char rm);

/********************************************
* CALL : Call Procedure (in other segment)
********************************************/
//direct = 1001 1000 : unsigned full offset, selector
IEncode call_os(int disp);

//indirect = 1111 1111 : mod 011 rm
IEncode call_os_m(char mod, char rm);


///CBW - Convert Byte to Word = 1001 1000
IEncode cbw();

///CDQ : Convert Doubleword to Qword = 1001 1001
IEncode cdq();

///CLC : Clear Carry Flag = 1111 1000
IEncode clc();

///CLD : Clear Direction Flag = 1111 1100
IEncode cld();

///CLI : Clear Interrupt Flag = 1111 1010
IEncode cli();

///CLTS : Clear Task-Switched Flag in CR0 = 0000 1111 : 0000 0110
IEncode clts();

///CMC : Complement Carry Flag = 1111 0101
IEncode cmc();

/************************************************
* CMOVcc : Conditional Move
************************************************/
//register2 to register1 = 0000 1111: 0100 tttn : 11 reg1 reg2
IEncode cmov_r_r(char tttn, char reg1, char reg2);

//memory to register = 0000 1111: 0100 tttn : mod mem r/m
IEncode cmov_m_r(char tttn, char mod, char mem, char rm);

/************************************************
* CMP : Compare Two Operands
************************************************/
//register1 with register2 = 0011 100w : 11 reg1 reg2
IEncode cmp_r_r(char w, char reg1, char reg2);

//register1 with register2 = 0011 100w : 11 reg1 reg2
IEncode cmp_r1_r2(char w, char reg1, char reg2);

//register2 with register1 = 0011 101w : 11 reg1 reg2
IEncode cmp_r2_r1(char w, char reg1, char reg2);

//memory with register = 0011 100w : mod reg r/m
IEncode cmp_m_r(char w, char mod, char reg, char rm);

//register with memory 0011 101w : mod reg r/m
IEncode cmp_r_m(char w, char mod, char reg, char rm);

//immediate with register = 1000 00sw : 11 111 reg : immediate data
IEncode cmp_i_r(char s, char w, char reg, int imm, int n_byte);

//immediate with AL, AX, or EAX = 0011 110w : immediate data
IEncode cmp_i_ra(char w, int imm, int n_byte);

//immediate with memory = 1000 00sw : mod 111 r/m (: immediate data)
IEncode cmp_i_m(char s, char w, char mod, char rm, int imm, int n_byte);

///CMPS/CMPSB/CMPSW/CMPSD : Compare String Operands = 1010 011w
IEncode cmps(char w);

/*******************************************************
* CMPXCHG : Compare and Exchange
********************************************************/
//register1, register2 = 0000 1111 : 1011 000w : 11 reg2 reg1
IEncode cmpxchg(char w, char reg1, char reg2);

//memory, register = 0000 1111 : 1011 000w : mod reg r/m
IEncode cmpxchg(char w, char mod, char reg, char rm);

/*********************************************************
* CMPXCHG8B : Compare and Exchange 8 Bytes
*********************************************************/
//memory, register = 0000 1111 : 1100 0111 : mod reg r/m
IEncode cmpxchg8b(char mod, char reg, char rm);

///CPUID : CPU Identification = 0000 1111 : 1010 0010
IEncode cpuid();

///CWD : Convert Word to Doubleword = 1001 1001
IEncode cwd();

///CWDE : Convert Word to Doubleword = 1001 1000
IEncode cwde();

///DAA : Decimal Adjust AL after Addition = 0010 0111
IEncode daa();

///DAS : Decimal Adjust AL after Subtraction = 0010 1111
IEncode das();

/****************************************
* DEC : Decrement by 1
****************************************/
//register = 1111 111w : 11 001 reg
IEncode dec_r(char w, char reg);

//register (alternate encoding) = 01 001 reg
IEncode dec_r(char reg);

//memory = 1111 111w : mod 001 r/m
IEncode dec_m(char w, char mod, char rm);

/********************************************************
* DIV : Unsigned Divide
********************************************************/
//AL, AX, or EAX by register = 1111 011w : 11 110 reg
IEncode div_ra_r(char w, char reg);

//AL, AX, or EAX by memory 1111 011w : mod 110 r/m
IEncode div_ra_m(char w, char mod, char rm);

///ENTER : Make Stack Frame for High Level Procedure = 1100 1000 : 16-bit displacement : 8-bit level (L)
IEncode enter(int disp16, char level);

///HLT : Halt = 1111 0100
IEncode hlt(char w, char mod, char rm);

/********************************************************
* IDIV : Signed Divide
********************************************************/
//AL, AX, or EAX by register = 1111 011w : 11 111 reg
IEncode idiv_ra_r(char w, char reg);

//AL, AX, or EAX by memory = 1111 011w : mod 111 r/m
IEncode idiv_ra_m(char w, char mod, char rm);

/***********************************************************
* IMUL : Signed Multiply
***********************************************************/
//AL, AX, or EAX with register = 1111 011w : 11 101 reg
IEncode imul_ra_r(char w, char reg);

//AL, AX, or EAX with memory = 1111 011w : mod 101 reg
IEncode imul_ra_m(char w, char mod, char reg);

//register1 with register2 = 0000 1111 : 1010 1111 : 11 : reg1 reg2
IEncode imul_r_r(char reg1, char reg2);

//register with memory = 0000 1111 : 1010 1111 : mod reg r/m
IEncode imul_r_m(char mod, char reg, char rm);

//register1 with immediate to register2 = 0110 10s1 : 11 reg1 reg2 : immediate data
IEncode imul_r_i_r(char s, char reg1, char rm, int imm, int n_byte);

//memory with immediate to register = 0110 10s1 : mod reg r/m : immediate data
IEncode imul_m_i_r(char s, char mod, char reg, char rm, int imm, int n_byte);

/************************************************************************
* IN : Input From Port
************************************************************************/
//fixed port = 1110 010w : port number
IEncode in_fp(char w, char port);

//variable port = 1110 110w
IEncode in_vp(char w);

/************************************************************************
* INC : Increment by 1
************************************************************************/
//reg = 1111 111w : 11 000 reg
IEncode inc_r(char w, char reg);

//reg (alternate encoding) = 0100 0 reg
IEncode inc_r(char reg);

//memory = 1111 111w : mod 000 r/m
IEncode inc_m(char w, char mod, char rm);

///INS : Input from DX Port = 0110 110w
IEncode ins(char w);

///INT n : Interrupt Type n = 1100 1101 : type
IEncode int_n(char type);

///INT : Single-Step Interrupt 3 = 1100 1100
IEncode int_ss();

///INTO : Interrupt 4 on Overflow = 1100 1110
IEncode into();

///INVD : Invalidate Cache = 0000 1111 : 0000 1000
IEncode invd();

///INVLPG : Invalidate TLB Entry = 0000 1111 : 0000 0001
IEncode invlpg();

///IRET/IRETD : Interrupt Return = 1100 1111
IEncode iret();

/********************************************************
* Jcc : Jump if Condition is Met
********************************************************/
//8-bit displacement 0111 tttn : 8-bit displacement
IEncode jc_8b(char tttn, char disp8);

//full displacement 0000 1111 : 1000 tttn : full displacement
IEncode jc(char tttn, int disp);

/********************************************************
* JMP : Unconditional Jump (to same segment)
********************************************************/
//short = 1110 1011 : 8-bit displacement
IEncode jmp_ss_s(char disp8);

//direct = 1110 1001 : full displacement
IEncode jmp_ss_d(int disp);

//register indirect = 1111 1111 : 11 100 reg
IEncode jmp_ss_r(char reg);

//memory indirect = 1111 1111 : mod 100 r/m
IEncode jmp_ss_m(char mod, char rm);

/********************************************************
* JMP : Unconditional Jump (to other segment)
********************************************************/
//direct intersegment = 1110 1010 : unsigned full offset, selector
//IEncode jmp_os_d(int offset, c);

//indirect intersegment = 1111 1111 : mod 101 r/m
IEncode jmp_os_i(char mod, char rm);

///LAHF : Load Flags into AHRegister = 1001 1111
IEncode lahf();

/********************************************************
* LAR : Load Access Rights Byte
********************************************************/
//from register 0000 1111 : 0000 0010 : 11 reg1 reg2
IEncode lar_r(char reg1, char reg2);

//from memory 0000 1111 : 0000 0010 : mod reg r/m
IEncode lar_r(char mod, char reg, char rm);

///LDS : Load Pointer to DS = 1100 0101 : mod reg r/m
IEncode lds(char mod, char reg, char rm);

///LEA : Load Effective Address = 1000 1101 : mod reg r/m
IEncode lea(char mod, char reg, char rm);

///LEAVE : High Level Procedure Exit = 1100 1001
IEncode leave();

///LES : Load Pointer to ES = 1100 0100 : mod reg r/m
IEncode les(char mod, char reg, char rm);

///LFS : Load Pointer to FS = 0000 1111 : 1011 0100 : mod reg r/m
IEncode lfs(char mod, char reg, char rm);

///LGDT : Load Global Descriptor Table Register = 0000 1111 : 0000 0001 : mod 010 r/m
IEncode lgdt(char mod, char rm);

///LGS : Load Pointer to GS = 0000 1111 : 1011 0101 : mod reg r/m
IEncode lgs(char mod, char reg, char rm);

/**************************************************************
* LLDT : Load Local Descriptor Table Register
**************************************************************/
//LDTR from register 0000 1111 : 0000 0000 : 11 010 reg
IEncode lldt_r(char reg);

//LDTR from memory 0000 1111 : 0000 0000 : mod 010 r/m
IEncode lldt_m(char mod, char rm);

/**************************************************************
* LMSW : Load Machine Status Word
**************************************************************/
//from register 0000 1111 : 0000 0001 : 11 110 reg
IEncode lmsw_r(char reg);

//from memory 0000 1111 : 0000 0001 : mod 110 r/m
IEncode lmsw_m(char mod, char rm);

///LOCK : Assert LOCK# Signal Prefix 1111 0000
IEncode lock();

///LODS/LODSB/LODSW/LODSD : Load String Operand 1010 110w
IEncode lods(char w);

///LOOP : Loop Count 1110 0010 : 8-bit displacement
IEncode loop(char disp8);

///LOOPZ/LOOPE : Loop Count while Zero/Equal 1110 0001 : 8-bit displacement
IEncode loopz(char disp8);

///LOOPNZ/LOOPNE : Loop Count while not Zero/Equal 1110 0000 : 8-bit displacement
IEncode loopnz(char disp8);

/***********************************************************
* LSL : Load Segment Limit
***********************************************************/
//from register 0000 1111 : 0000 0011 : 11 reg1 reg2
IEncode lsl_r(char reg1, char reg2);

//from memory 0000 1111 : 0000 0011 : mod reg r/m
IEncode lsl_m(char mod, char reg, char rm);

/********************************************************
* LTR : Load Task Register
********************************************************/
//from register 0000 1111 : 0000 0000 : 11 011 reg
IEncode ltr_r(char reg);

//from memory 0000 1111 : 0000 0000 : mod 011 r/m
IEncode lsl_m(char mod, char rm);

/********************************************************
* MOV : Move Data
********************************************************/
//register1 to register2 1000 100w : 11 reg1 reg2
IEncode mov_r1_r2(char w, char reg1, char reg2);

//register2 to register1 1000 101w : 11 reg1 reg2
IEncode mov_r2_r1(char w, char reg1, char reg2);

//memory to reg 1000 101w : mod reg r/m
IEncode mov_m_r(char w, char mod, char reg, char rm);

//reg to memory 1000 100w : mod reg r/m
IEncode mov_r_m(char w, char mod, char reg, char rm);

//immediate to register 1100 011w : 11 000 reg : immediate data
IEncode mov_i_r(char w, char reg, int imm, int n_byte);

//immediate to register (alternate encoding) 1011 w reg : immediate data
IEncode mov_i_r_alt(char w, char reg, int imm, int n_byte);

//immediate to memory 1100 011w : mod 000 r/m : immediate data
IEncode mov_i_m(char w, char mod, char rm, int imm, int n_byte);

//memory to AL, AX, or EAX 1010 000w : full displacement
IEncode mov_m_ra(char w, int disp);

//AL, AX, or EAX to memory 1010 001w : full displacement
IEncode mov_ra_m(char w, int disp);


/********************************************************
* MOV : Move to/from Control Registers
********************************************************/
//CR0 from register 0000 1111 : 0010 0010 : 11 000 reg
IEncode mov_r_cr0(char reg);
//CR2 from register 0000 1111 : 0010 0010 : 11 010reg
IEncode mov_r_cr2(char reg);
//CR3 from register 0000 1111 : 0010 0010 : 11 011 reg
IEncode mov_r_cr3(char reg);
//CR4 from register 0000 1111 : 0010 0010 : 11 100 reg
IEncode mov_r_cr4(char reg);
//register from CR0-CR4 0000 1111 : 0010 0000 : 11 eee reg
IEncode mov_cr_r(char eee, char reg);

/***************************************************************
* MOV : Move to/from Debug Registers
***************************************************************/
//DR? from register 0000 1111 : 0010 0011 : 11 eee reg
IEncode mov_r_dr(char eee, char reg);

//register from DR? 0000 1111 : 0010 0001 : 11 eee reg
IEncode mov_dr_r(char eee, char reg);

/*******************************************************************
* MOV : Move to/from Segment Registers
*******************************************************************/
//register to segment register 1000 1110 : 11 sreg3 reg
//register to SS 1000 1110 : 11 sreg3 reg
IEncode mov_r_sr(char sreg3, char reg);

//memory to segment reg 1000 1110 : mod sreg3 r/m
//memory to SS 1000 1110 : mod sreg3 r/m
IEncode mov_m_sr(char mod, char sreg3, char rm);

//segment register to register 1000 1100 : 11 sreg3 reg
IEncode mov_sr_r(char sreg3, char reg);

//segment register to memory 1000 1100 : mod sreg3 r/m
IEncode mov_sr_m(char mod, char sreg3, char rm);


///MOVS/MOVSB/MOVSW/MOVSD : Move Data from String to String 1010 010w
IEncode movs(char w);

///MOVSX : Move with Sign-Extend
//register2 to register1 0000 1111 : 1011 111w : 11 reg1 reg2
IEncode movsx_r2_r1(char w, char reg1, char reg2);

//memory to reg 0000 1111 : 1011 111w : mod reg r/m
IEncode movsx_m_r(char w, char mod, char reg, char rm);

///MOVZX : Move with Zero-Extend
//register2 to register1 0000 1111 : 1011 011w : 11 reg1 reg2
IEncode movzx_r2_r1(char w, char reg1, char reg2);

//memory to register 0000 1111 : 1011 011w : mod reg r/m
IEncode movzx_m_r(char w, char mod, char reg, char rm);

///MUL : Unsigned Multiply
//AL, AX, or EAX with register 1111 011w : 11 100 reg
IEncode mul_ra_r(char w, char reg);

//AL, AX, or EAX with memory 1111 011w : mod 100 reg
IEncode mul_ra_m(char w, char mod, char reg);

///NEG : Two's Complement Negation
//register 1111 011w : 11 011 reg
IEncode neg_r(char w, char reg);

//memory 1111 011w : mod 011 r/m
IEncode neg_m(char w, char mod, char rm);

///NOP : No Operation 1001 0000
IEncode nop();

///NOT : One's Complement Negation
//register 1111 011w : 11 010 reg
IEncode not_r(char w, char reg);

//memory 1111 011w : mod 010 r/m
IEncode not_m(char w, char mod, char rm);

///OR : Logical Inclusive OR
//register1 to register2 0000 100w : 11 reg1 reg2
IEncode or_r1_r2(char w, char reg1, char reg2);

//register2 to register1 0000 101w : 11 reg1 reg2
IEncode or_r2_r1(char w, char reg1, char reg2);

//memory to register 0000 101w : mod reg r/m
IEncode or_m_r(char w, char mod, char reg, char rm);

//register to memory 0000 100w : mod reg r/m
IEncode or_r_m(char w, char mod, char reg, char rm);

//immediate to register 1000 00sw : 11 001 reg : immediate data
IEncode or_i_r(char s, char w, char reg, int imm, int n_byte);

//immediate to AL, AX, or EAX 0000 110w : immediate data
IEncode or_i_ra(char w, int imm, int n_byte);

//immediate to memory 1000 00sw : mod 001 r/m : immediate data
IEncode or_i_r(char s, char w, char mod, char rm, int imm, int n_byte);

///OUT : Output to Port
//fixed port 1110 011w : port number (16-bit)
IEncode out_f(char w, int disp, int n_byte); //port number 16 bits

//variable port 1110 111w
IEncode out_v(char w);

///OUTS : Output to DX Port 0110 111w
IEncode outs_dx(char w);

///POP : Pop a Word from the Stack
//register 1000 1111 : 11 000 reg
IEncode pop_r(char reg);
//register (alternate encoding) 0101 1 reg
IEncode pop_r_alt(char reg);
//memory 1000 1111 : mod 000 r/m
IEncode pop_m(char mod, char rm);

///POP : Pop a Segment Register from the Stack
//segment register CS, DS, ES, SS 000 sreg2 111
IEncode pop_sreg2(char sreg2);

//segment register FS, GS 0000 1111: 10 sreg3 001
IEncode pop_sreg3(char sreg3);

///POPA/POPAD : Pop All General Registers 0110 0001
IEncode popa();

///POPF/POPFD : Pop Stack into FLAGS or EFLAGS Register 1001 1101
IEncode popf();

///PUSH : Push Operand onto the Stack
//register 1111 1111 : 11 110 reg
IEncode push_r(char reg);

//register (alternate encoding) 0101 0 reg
IEncode push_r_alt(char reg);

//memory 1111 1111 : mod 110 r/m
IEncode push_m(char mod, char rm);

//immediate 0110 10s0 : immediate data
IEncode push_i(char s, int imm, int n_byte);

///PUSH : Push Segment Register onto the Stack
//segment register CS,DS,ES,SS = 000 sreg2 110
IEncode push_sreg2(char sreg2);
//segment register FS,GS = 0000 1111: 10 sreg3 000
IEncode push_sreg3(char sreg3);

///PUSHA/PUSHAD : Push All General Registers 0110 0000
IEncode pusha();

///PUSHF/PUSHFD : Push Flags Register onto the Stack 1001 1100
IEncode pushf();

///RCL : Rotate thru Carry Left
//register by 1 = 1101 000w : 11 010 reg
IEncode rcl_r_1(char w, char reg);
//memory by 1 = 1101 000w : mod 010 r/m
IEncode rcl_m_1(char w, char mod, char rm);
//register by CL = 1101 001w : 11 010 reg
IEncode rcl_r_cl(char w, char reg);
//memory by CL = 1101 001w : mod 010 r/m
IEncode rcl_m_cl(char w, char mod, char rm);
//register by immediate count = 1100 000w : 11 010 reg : imm8 data
IEncode rcl_r_i(char w, char reg, char imm8);
//memory by immediate count = 1100 000w : mod 010 r/m : imm8 data
IEncode rcl_m_i(char w, char mod, char rm, char imm8);


///RCR : Rotate thru Carry Right
//register by 1 = 1101 000w : 11 011 reg
IEncode rcr_r_1(char w, char reg);
//memory by 1 = 1101 000w : mod 011 r/m
IEncode rcr_m_1(char w, char mod, char rm);
//register by CL = 1101 001w : 11 011 reg
IEncode rcr_r_cl(char w, char reg);
//memory by CL = 1101 001w : mod 011 r/m
IEncode rcr_m_cl(char w, char mod, char rm);
//register by immediate count = 1100 000w : 11 011 reg : imm8 data
IEncode rcr_r_i(char w, char reg, char imm8);
//memory by immediate count = 1100 000w : mod 011 r/m : imm8 data
IEncode rcr_m_i(char w, char mod, char rm, char imm8);

///RDMSR : Read from Model-Specific Register 0000 1111 : 0011 0010
IEncode rdmsr();
///RDPMC : Read Performance Monitoring Counters 0000 1111 : 0011 0011
IEncode rdpmc();
///RDTSC : Read Time-Stamp Counter 0000 1111 : 0011 0001
IEncode rdtsc();
///REP INS : Input String 1111 0011 : 0110 110w
IEncode rep_ins(char w);
///REP LODS : Load String 1111 0011 : 1010 110w
IEncode rep_lods(char w);
///REP MOVS : Move String 1111 0011 : 1010 010w
IEncode rep_movs(char w);
///REP OUTS : Output String 1111 0011 : 0110 111w
IEncode rep_outs(char w);
///REP STOS : Store String 1111 0011 : 1010 101w
IEncode rep_stos(char w);
///REPE CMPS : Compare String 1111 0011 : 1010 011w
IEncode repe_cmps(char w);
///REPE SCAS : Scan String 1111 0011 : 1010 111w
IEncode repe_scas(char w);
///REPNE CMPS : Compare String 1111 0010 : 1010 011w
IEncode repne_cmps(char w);
///REPNE SCAS : Scan String 1111 0010 : 1010 111w
IEncode repne_scas(char w);

///RET : Return from Procedure (to same segment)
//no argument 1100 0011
IEncode ret_ss();
//adding immediate to SP 1100 0010 : 16-bit displacement
IEncode ret_ss(int disp16);

///RET : Return from Procedure (to other segment)
//intersegment 1100 1011
IEncode ret_os();
//adding immediate to SP 1100 1010 : 16-bit displacement
IEncode ret_os(int disp16);

///ROL : Rotate Left
//register by 1 = 1101 000w : 11 000 reg
IEncode rol_r_1(char w, char reg);
//memory by 1 = 1101 000w : mod 000 r/m
IEncode rol_m_1(char w, char mod, char rm);
//register by CL = 1101 001w : 11 000 reg
IEncode rol_r_cl(char w, char reg);
//memory by CL = 1101 001w : mod 000 r/m
IEncode rol_m_cl(char w, char mod, char rm);
//register by immediate count = 1100 000w : 11 000 reg : imm8 data
IEncode rol_r_i(char w, char reg, char imm8);
//memory by immediate count = 1100 000w : mod 000 r/m : imm8 data
IEncode rol_m_i(char w, char mod, char rm, char imm8);

///ROR : Rotate Right
//register by 1 = 1101 000w : 11 001 reg
IEncode ror_r_1(char w, char reg);
//memory by 1 = 1101 000w : mod 001 r/m
IEncode ror_m_1(char w, char mod, char rm);
//register by CL = 1101 001w : 11 001 reg
IEncode ror_r_cl(char w, char reg);
//memory by CL = 1101 001w : mod 001 r/m
IEncode ror_m_cl(char w, char mod, char rm);
//register by immediate count = 1100 000w : 11 001 reg : imm8 data
IEncode ror_r_i(char w, char reg, char imm8);
//memory by immediate count = 1100 000w : mod 001 r/m : imm8 data
IEncode ror_m_i(char w, char mod, char rm, char imm8);

///RSM : Resume from System Management Mode 0000 1111 : 1010 1010
IEncode rsm();
///SAHF : Store AH into Flags 1001 1110
IEncode sahf();

///SAR : Shift Arithmetic Right
//register by 1 = 1101 000w : 11 111 reg
IEncode sar_r_1(char w, char reg);
//memory by 1 = 1101 000w : mod 111 r/m
IEncode sar_m_1(char w, char mod, char rm);
//register by CL = 1101 001w : 11 111 reg
IEncode sar_r_cl(char w, char reg);
//memory by CL = 1101 001w : mod 111 r/m
IEncode sar_m_cl(char w, char mod, char rm);
//register by immediate count = 1100 000w : 11 111 reg : imm8 data
IEncode sar_r_i(char w, char reg, char imm8);
//memory by immediate count = 1100 000w : mod 111 r/m : imm8 data
IEncode sar_m_i(char w, char mod, char rm, char imm8);

///SBB : Integer Subtraction with Borrow
//register1 to register2 = 0001 100w : 11 reg1 reg2
IEncode sbb_r1_r2(char w, char reg1, char reg2);
//register2 to register1 = 0001 101w : 11 reg1 reg2
IEncode sbb_r2_r1(char w, char reg1, char reg2);
//memory to register = 0001 101w : mod reg r/m
IEncode sbb_m_r(char w, char mod, char reg, char rm);
//register to memory = 0001 100w : mod reg r/m
IEncode sbb_r_m(char w, char mod, char reg, char rm);
//immediate to register = 1000 00sw : 11 011 reg : immediate data
IEncode sbb_i_r(char s, char w, char reg, int imm, int n_byte);
//immediate to AL, AX, or EAX = 0001 110w : immediate data
IEncode sbb_i_ra(char w, int imm, int n_byte);
//immediate to memory = 1000 00sw : mod 011 r/m : immediate data
IEncode sbb_i_m(char s, char w, char mod, char rm, int imm, int n_byte);

///SCAS/SCASB/SCASW/SCASD : Scan String = 1101 111w
IEncode scas(char w);

///SETcc : Byte Set on Condition
//register 0000 1111 : 1001 tttn : 11 000 reg
IEncode setc_r(char tttn, char reg);
//memory 0000 1111 : 1001 tttn : mod 000 r/m
IEncode setc_m(char tttn, char mod, char rm);

///SGDT : Store Global Descriptor Table Register = 0000 1111 : 0000 0001 : mod 000 r/m
IEncode sgdt(char mod, char rm);

///SHL : Shift Left
//register by 1 = 1101 000w : 11 100 reg
IEncode shl_r_1(char w, char reg);
//memory by 1 = 1101 000w : mod 100 r/m
IEncode shl_m_1(char w, char mod, char rm);
//register by CL = 1101 001w : 11 100 reg
IEncode shl_r_cl(char w, char reg);
//memory by CL = 1101 001w : mod 100 r/m
IEncode shl_m_cl(char w, char mod, char rm);
//register by immediate count = 1100 000w : 11 100 reg : imm8 data
IEncode shl_r_i(char w, char reg, char imm8);
//memory by immediate count = 1100 000w : mod 100 r/m : imm8 data
IEncode shl_m_i(char w, char mod, char rm, char imm8);

///SHLD : Double Precision Shift Left
//register by immediate count = 0000 1111 : 1010 0100 : 11 reg2 reg1 : imm8
IEncode shld_r_i(char reg2, char reg1, char imm8);
//memory by immediate count = 0000 1111 : 1010 0100 : mod reg r/m : imm8
IEncode shld_m_i(char mod, char reg, char rm, char imm8);
//register by CL = 0000 1111 : 1010 0101 : 11 reg2 reg1
IEncode shld_r_cl(char reg2, char reg1);
//memory by CL = 0000 1111 : 1010 0101 : mod reg r/m
IEncode shld_m_cl(char mod, char reg, char rm);

///SHR : Shift Right
//register by 1 = 1101 000w : 11 101 reg
IEncode shr_r_1(char w, char reg);
//memory by 1 = 1101 000w : mod 101 r/m
IEncode shr_m_1(char w, char mod, char rm);
//register by CL = 1101 001w : 11 101 reg
IEncode shr_r_cl(char w, char reg);
//memory by CL = 1101 001w : mod 101 r/m
IEncode shr_m_cl(char w, char mod, char rm);
//register by immediate count = 1100 000w : 11 101 reg : imm8 data
IEncode shr_r_i(char w, char reg, char imm8);
//memory by immediate count = 1100 000w : mod 101 r/m : imm8 data
IEncode shr_m_i(char w, char mod, char rm, char imm8);

///SHRD : Double Precision Shift Right
//register by immediate count = 0000 1111 : 1010 1100 : 11 reg2 reg1 : imm8
IEncode shrd_r_i(char reg2, char reg1, char imm8);
//memory by immediate count = 0000 1111 : 1010 1100 : mod reg r/m : imm8
IEncode shrd_m_i(char mod, char reg, char rm, char imm8);
//register by CL = 0000 1111 : 1010 1101 : 11 reg2 reg1
IEncode shrd_r_cl(char reg2, char reg1);
//memory by CL = 0000 1111 : 1010 1101 : mod reg r/m
IEncode shrd_m_cl(char mod, char reg, char rm);

///SIDT : Store Interrupt Descriptor Table Register = 0000 1111 : 0000 0001 : mod 001 r/m
IEncode sidt(char mod, char rm);

///SLDT : Store Local Descriptor Table Register
//to register = 0000 1111 : 0000 0000 : 11 000 reg
IEncode sldt_r(char reg);
//to memory = 0000 1111 : 0000 0000 : mod 000 r/m
IEncode sldt_m(char mod, char rm);

///SMSW : Store Machine Status Word
//to register = 0000 1111 : 0000 0001 : 11 100 reg
IEncode smsw_r(char reg);
//to memory = 0000 1111 : 0000 0001 : mod 100 r/m
IEncode smsw_m(char mod, char rm);

///STC : Set Carry Flag = 1111 1001
IEncode stc();

///STD : Set Direction Flag 1111 1101
IEncode stdf();

///STI : Set Interrupt Flag = 1111 1011
IEncode sti();

///STOS/STOSB/STOSW/STOSD : Store String Data = 1010 101w
IEncode stos(char w);

///STR : Store Task Register
//to register = 0000 1111 : 0000 0000 : 11 001 reg
IEncode str_r(char reg);
//to memory = 0000 1111 : 0000 0000 : mod 001 r/m
IEncode str_m(char mod, char rm);

///SUB : Integer Subtraction
//register1 to register2 = 0010 100w : 11 reg1 reg2
IEncode sub_r1_r2(char w, char reg1, char reg2);
//register2 to register1 = 0010 101w : 11 reg1 reg2
IEncode sub_r2_r1(char w, char reg1, char reg2);
//memory to register = 0010 101w : mod reg r/m
IEncode sub_m_r(char w, char mod, char reg, char rm);
//register to memory = 0010 100w : mod reg r/m
IEncode sub_r_m(char w, char mod, char reg, char rm);
//immediate to register = 1000 00sw : 11 101 reg : immediate data
IEncode sub_i_r(char s, char w, char reg, int imm, int n_byte);
//immediate to AL, AX, or EAX = 0010 110w : immediate data
IEncode sub_i_ra(char w, int imm, int n_byte);
//immediate to memory = 1000 00sw : mod 101 r/m : immediate data
IEncode sub_i_m(char s, char w, char mod, char rm, int imm, int n_byte);

///TEST : Logical Compare
//register1 and register2 = 1000 010w : 11 reg1 reg2
IEncode test_r_r(char w, char reg1, char reg2);
//memory and register = 1000 010w : mod reg r/m
IEncode test_m_r(char w, char mod, char reg, char rm);
//immediate and register = 1111 011w : 11 000 reg : immediate data
IEncode test_i_r(char w, char reg, int imm, int n_byte);
//immediate and AL, AX, or EAX = 1010 100w : immediate data
IEncode test_i_ra(char w, int imm, int n_byte);
//immediate and memory = 1111 011w : mod 000 r/m : immediate data
IEncode test_i_m(char w, char mod, char rm, int imm, int n_byte);

///UD2 : Undefined instruction 0000 FFFF : 0000 1011
IEncode ud2();

///VERR : Verify a Segment for Reading
//register = 0000 1111 : 0000 0000 : 11 100 reg
IEncode verr(char reg);
//memory = 0000 1111 : 0000 0000 : mod 100 r/m
IEncode verr(char mod, char rm);

///VERW : Verify a Segment for Writing
//register = 0000 1111 : 0000 0000 : 11 101 reg
IEncode verw(char reg);
//memory = 0000 1111 : 0000 0000 : mod 101 r/m
IEncode verw(char mod, char rm);

///WAIT : Wait = 1001 1011
IEncode wait();

///WBINVD : Writeback and Invalidate Data Cache = 0000 1111 : 0000 1001
IEncode wbinvd();

///WRMSR : Write to Model-Specific Register = 0000 1111 : 0011 0000
IEncode wrmsr();

///XADD : Exchange and Add
//register1, register2 = 0000 1111 : 1100 000w : 11 reg2 reg1
IEncode xadd_r_r(char w, char reg1, char reg2);
//memory, reg = 0000 1111 : 1100 000w : mod reg r/m
IEncode xadd_m_r(char w, char mod, char reg, char rm);

///XCHG : Exchange Register/Memory with Register
//register1 with register2 = 1000 011w : 11 reg1 reg2
IEncode xchg_r_r(char w, char reg1, char reg2);
//AL, AX, or EAX with reg = 1001 0 reg
IEncode xchg_ra_r(char reg);
//memory with reg = 1000 011w : mod reg r/m
IEncode xchg_m_r(char w, char mod, char reg, char rm);

///XLAT/XLATB : Table Look-up Translation = 1101 0111
IEncode xlat();

///XOR : Logical Exclusive OR
//register1 to register2 = 0011 000w : 11 reg1 reg2
IEncode xor_r1_r2(char w, char reg1, char reg2);
//register2 to register1 = 0011 001w : 11 reg1 reg2
IEncode xor_r2_r1(char w, char reg1, char reg2);
//memory to register = 0011 001w : mod reg r/m
IEncode xor_m_r(char w, char mod, char reg, char rm);
//register to memory = 0011 000w : mod reg r/m
IEncode xor_r_m(char w, char mod, char reg, char rm);
//immediate to register = 1000 00sw : 11 110 reg : immediate data
IEncode xor_i_r(char s, char w, char reg, int imm, int n_byte);
//immediate to AL, AX, or EAX = 0011 010w : immediate data
IEncode xor_i_ra(char w, int imm, int n_byte);
//immediate to memory = 1000 00sw : mod 110 r/m : immediate data
IEncode xor_i_m(char s, char w, char mod, char rm, int imm, int n_byte);

/*********
* UTIL
*********/
void printHex(char ch);
void printHex(int i32, int n_byte=sizeof(int), char invert=0);
void printModRM(ModRM modrm);
void print(IEncode ie);
void write(ofstream &o, IEncode &ie);

#endif
