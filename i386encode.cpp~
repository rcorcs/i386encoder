/****************************************************/
/* File: i386encode.cpp                             */
/* ROCHA, Rodrigo Caetano de Oliveira			    */
/* rcor                                             */
/****************************************************/

#include "i386encode.h"

#include <iostream>
using std::cout;
using std::endl;
using std::hex;

//AAA : ASCII Adjust after Addition = 0011 0111
IEncode aaa()
{
	_IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x37,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//AAD : ASCII Adjust AX before Division = 1101 0101 0000 1010
IEncode aad()
{
	_IENCODE(1,1,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD5,0x0A,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//AAD : ASCII Adjust AX before Division = 1101 0100 0000 1010
IEncode aam()
{
	_IENCODE(1,1,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD4,0x0A,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//AAS : ASCII Adjust AL after Subtraction = 0011 1111
IEncode aas()
{
	_IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x3F,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/****************************
* ADC : ADD with Carry
****************************/
//register1 to register2 = 0001 000w : 11 reg1 reg2
IEncode adc_r1_r2(char w, char reg1, char reg2)
{
	_IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x10,0,w,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register2 to register1 = 0001 001w : 11 reg1 reg2
IEncode adc_r2_r1(char w, char reg1, char reg2)
{
	_IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x12,0,w,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory to register = 0001 001w : mod reg r/m
IEncode adc_m_r(char w, char mod, char reg, char rm)
{
	_IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x12,0,w,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register to memory = 0001 000w : mod reg r/m
IEncode adc_r_m(char w, char mod, char reg, char rm)
{
	_IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x10,0,w,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//immediate to register = 1000 00sw : 11 010 reg : immediate data
IEncode adc_i_r(char s, char w, char reg, int imm, int n_byte)
{
	_IENCODE(1,0,1,1,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x80, 0, w, s, 0x3, 0x2, reg, 0, 0, imm, n_byte);
	_END_IENCODE;
}

//immediate to AL, AX, or EAX = 0001 010w : immediate data
IEncode adc_i_ra(char w, int imm, int n_byte)
{
	_IENCODE(1,0,1,0,0,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x14, 0, w, 0, 0, 0, 0, 0, 0, imm, n_byte);
	_END_IENCODE;
}

//immediate to memory = 1000 00sw : mod 010 r/m : immediate data
IEncode adc_i_m(char s, char w, char mod, char rm, int imm, int n_byte)
{
	_IENCODE(1,0,1,1,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x80, 0, w, s, mod, 0x2, rm, 0, 0, imm, n_byte);
	_END_IENCODE;
}

/****************************
* ADD : Add
****************************/
//register1 to register2 = 0000 000w : 11 reg1 reg2
IEncode add_r1_r2(char w, char reg1, char reg2)
{
	_IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x00,0,w,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register2 to register1 = 0000 001w : 11 reg1 reg2
IEncode add_r2_r1(char w, char reg1, char reg2)
{
	_IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x02,0,w,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory to register = 0000 001w : mod reg r/m
IEncode add_m_r(char w, char mod, char reg, char rm)
{
	_IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x02,0,w,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register to memory = 0000 000w : mod reg r/m
IEncode add_r_m(char w, char mod, char reg, char rm)
{
	_IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x00,0,w,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//immediate to register = 1000 00sw : 11 000 reg : immediate data
IEncode add_i_r(char s, char w, char reg, int imm, int n_byte)
{
	_IENCODE(1,0,1,1,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x80, 0, w, s, 0x3, 0x0, reg, 0, 0, imm, n_byte);
	_END_IENCODE;
}

//immediate to AL, AX, or EAX = 0000 010w : immediate data
IEncode add_i_ra(char w, int imm, int n_byte)
{
	_IENCODE(1,0,1,0,0,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x04, 0, w, 0, 0, 0, 0, 0, 0, imm, n_byte);
	_END_IENCODE;
}

//immediate to memory = 1000 00sw : mod 000 r/m : immediate data
IEncode add_i_m(char s, char w, char mod, char rm, int imm, int n_byte)
{
	_IENCODE(1,0,1,1,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x80, 0, w, s, mod, 0x0, rm, 0, 0, imm, n_byte);
	_END_IENCODE;
}

/**********************************
* AND : Logical AND
**********************************/
//register1 to register2 = 0010 000w : 11 reg1 reg2
IEncode and_r1_r2(char w, char reg1, char reg2)
{
	_IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x20,0,w,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register2 to register1 = 0010 001w : 11 reg1 reg2
IEncode and_r2_r1(char w, char reg1, char reg2)
{
	_IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x22,0,w,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory to register = 0010 001w : mod reg r/m
IEncode and_m_r(char w, char mod, char reg, char rm)
{
	_IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x22,0,w,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register to memory = 0010 000w : mod reg r/m
IEncode and_r_m(char w, char mod, char reg, char rm)
{
	_IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x20,0,w,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//I AM NOT SURE IF THIS INTRUCTION IS RIGHT
//immediate to register = 1000 00sw : 11 100 reg : immediate data
IEncode and_i_r(char s, char w, char reg, int imm, int n_byte)
{
	_IENCODE(1,0,1,1,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x80, 0, w, s, 0x3, 0x4, reg, 0, 0, imm, n_byte);
	_END_IENCODE;
}

//immediate to AL, AX, or EAX = 0010 010w : immediate data
IEncode and_i_ra(char w, int imm, int n_byte)
{
	_IENCODE(1,0,1,0,0,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x24, 0, w, 0, 0, 0, 0, 0, 0, imm, n_byte);
	_END_IENCODE;
}

//immediate to memory = 1000 00sw : mod 100 r/m : immediate data
IEncode and_i_m(char s, char w, char mod, char rm, int imm, int n_byte)
{
	_IENCODE(1,0,1,1,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x80, 0, w, s, mod, 0x4, rm, 0, 0, imm, n_byte);
	_END_IENCODE;
}


/***************************************
* ARPL : Adjust RPL Field of Selector
***************************************/
//from register = 0110 0011 : 11 reg1 reg2
IEncode arpl_r(char reg1, char reg2)
{
    _IENCODE(1,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x63,0,0,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//from memory = 0110 0011 : mod reg r/m
IEncode arpl_m(char mod, char reg, char rm)
{
    _IENCODE(1,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
    _SET_IENCODE(0x63,0,0,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///BOUND : Check Array Against Bounds = 0110 0010 : mod reg r/m
IEncode bound(char mod, char reg, char rm)
{
    _IENCODE(1,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x62,0,0,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/***************************************
* BSF : Bit Scan Forward
***************************************/
//register1, register2 = 0000 1111 : 1011 1100 : 11 reg2 reg1
IEncode bsf_r_r(char reg1, char reg2)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xBC,0,0x3,reg2,reg1); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory, register = 0000 1111 : 1011 1100 : mod reg r/m
IEncode bsf_m_r(char mod, char reg, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
    _SET_IENCODE(0x0F,0xBC,0,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/***************************************
* BSR : Bit Scan Reverse
***************************************/
//register1, register2 = 0000 1111 : 1011 1101 : 11 reg2 reg1
IEncode bsr_r_r(char reg1, char reg2)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xBD,0,0x3,reg2,reg1); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory, register = 0000 1111 : 1011 1101 : mod reg r/m
IEncode bsr_m_r(char mod, char reg, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
    _SET_IENCODE(0x0F,0xBD,0,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///BSWAP : Byte Swap = 0000 1111 : 11 001 reg
IEncode bswap(char reg)
{
    _IENCODE(1,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
    _SET_IENCODE(0x0F,0,0,0x3,0x1,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/********************************************
* BT : Bit Test
********************************************/
//register, immediate = 0000 1111 : 1011 1010 : 11 100 reg: imm8 data
IEncode bt_r_i(char reg, int imm8)
{
    _IENCODE(1,1,0,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
    //_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x0F, 0xBA, 0, 0, 0x3, 0x4, reg, 0, 0, imm8, 1);
	_END_IENCODE;
}

//memory, immediate = 0000 1111 : 1011 1010 : mod 100 r/m : imm8 data
IEncode bt_m_i(char mod, char rm, int imm8)
{
    _IENCODE(1,1,0,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x0F, 0xBA, 0, 0, mod, 0x4, rm, 0, 0, imm8, 1);
	_END_IENCODE;
}

//register1, register2 = 0000 1111 : 1010 0011 : 11 reg2 reg1
IEncode bt_r_r(char reg1, char reg2)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
    _SET_IENCODE(0x0F,0xA3,0,0x3,reg2,reg1); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory, reg = 0000 1111 : 1010 0011 : mod reg r/m
IEncode bt_m_r(char mod, char reg, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xA3,0,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/********************************************
* BTC : Bit Test and Complement
********************************************/
//register, immediate = 0000 1111 : 1011 1010 : 11 111 reg: imm8 data
IEncode btc_r_i(char reg, int imm8)
{
    _IENCODE(1,1,0,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x0F, 0xBA, 0, 0, 0x3, 0x7, reg, 0, 0, imm8, 1);
	_END_IENCODE;
}

//memory, immediate = 0000 1111 : 1011 1010 : mod 111 r/m : imm8 data
IEncode btc_m_i(char mod, char rm, int imm8)
{
    _IENCODE(1,1,0,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x0F, 0xBA, 0, 0, mod, 0x7, rm, 0, 0, imm8, 1);
	_END_IENCODE;
}

//register1, register2 = 0000 1111 : 1011 1011 : 11 reg2 reg1
IEncode btc_r_r(char reg1, char reg2)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
    _SET_IENCODE(0x0F,0xBB,0,0x3,reg2,reg1); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory, reg = 0000 1111 : 1011 1011 : mod reg r/m
IEncode btc_m_r(char mod, char reg, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xBB,0,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/********************************************
* BTR : Bit Test and Reset
********************************************/
//register, immediate = 0000 1111 : 1011 1010 : 11 110 reg: imm8 data
IEncode btr_r_i(char reg, int imm8)
{
    _IENCODE(1,1,0,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
    //_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x0F, 0xBA, 0, 0, 0x3, 0x6, reg, 0, 0, imm8, 1);
	_END_IENCODE;
}

//memory, immediate = 0000 1111 : 1011 1010 : mod 110 r/m : imm8 data
IEncode btr_m_i(char mod, char rm, int imm8)
{
    _IENCODE(1,1,0,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x0F, 0xBA, 0, 0, mod, 0x6, rm, 0, 0, imm8, 1);
	_END_IENCODE;
}

//register1, register2 = 0000 1111 : 1011 0011 : 11 reg2 reg1
IEncode btr_r_r(char reg1, char reg2)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
    _SET_IENCODE(0x0F,0xB3,0,0x3,reg2,reg1); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory, reg = 0000 1111 : 1011 0011 : mod reg r/m
IEncode btr_m_r(char mod, char reg, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xB3,0,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/********************************************
* BTS : Bit Test and Set
********************************************/
//register, immediate = 0000 1111 : 1011 1010 : 11 101 reg: imm8 data
IEncode bts_r_i(char reg, int imm8)
{
    _IENCODE(1,1,0,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x0F, 0xBA, 0, 0, 0x3, 0x5, reg, 0, 0, imm8, 1);
	_END_IENCODE;
}

//memory, immediate = 0000 1111 : 1011 1010 : mod 101 r/m : imm8 data
IEncode bts_m_i(char mod, char rm, int imm8)
{
    _IENCODE(1,1,0,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x0F, 0xBA, 0, 0, mod, 0x5, rm, 0, 0, imm8, 1);
	_END_IENCODE;
}

//register1, register2 = 0000 1111 : 1010 1011 : 11 reg2 reg1
IEncode bts_r_r(char reg1, char reg2)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
    _SET_IENCODE(0x0F,0xAB,0,0x3,reg2,reg1); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory, reg = 0000 1111 : 1010 1011 : mod reg r/m
IEncode bts_m_r(char mod, char reg, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xAB,0,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/********************************************
* CALL : Call Procedure (in same segment)
********************************************/
//direct = 1110 1000 : full displacement
IEncode call_ss(int disp)
{
    _IENCODE(1,0,0,0,0,0,1,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
    //_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
    _SET_FULL_IENCODE(0xFF, 0, 0, 0, 0, 0, 0, disp, sizeof(int), 0, 0);
	_END_IENCODE;
}

//register indirect = 1111 1111 : 11 010 reg
IEncode call_ss_r(char reg)
{
    _IENCODE(1,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
    _SET_IENCODE(0xFF,0,0,0x3,0x2,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory indirect = 1111 1111 : mod 010 rm
IEncode call_ss_m(char mod, char rm)
{
    _IENCODE(1,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xFF,0,0,mod,0x2,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/********************************************
* CALL : Call Procedure (in other segment)
********************************************/

IEncode call_os(int disp)
{
    _IENCODE(1,0,0,0,0,0,1,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
    _SET_FULL_IENCODE(0x9A, 0, 0, 0, 0, 0, 0, disp, sizeof(int), 0, 0);
	_END_IENCODE;
}

IEncode call_os_m(char mod, char rm)
{
    _IENCODE(1,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xFF,0,0,mod,0x3,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///CBW - Convert Byte to Word = 1001 1000
IEncode cbw()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x98,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///CDQ : Convert Doubleword to Qword = 1001 1001
IEncode cdq()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x99,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///CLC : Clear Carry Flag = 1111 1000
IEncode clc()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xF8,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///CLD : Clear Direction Flag = 1111 1100
IEncode cld()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xFC,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///CLI : Clear Interrupt Flag = 1111 1010
IEncode cli()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xFA,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///CLTS : Clear Task-Switched Flag in CR0 = 0000 1111 : 0000 0110
IEncode clts()
{
    _IENCODE(1,1,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x06,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///CMC : Complement Carry Flag = 1111 0101
IEncode cmc()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xF5,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/************************************************
* CMOVcc : Conditional Move
************************************************/
//register2 to register1 = 0000 1111: 0100 tttn : 11 reg1 reg2
IEncode cmov_r_r(char tttn, char reg1, char reg2)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,1); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
    _SET_IENCODE(0x0F,0x40,0,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_SET_TTTN(tttn);
	_END_IENCODE;
}

//memory to register = 0000 1111: 0100 tttn : mod mem r/m
IEncode cmov_m_r(char tttn, char mod, char mem, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,1); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
    _SET_IENCODE(0x0F,0x40,0,mod,mem,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_SET_TTTN(tttn);
	_END_IENCODE;
}

/************************************************
* CMP : Compare Two Operands
************************************************/
//register1 with register2 = 0011 100w : 11 reg1 reg2
IEncode cmp_r_r(char w, char reg1, char reg2)
{
    return cmp_r1_r2(w,reg1,reg2);
}

//register1 with register2 = 0011 100w : 11 reg1 reg2
IEncode cmp_r1_r2(char w, char reg1, char reg2)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
    _SET_IENCODE(0x38,0,w,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register2 with register1 = 0011 101w : 11 reg1 reg2
IEncode cmp_r2_r1(char w, char reg1, char reg2)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x3A,0,w,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory with register = 0011 100w : mod reg r/m
IEncode cmp_m_r(char w, char mod, char reg, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
    _SET_IENCODE(0x38,0,w,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register with memory 0011 101w : mod reg r/m
IEncode cmp_r_m(char w, char mod, char reg, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x3A,0,w,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//immediate with register = 1000 00sw : 11 111 reg : immediate data
IEncode cmp_i_r(char s, char w, char reg, int imm, int n_byte)
{
    _IENCODE(1,0,1,1,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x80, 0, w, s, 0x3, 0x7, reg, 0, 0, imm, n_byte);
	_END_IENCODE;
}

//immediate with AL, AX, or EAX = 0011 110w : immediate data
IEncode cmp_i_ra(char w, int imm, int n_byte)
{
    _IENCODE(1,0,1,0,0,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x3C, 0, w, 0, 0, 0, 0, 0, 0, imm, n_byte);
	_END_IENCODE;
}

//immediate with memory = 1000 00sw : mod 111 r/m (: immediate data)
IEncode cmp_i_m(char s, char w, char mod, char rm, int imm, int n_byte)
{
    _IENCODE(1,0,1,1,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
    //_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x3C, 0, w, s, mod, 0x7, rm, 0, 0, imm, n_byte);
	_END_IENCODE;
}

///CMPS/CMPSB/CMPSW/CMPSD : Compare String Operands = 1010 011w
IEncode cmps(char w)
{
    _IENCODE(1,0,1,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
    _SET_IENCODE(0xA6,0,w,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/*******************************************************
* CMPXCHG : Compare and Exchange
********************************************************/
//register1, register2 = 0000 1111 : 1011 000w : 11 reg2 reg1
IEncode cmpxchg(char w, char reg1, char reg2)
{
    _IENCODE(1,1,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xB0,w,0x3,reg2,reg1); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory, register = 0000 1111 : 1011 000w : mod reg r/m
IEncode cmpxchg(char w, char mod, char reg, char rm)
{
    _IENCODE(1,1,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xB0,w,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/*********************************************************
* CMPXCHG8B : Compare and Exchange 8 Bytes
*********************************************************/
//memory, register = 0000 1111 : 1100 0111 : mod reg r/m
IEncode cmpxchg8b(char mod, char reg, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xC7,0,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///CPUID : CPU Identification = 0000 1111 : 1010 0010
IEncode cpuid()
{
    _IENCODE(1,1,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xA2,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///CWD : Convert Word to Doubleword = 1001 1001
IEncode cwd()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x99,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///CWDE : Convert Word to Doubleword = 1001 1000
IEncode cwde()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x98,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///DAA : Decimal Adjust AL after Addition = 0010 0111
IEncode daa()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x27,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///DAS : Decimal Adjust AL after Subtraction = 0010 1111
IEncode das()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x2F,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/****************************************
* DEC : Decrement by 1
****************************************/
//register = 1111 111w : 11 001 reg
IEncode dec_r(char w, char reg)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xFE,0,w,0x3,0x1,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register (alternate encoding) = 01 001 reg
IEncode dec_r(char reg)
{
    _IENCODE(0,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0,0,0,0x1,0x1,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory = 1111 111w : mod 001 r/m
IEncode dec_m(char w, char mod, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xFE,0,w,mod,0x1,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/********************************************************
* DIV : Unsigned Divide
********************************************************/
//AL, AX, or EAX by register = 1111 011w : 11 110 reg
IEncode div_ra_r(char w, char reg)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
    _SET_IENCODE(0xF6,0,w,0x3,0x6,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//AL, AX, or EAX by memory 1111 011w : mod 110 r/m
IEncode div_ra_m(char w, char mod, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xF6,0,w,mod,0x6,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///ENTER : Make Stack Frame for High Level Procedure = 1100 1000 : 16-bit displacement : 8-bit level (L)
IEncode enter(int disp16, char level)
{
    _IENCODE(1,0,0,0,0,0,1,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xC8, 0, 0, 0, 0, 0, 0, disp16, 2, level, 1); //8-bit level (L) ?
	_END_IENCODE;
}

///HLT : Halt = 1111 0100
IEncode hlt(char w, char mod, char rm)
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
    _SET_IENCODE(0xF4,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/********************************************************
* IDIV : Signed Divide
********************************************************/
//AL, AX, or EAX by register = 1111 011w : 11 111 reg
IEncode idiv_ra_r(char w, char reg)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xF6,0,w,0x3,0x7,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//AL, AX, or EAX by memory = 1111 011w : mod 111 r/m
IEncode idiv_ra_m(char w, char mod, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xF6,0,w,mod,0x7,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/***********************************************************
* IMUL : Signed Multiply
***********************************************************/
//AL, AX, or EAX with register = 1111 011w : 11 101 reg
IEncode imul_ra_r(char w, char reg)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xF6,0,w,0x3,0x5,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//AL, AX, or EAX with memory = 1111 011w : mod 101 reg
IEncode imul_ra_m(char w, char mod, char reg)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xF6,0,w,mod,0x5,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register1 with register2 = 0000 1111 : 1010 1111 : 11 : reg1 reg2
IEncode imul_r_r(char reg1, char reg2)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xAF,0,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register with memory = 0000 1111 : 1010 1111 : mod reg r/m
IEncode imul_r_m(char mod, char reg, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xAF,0,mod,reg,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register1 with immediate to register2 = 0110 10s1 : 11 reg1 reg2 : immediate data
IEncode imul_r_i_r(char s, char reg1, char reg2, int imm, int n_byte)
{
    _IENCODE(1,0,0,1,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x69, 0, 0, 1, 0x3, reg1, reg2, 0, 0, imm, n_byte); //8-bit level (L) ?
	_END_IENCODE;
}

//memory with immediate to register = 0110 10s1 : mod reg r/m : immediate data
IEncode imul_m_i_r(char s, char mod, char reg, char rm, int imm, int n_byte)
{
    _IENCODE(1,0,0,1,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x69, 0, 0, 1, mod, reg, rm, 0, 0, imm, n_byte); //8-bit level (L) ?
	_END_IENCODE;
}

/************************************************************************
* IN : Input From Port
************************************************************************/
//fixed port = 1110 010w : port number
IEncode in_fp(char w, char port)
{
    _IENCODE(1,0,1,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xE4,port,w,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//variable port = 1110 110w
IEncode in_vp(char w)
{
    _IENCODE(1,0,1,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xEC,0,w,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/************************************************************************
* INC : Increment by 1
************************************************************************/
//reg = 1111 111w : 11 000 reg
IEncode inc_r(char w, char reg)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xFE,0,w,0x3,0x0,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//reg (alternate encoding) = 01 000 reg
IEncode inc_r(char reg)
{
    _IENCODE(0,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0,0,0,0x1,0x0,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory = 1111 111w : mod 000 r/m
IEncode inc_m(char w, char mod, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xFE,0,w,mod,0x0,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///INS : Input from DX Port = 0110 110w
IEncode ins(char w)
{
    _IENCODE(1,0,1,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x6C,0,w,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///INT n : Interrupt Type n = 1100 1101 : type
IEncode int_n(char type)
{
    _IENCODE(1,1,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xCD,type,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///INT : Single-Step Interrupt 3 = 1100 1100
IEncode int_ss()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xCC,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///INTO : Interrupt 4 on Overflow = 1100 1110
IEncode into()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xCE,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///INVD : Invalidate Cache = 0000 1111 : 0000 1000
IEncode invd()
{
    _IENCODE(1,1,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x08,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///INVLPG : Invalidate TLB Entry = 0000 1111 : 0000 0001
IEncode invlpg()
{
    _IENCODE(1,1,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x01,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///IRET/IRETD : Interrupt Return = 1100 1111
IEncode iret()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xCF,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/********************************************************
* Jcc : Jump if Condition is Met
********************************************************/
//8-bit displacement 0111 tttn : 8-bit displacement
IEncode jc_8b(char tttn, char disp8)
{
    _IENCODE(1,0,0,0,0,0,1,0,0,1); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x70, 0, 0, 0, 0, 0, 0, disp8, 1, 0, 0);
	_SET_TTTN(tttn);
	_END_IENCODE;
}

//full displacement 0000 1111 : 1000 tttn : full displacement
IEncode jc(char tttn, int disp)
{
    _IENCODE(1,1,0,0,0,0,1,0,0,1); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x0F, 0x80, 0, 0, 0, 0, 0, disp, sizeof(int), 0, 0);
	_SET_TTTN(tttn);
	_END_IENCODE;
}

/********************************************************
* JMP : Unconditional Jump (to same segment)
********************************************************/
//short = 1110 1011 : 8-bit displacement
IEncode jmp_ss_s(char disp8)
{
    _IENCODE(1,0,0,0,0,0,1,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xEB, 0, 0, 0, 0, 0, 0, disp8, 1, 0, 0);
	_END_IENCODE;
}

//direct = 1110 1001 : full displacement
IEncode jmp_ss_d(int disp)
{
    _IENCODE(1,0,0,0,0,0,1,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xE9, 0, 0, 0, 0, 0, 0, disp, sizeof(int), 0, 0);
	_END_IENCODE;
}

//register indirect = 1111 1111 : 11 100 reg
IEncode jmp_ss_r(char reg)
{
    _IENCODE(1,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xFF,0,0,0x3,0x4,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory indirect = 1111 1111 : mod 100 r/m
IEncode jmp_ss_m(char mod, char rm)
{
    _IENCODE(1,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xFF,0,0,mod,0x4,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///LAHF : Load Flags into AHRegister = 1001 1111
IEncode lahf()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x9F,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/********************************************************
* LAR : Load Access Rights Byte
********************************************************/
//from register 0000 1111 : 0000 0010 : 11 reg1 reg2
IEncode lar_r(char reg1, char reg2)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x02,0,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//from memory 0000 1111 : 0000 0010 : mod reg r/m
IEncode lar_r(char mod, char reg, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x02,0,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///LDS : Load Pointer to DS = 1100 0101 : mod reg r/m
IEncode lds(char mod, char reg, char rm)
{
    _IENCODE(1,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xC5,0,0,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///LEA : Load Effective Address = 1000 1101 : mod reg r/m
IEncode lea(char mod, char reg, char rm)
{
    _IENCODE(1,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x8D,0,0,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///LEAVE : High Level Procedure Exit = 1100 1001
IEncode leave()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xC9,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///LES : Load Pointer to ES = 1100 0100 : mod reg r/m
IEncode les(char mod, char reg, char rm)
{
    _IENCODE(1,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xC4,0,0,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///LFS : Load Pointer to FS = 0000 1111 : 1011 0100 : mod reg r/m
IEncode lfs(char mod, char reg, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xB4,0,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///LGDT : Load Global Descriptor Table Register = 0000 1111 : 0000 0001 : mod 010 r/m
IEncode lgdt(char mod, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x01,0,mod,0x2,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///LGS : Load Pointer to GS = 0000 1111 : 1011 0101 : mod reg r/m
IEncode lgs(char mod, char reg, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xB5,0,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/**************************************************************
* LLDT : Load Local Descriptor Table Register
**************************************************************/
//LDTR from register 0000 1111 : 0000 0000 : 11 010 reg
IEncode lldt_r(char reg)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x00,0,0x3,0x2,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//LDTR from memory 0000 1111 : 0000 0000 : mod 010 r/m
IEncode lldt_r(char mod, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x00,0,mod,0x2,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/**************************************************************
* LMSW : Load Machine Status Word
**************************************************************/
//from register 0000 1111 : 0000 0001 : 11 110 reg
IEncode lmsw_r(char reg)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x01,0,0x3,0x6,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//from memory 0000 1111 : 0000 0001 : mod 110 r/m
IEncode lmsw_m(char mod, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x01,0,mod,0x6,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///LOCK : Assert LOCK# Signal Prefix 1111 0000
IEncode lock()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xF0,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///LODS/LODSB/LODSW/LODSD : Load String Operand 1010 110w
IEncode lods(char w)
{
    _IENCODE(1,0,1,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xAC,0,w,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///LOOP : Loop Count 1110 0010 : 8-bit displacement
IEncode loop(char disp8)
{
    _IENCODE(1,0,0,0,0,0,1,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xE2, 0, 0, 0, 0, 0, 0, disp8, 1, 0, 0);
	_END_IENCODE;
}

///LOOPZ/LOOPE : Loop Count while Zero/Equal 1110 0001 : 8-bit displacement
IEncode loopz(char disp8)
{
    _IENCODE(1,0,0,0,0,0,1,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xE1, 0, 0, 0, 0, 0, 0, disp8, 1, 0, 0);
	_END_IENCODE;
}

///LOOPNZ/LOOPNE : Loop Count while not Zero/Equal 1110 0000 : 8-bit displacement
IEncode loopnz(char disp8)
{
    _IENCODE(1,0,0,0,0,0,1,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xE0, 0, 0, 0, 0, 0, 0, disp8, 1, 0, 0);
	_END_IENCODE;
}

/***********************************************************
* LSL : Load Segment Limit
***********************************************************/
//from register 0000 1111 : 0000 0011 : 11 reg1 reg2
IEncode lsl_r(char reg1, char reg2)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x03,0,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//from memory 0000 1111 : 0000 0011 : mod reg r/m
IEncode lsl_m(char mod, char reg, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x03,0,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/********************************************************
* LTR : Load Task Register
********************************************************/
//from register 0000 1111 : 0000 0000 : 11 011 reg
IEncode ltr_r(char reg)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x00,0,0x3,0x3,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//from memory 0000 1111 : 0000 0000 : mod 011 r/m
IEncode lsl_m(char mod, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x00,0,mod,0x3,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/********************************************************
* MOV : Move Data
********************************************************/
//register1 to register2 1000 100w : 11 reg1 reg2
IEncode mov_r1_r2(char w, char reg1, char reg2)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x88,0,w,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register2 to register1 1000 101w : 11 reg1 reg2
IEncode mov_r2_r1(char w, char reg1, char reg2)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x8A,0,w,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory to reg 1000 101w : mod reg r/m
IEncode mov_m_r(char w, char mod, char reg, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x8A,0,w,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//reg to memory 1000 100w : mod reg r/m
IEncode mov_r_m(char w, char mod, char reg, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x88,0,w,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//immediate to register 1100 011w : 11 000 reg : immediate data
IEncode mov_i_r(char w, char reg, int imm, int n_byte)
{
    _IENCODE(1,0,1,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xC6, 0, w, 0, 0x3, 0, reg, 0, 0, imm, n_byte);
	_END_IENCODE;
}

//immediate to register (alternate encoding) 10 11w reg : immediate data
IEncode mov_i_r_alt(char w, char reg, int imm, int n_byte)
{
    _IENCODE(0,0,0,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0,0,0,0,0x2,(0x6|w),reg,0,0,imm,n_byte);
	_END_IENCODE;
}

//immediate to memory 1100 011w : mod 000 r/m : immediate data
IEncode mov_i_m(char w, char mod, char rm, int imm, int n_byte)
{
    _IENCODE(1,0,1,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xC6, 0, w, 0, mod, 0, rm, 0, 0, imm, n_byte);
	_END_IENCODE;
}

//memory to AL, AX, or EAX 1010 000w : full displacement
IEncode mov_m_ra(char w, int disp)
{
    _IENCODE(1,0,1,0,0,0,1,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xA0,0,w,0,0,0,0,disp,sizeof(int),0,0);
	_END_IENCODE;
}

//AL, AX, or EAX to memory 1010 001w : full displacement
IEncode mov_ra_m(char w, int disp)
{
    _IENCODE(1,0,1,0,0,0,1,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xA2,0,w,0,0,0,0,disp,sizeof(int),0,0);
	_END_IENCODE;
}

/********************************************************
* MOV : Move to/from Control Registers
********************************************************/
//CR0 from register 0000 1111 : 0010 0010 : 11 000 reg
IEncode mov_r_cr0(char reg)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x02,0,0x3,0x0,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//CR2 from register 0000 1111 : 0010 0010 : 11 010reg
IEncode mov_r_cr2(char reg)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x02,0,0x3,0x2,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//CR3 from register 0000 1111 : 0010 0010 : 11 011 reg
IEncode mov_r_cr3(char reg)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x02,0,0x3,0x3,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//CR4 from register 0000 1111 : 0010 0010 : 11 100 reg
IEncode mov_r_cr4(char reg)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x02,0,0x3,0x4,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register from CR0-CR4 0000 1111 : 0010 0000 : 11 eee reg
IEncode mov_cr_r(char eee, char reg)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x20,0,0x3,eee,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/***************************************************************
* MOV : Move to/from Debug Registers
***************************************************************/
//DR? from register 0000 1111 : 0010 0011 : 11 eee reg
IEncode mov_r_dr(char eee, char reg)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x23,0,0x3,eee,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register from DR? 0000 1111 : 0010 0001 : 11 eee reg
IEncode mov_dr_r(char eee, char reg)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x21,0,0x3,eee,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

/*******************************************************************
* MOV : Move to/from Segment Registers
*******************************************************************/
//register to segment register 1000 1110 : 11 sreg3 reg
//register to SS 1000 1110 : 11 sreg3 reg
IEncode mov_r_sr(char sreg3, char reg)
{
    _IENCODE(1,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x8E,0,0,0x3,sreg3,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory to segment reg 1000 1110 : mod sreg3 r/m
//memory to SS 1000 1110 : mod sreg3 r/m
IEncode mov_m_sr(char mod, char sreg3, char rm)
{
    _IENCODE(1,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x8E,0,0,mod,sreg3,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//segment register to register 1000 1100 : 11 sreg3 reg
IEncode mov_sr_r(char sreg3, char reg)
{
    _IENCODE(1,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x8C,0,0,0x3,sreg3,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//segment register to memory 1000 1100 : mod sreg3 r/m
IEncode mov_sr_m(char mod, char sreg3, char rm)
{
    _IENCODE(1,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x8C,0,0,mod,sreg3,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///MOVS/MOVSB/MOVSW/MOVSD : Move Data from String to String 1010 010w
IEncode movs(char w)
{
    _IENCODE(1,0,1,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xA4,0,w,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///MOVSX : Move with Sign-Extend
//register2 to register1 0000 1111 : 1011 111w : 11 reg1 reg2
IEncode movsx_r2_r1(char w, char reg1, char reg2)
{
    _IENCODE(1,1,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xBE,w,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory to reg 0000 1111 : 1011 111w : mod reg r/m
IEncode movsx_m_r(char w, char mod, char reg, char rm)
{
    _IENCODE(1,1,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xBE,w,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///MOVZX : Move with Zero-Extend
//register2 to register1 0000 1111 : 1011 011w : 11 reg1 reg2
IEncode movzx_r2_r1(char w, char reg1, char reg2)
{
    _IENCODE(1,1,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xB6,w,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory to register 0000 1111 : 1011 011w : mod reg r/m
IEncode movzx_m_r(char w, char mod, char reg, char rm)
{
    _IENCODE(1,1,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xB6,w,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///MUL : Unsigned Multiply
//AL, AX, or EAX with register 1111 011w : 11 100 reg
IEncode mul_ra_r(char w, char reg)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xF6,0,w,0x3,0x4,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//AL, AX, or EAX with memory 1111 011w : mod 100 rm
IEncode mul_ra_m(char w, char mod, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xF6,0,w,mod,0x4,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///NEG : Two's Complement Negation
//register 1111 011w : 11 011 reg
IEncode neg_r(char w, char reg)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xF6,0,w,0x3,0x3,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory 1111 011w : mod 011 r/m
IEncode neg_m(char w, char mod, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xF6,0,w,mod,0x3,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///NOP : No Operation 1001 0000
IEncode nop()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x90,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///NOT : One's Complement Negation
//register 1111 011w : 11 010 reg
IEncode not_r(char w, char reg)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xF6,0,w,0x3,0x2,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory 1111 011w : mod 010 r/m
IEncode not_m(char w, char mod, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xF6,0,w,mod,0x2,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///OUT : Output to Port
//fixed port 1110 011w : port number
IEncode out_f(char w, int disp, int n_byte) //port number 16 bits
{
    _IENCODE(1,0,1,0,0,0,1,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xE6,0,w,0,0,0,0,disp,n_byte,0,0);
	_END_IENCODE;
}

//variable port 1110 111w
IEncode out_v(char w)
{
    _IENCODE(1,0,1,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xEE,0,w,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///OUTS : Output to DX Port 0110 111w
IEncode outs_dx(char w)
{
    _IENCODE(1,0,1,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x6E,0,w,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///POP : Pop a Word from the Stack
//register 1000 1111 : 11 000 reg
IEncode pop_r(char reg)
{
    _IENCODE(1,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x8F,0,0,0x3,0x0,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register (alternate encoding) 01 011 reg
IEncode pop_r_alt(char reg)
{
    _IENCODE(0,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0,0,0,0x1,0x3,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory 1000 1111 : mod 000 r/m
IEncode pop_m(char mod, char rm)
{
    _IENCODE(1,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x8F,0,0,mod,0x0,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///POP : Pop a Segment Register from the Stack
//segment register CS, DS, ES, SS 000 sreg2 111
IEncode pop_sreg2(char sreg2)
{
    _IENCODE(0,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0,0,0,0x0,sreg2,0x7); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//segment register FS, GS 0000 1111: 10 sreg3 001
IEncode pop_sreg3(char sreg3)
{
    _IENCODE(1,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0,0,0x2,sreg3,0x1); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///POPA/POPAD : Pop All General Registers 0110 0001
IEncode popa()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x61,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///POPF/POPFD : Pop Stack into FLAGS or EFLAGS Register 1001 1101
IEncode popf()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x9D,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///PUSH : Push Operand onto the Stack
//register 1111 1111 : 11 110 reg
IEncode push_r(char reg)
{
    _IENCODE(1,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xFF,0,0,0x3,0x6,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register (alternate encoding) 01 010 reg
IEncode push_r_alt(char reg)
{
    _IENCODE(0,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0,0,0,0x1,0x2,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory 1111 1111 : mod 110 r/m
IEncode push_m(char mod, char rm)
{
    _IENCODE(1,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xFF,0,0,mod,0x6,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//immediate 0110 10s0 : immediate data
IEncode push_i(char s, int imm, int n_byte)
{
    _IENCODE(1,0,0,1,0,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x68,0,0,s,0,0,0,0,0,imm,n_byte);
	_END_IENCODE;
}

///PUSH : Push Segment Register onto the Stack
//segment register CS,DS,ES,SS = 00 0 sreg2 110
IEncode push_sreg2(char sreg2)
{
    _IENCODE(0,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0,0,0,0x0,sreg2,0x6); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//segment register FS,GS = 0000 1111: 10 sreg3 000
IEncode push_sreg3(char sreg3)
{
    _IENCODE(1,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0,0,0x2,sreg3,0x0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///PUSHA/PUSHAD : Push All General Registers = 0110 0000
IEncode pusha()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x60,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///PUSHF/PUSHFD : Push Flags Register onto the Stack = 1001 1100
IEncode pushf()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x9C,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///RCL : Rotate thru Carry Left
//register by 1 = 1101 000w : 11 010 reg
IEncode rcl_r_1(char w, char reg)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD0,0,w,0x3,0x2,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory by 1 = 1101 000w : mod 010 r/m
IEncode rcl_m_1(char w, char mod, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD0,0,w,mod,0x2,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register by CL = 1101 001w : 11 010 reg
IEncode rcl_r_cl(char w, char reg)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD2,0,w,0x3,0x2,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory by CL = 1101 001w : mod 010 r/m
IEncode rcl_m_cl(char w, char mod, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD2,0,w,mod,0x2,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register by immediate count = 1100 000w : 11 010 reg : imm8 data
IEncode rcl_r_i(char w, char reg, char imm8)
{
    _IENCODE(1,0,1,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xC0,0,w,0,0x3,0x2,reg,0,0,imm8,1);
	_END_IENCODE;
}

//memory by immediate count = 1100 000w : mod 010 r/m : imm8 data
IEncode rcl_m_i(char w, char mod, char rm, char imm8)
{
    _IENCODE(1,0,1,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xC0,0,w,0,mod,0x2,rm,0,0,imm8,1);
	_END_IENCODE;
}

///RCR : Rotate thru Carry Right
//register by 1 = 1101 000w : 11 011 reg
IEncode rcr_r_1(char w, char reg)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD0,0,w,0x3,0x3,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory by 1 = 1101 000w : mod 011 r/m
IEncode rcr_m_1(char w, char mod, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD2,0,w,mod,0x3,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register by CL = 1101 001w : 11 011 reg
IEncode rcr_r_cl(char w, char reg)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD2,0,w,0x3,0x3,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory by CL = 1101 001w : mod 011 r/m
IEncode rcr_m_cl(char w, char mod, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD2,0,w,mod,0x3,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register by immediate count = 1100 000w : 11 011 reg : imm8 data
IEncode rcr_r_i(char w, char reg, char imm8)
{
    _IENCODE(1,0,1,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xC0,0,w,0,0x3,0x3,reg,0,0,imm8,1);
	_END_IENCODE;
}

//memory by immediate count = 1100 000w : mod 011 r/m : imm8 data
IEncode rcr_m_i(char w, char mod, char rm, char imm8)
{
    _IENCODE(1,0,1,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xC0,0,w,0,mod,0x3,rm,0,0,imm8,1);
	_END_IENCODE;
}

///RDMSR : Read from Model-Specific Register 0000 1111 : 0011 0010
IEncode rdmsr()
{
    _IENCODE(1,1,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x32,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///RDPMC : Read Performance Monitoring Counters 0000 1111 : 0011 0011
IEncode rdpmc()
{
    _IENCODE(1,1,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x33,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///RDTSC : Read Time-Stamp Counter 0000 1111 : 0011 0001
IEncode rdtsc()
{
    _IENCODE(1,1,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x31,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///REP INS : Input String 1111 0011 : 0110 110w
IEncode rep_ins(char w)
{
    _IENCODE(1,1,1,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xF3,0x6C,w,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///REP LODS : Load String 1111 0011 : 1010 110w
IEncode rep_lods(char w)
{
    _IENCODE(1,1,1,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xF3,0xAC,w,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///REP MOVS : Move String 1111 0011 : 1010 010w
IEncode rep_movs(char w)
{
    _IENCODE(1,1,1,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xF3,0xA4,w,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///REP OUTS : Output String 1111 0011 : 0110 111w
IEncode rep_outs(char w)
{
    _IENCODE(1,1,1,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xF3,0x6E,w,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///REP STOS : Store String 1111 0011 : 1010 101w
IEncode rep_stos(char w)
{
    _IENCODE(1,1,1,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xF3,0xAA,w,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///REPE CMPS : Compare String 1111 0011 : 1010 011w
IEncode repe_cmps(char w)
{
    _IENCODE(1,1,1,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xF3,0xA6,w,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///REPE SCAS : Scan String 1111 0011 : 1010 111w
IEncode repe_scas(char w)
{
    _IENCODE(1,1,1,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xF3,0xAE,w,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///REPNE CMPS : Compare String 1111 0010 : 1010 011w
IEncode repne_cmps(char w)
{
    _IENCODE(1,1,1,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xF2,0xA6,w,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///REPNE SCAS : Scan String 1111 0010 : 1010 111w
IEncode repne_scas(char w)
{
    _IENCODE(1,1,1,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xF2,0xAE,w,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///RET : Return from Procedure (to same segment)
//no argument 1100 0011
IEncode ret_ss()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xC3,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//adding immediate to SP 1100 0010 : 16-bit displacement
IEncode ret_ss(int disp16)
{
    _IENCODE(1,0,0,0,0,0,1,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xC2,0,0,0,0,0,0,disp16,2,0,0);
	_END_IENCODE;
}

///RET : Return from Procedure (to other segment)
//intersegment 1100 1011
IEncode ret_os()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xCB,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//adding immediate to SP 1100 1010 : 16-bit displacement
IEncode ret_os(int disp16)
{
    _IENCODE(1,0,0,0,0,0,1,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xCA,0,0,0,0,0,0,disp16,2,0,0);
	_END_IENCODE;
}

///ROL : Rotate Left
//register by 1 = 1101 000w : 11 000 reg
IEncode rol_r_1(char w, char reg)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD0,0,w,0x3,0x0,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory by 1 = 1101 000w : mod 000 r/m
IEncode rol_m_1(char w, char mod, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD0,0,w,mod,0x0,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register by CL = 1101 001w : 11 000 reg
IEncode rol_r_cl(char w, char reg)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD2,0,w,0x3,0x0,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory by CL = 1101 001w : mod 000 r/m
IEncode rol_m_cl(char w, char mod, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD2,0,w,mod,0x0,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register by immediate count = 1100 000w : 11 000 reg : imm8 data
IEncode rol_r_i(char w, char reg, char imm8)
{
    _IENCODE(1,0,1,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xC0,0,w,0,0x3,0x0,reg,0,0,imm8,1);
	_END_IENCODE;
}

//memory by immediate count = 1100 000w : mod 000 r/m : imm8 data
IEncode rol_m_i(char w, char mod, char rm, char imm8)
{
    _IENCODE(1,0,1,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xC0,0,w,0,mod,0x0,rm,0,0,imm8,1);
	_END_IENCODE;
}

///ROR : Rotate Right
//register by 1 = 1101 000w : 11 001 reg
IEncode ror_r_1(char w, char reg)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD0,0,w,0x3,0x1,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory by 1 = 1101 000w : mod 001 r/m
IEncode ror_m_1(char w, char mod, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD0,0,w,mod,0x1,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register by CL = 1101 001w : 11 001 reg
IEncode ror_r_cl(char w, char reg)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD2,0,w,0x3,0x1,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}
//memory by CL = 1101 001w : mod 001 r/m
IEncode ror_m_cl(char w, char mod, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD2,0,w,mod,0x1,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register by immediate count = 1100 000w : 11 001 reg : imm8 data
IEncode ror_r_i(char w, char reg, char imm8)
{
    _IENCODE(1,0,1,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xC0,0,w,0,0x3,0x1,reg,0,0,imm8,1);
	_END_IENCODE;
}

//memory by immediate count = 1100 000w : mod 001 r/m : imm8 data
IEncode ror_m_i(char w, char mod, char rm, char imm8)
{
    _IENCODE(1,0,1,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xC0,0,w,0,mod,0x1,rm,0,0,imm8,1);
	_END_IENCODE;
}

///RSM : Resume from System Management Mode 0000 1111 : 1010 1010
IEncode rsm()
{
    _IENCODE(1,1,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xAA,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///SAHF : Store AH into Flags 1001 1110
IEncode sahf()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x9E,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///SAR : Shift Arithmetic Right
//register by 1 = 1101 000w : 11 111 reg
IEncode sar_r_1(char w, char reg)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD0,0,w,0x3,0x7,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory by 1 = 1101 000w : mod 111 r/m
IEncode sar_m_1(char w, char mod, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD0,0,w,mod,0x7,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register by CL = 1101 001w : 11 111 reg
IEncode sar_r_cl(char w, char reg)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD2,0,w,0x3,0x7,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory by CL = 1101 001w : mod 111 r/m
IEncode sar_m_cl(char w, char mod, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD2,0,w,mod,0x7,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register by immediate count = 1100 000w : 11 111 reg : imm8 data
IEncode sar_r_i(char w, char reg, char imm8)
{
    _IENCODE(1,0,1,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xC0,0,w,0,0x3,0x7,reg,0,0,imm8,1);
	_END_IENCODE;
}

//memory by immediate count = 1100 000w : mod 111 r/m : imm8 data
IEncode sar_m_i(char w, char mod, char rm, char imm8)
{
    _IENCODE(1,0,1,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xC0,0,w,0,mod,0x7,rm,0,0,imm8,1);
	_END_IENCODE;
}

///SBB : Integer Subtraction with Borrow
//register1 to register2 = 0001 100w : 11 reg1 reg2
IEncode sbb_r1_r2(char w, char reg1, char reg2)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x18,0,w,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register2 to register1 = 0001 101w : 11 reg1 reg2
IEncode sbb_r2_r1(char w, char reg1, char reg2)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x1A,0,w,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory to register = 0001 101w : mod reg r/m
IEncode sbb_m_r(char w, char mod, char reg, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x1A,0,w,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register to memory = 0001 100w : mod reg r/m
IEncode sbb_r_m(char w, char mod, char reg, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x18,0,w,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}
//immediate to register = 1000 00sw : 11 011 reg : immediate data
IEncode sbb_i_r(char s, char w, char reg, int imm, int n_byte)
{
    _IENCODE(1,0,1,1,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x80,0,w,s,0x3,0x3,reg,0,0,imm,n_byte);
	_END_IENCODE;
}

//immediate to AL, AX, or EAX = 0001 110w : immediate data
IEncode sbb_i_ra(char w, int imm, int n_byte)
{
    _IENCODE(1,0,1,0,0,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x1C,0,w,0,0,0,0,0,0,imm,n_byte);
	_END_IENCODE;
}

//immediate to memory = 1000 00sw : mod 011 r/m : immediate data
IEncode sbb_i_m(char s, char w, char mod, char rm, int imm, int n_byte)
{
    _IENCODE(1,0,1,1,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x80,0,w,s,mod,0x3,rm,0,0,imm,n_byte);
	_END_IENCODE;
}

///SCAS/SCASB/SCASW/SCASD : Scan String = 1101 111w
IEncode scas(char w)
{
    _IENCODE(1,0,1,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xDE,0,w,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///SETcc : Byte Set on Condition
//register 0000 1111 : 1001 tttn : 11 000 reg
IEncode setc_r(char tttn, char reg)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,1); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x90,0,0x3,0x0,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_SET_TTTN(tttn);
	_END_IENCODE;
}

//memory 0000 1111 : 1001 tttn : mod 000 r/m
IEncode setc_m(char tttn, char mod, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,1); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x90,0,mod,0x0,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_SET_TTTN(tttn);
	_END_IENCODE;
}

///SGDT : Store Global Descriptor Table Register = 0000 1111 : 0000 0001 : mod 000 r/m
IEncode sgdt(char mod, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x01,0,mod,0x0,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///SHL : Shift Left
//register by 1 = 1101 000w : 11 100 reg
IEncode shl_r_1(char w, char reg)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD0,0,w,0x3,0x4,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory by 1 = 1101 000w : mod 100 r/m
IEncode shl_m_1(char w, char mod, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD0,0,w,mod,0x4,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register by CL = 1101 001w : 11 100 reg
IEncode shl_r_cl(char w, char reg)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD2,0,w,0x3,0x4,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory by CL = 1101 001w : mod 100 r/m
IEncode shl_m_cl(char w, char mod, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD2,0,w,mod,0x4,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register by immediate count = 1100 000w : 11 100 reg : imm8 data
IEncode shl_r_i(char w, char reg, char imm8)
{
    _IENCODE(1,0,1,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xC0,0,w,0,0x3,0x4,reg,0,0,imm8,1);
	_END_IENCODE;
}

//memory by immediate count = 1100 000w : mod 100 r/m : imm8 data
IEncode shl_m_i(char w, char mod, char rm, char imm8)
{
    _IENCODE(1,0,1,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xC0,0,w,0,mod,0x4,rm,0,0,imm8,1);
	_END_IENCODE;
}

///SHLD : Double Precision Shift Left
//register by immediate count = 0000 1111 : 1010 0100 : 11 reg2 reg1 : imm8
IEncode shld_r_i(char reg2, char reg1, char imm8)
{
    _IENCODE(1,1,0,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x0F,0xA4,0,0,0x3,reg2,reg1,0,0,imm8,1);
	_END_IENCODE;
}

//memory by immediate count = 0000 1111 : 1010 0100 : mod reg r/m : imm8
IEncode shld_m_i(char mod, char reg, char rm, char imm8)
{
    _IENCODE(1,1,0,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x0F,0xA4,0,0,mod,reg,rm,0,0,imm8,1);
	_END_IENCODE;
}

//register by CL = 0000 1111 : 1010 0101 : 11 reg2 reg1
IEncode shld_r_cl(char reg2, char reg1)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xA5,0,0x3,reg2,reg1); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory by CL = 0000 1111 : 1010 0101 : mod reg r/m
IEncode shld_m_cl(char mod, char reg, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xA5,0,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///SHR : Shift Right
//register by 1 = 1101 000w : 11 101 reg
IEncode shr_r_1(char w, char reg)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD0,0,w,0x3,0x5,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory by 1 = 1101 000w : mod 101 r/m
IEncode shr_m_1(char w, char mod, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD0,0,w,mod,0x5,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register by CL = 1101 001w : 11 101 reg
IEncode shr_r_cl(char w, char reg)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD2,0,w,0x3,0x5,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory by CL = 1101 001w : mod 101 r/m
IEncode shr_m_cl(char w, char mod, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD2,0,w,mod,0x5,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register by immediate count = 1100 000w : 11 101 reg : imm8 data
IEncode shr_r_i(char w, char reg, char imm8)
{
    _IENCODE(1,0,1,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xC0,0,w,0,0x3,0x5,reg,0,0,imm8,1);
	_END_IENCODE;
}

//memory by immediate count = 1100 000w : mod 101 r/m : imm8 data
IEncode shr_m_i(char w, char mod, char rm, char imm8)
{
    _IENCODE(1,0,1,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xC0,0,w,0,mod,0x5,rm,0,0,imm8,1);
	_END_IENCODE;
}

///SHRD : Double Precision Shift Right
//register by immediate count = 0000 1111 : 1010 1100 : 11 reg2 reg1 : imm8
IEncode shrd_r_i(char reg2, char reg1, char imm8)
{
    _IENCODE(1,1,0,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x0F,0xAC,0,0,0x3,reg2,reg1,0,0,imm8,1);
	_END_IENCODE;
}

//memory by immediate count = 0000 1111 : 1010 1100 : mod reg r/m : imm8
IEncode shrd_m_i(char mod, char reg, char rm, char imm8)
{
    _IENCODE(1,1,0,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x0F,0xAC,0,0,mod,reg,rm,0,0,imm8,1);
	_END_IENCODE;
}

//register by CL = 0000 1111 : 1010 1101 : 11 reg2 reg1
IEncode shrd_r_cl(char reg2, char reg1)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xAD,0,0x3,reg2,reg1); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory by CL = 0000 1111 : 1010 1101 : mod reg r/m
IEncode shrd_m_cl(char mod, char reg, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xAD,0,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///SIDT : Store Interrupt Descriptor Table Register = 0000 1111 : 0000 0001 : mod 001 r/m
IEncode sidt(char mod, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x01,0,mod,0x1,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///SLDT : Store Local Descriptor Table Register
//to register = 0000 1111 : 0000 0000 : 11 000 reg
IEncode sldt_r(char reg)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x00,0,0x3,0x0,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//to memory = 0000 1111 : 0000 0000 : mod 000 r/m
IEncode sldt_m(char mod, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x00,0,mod,0x0,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///SMSW : Store Machine Status Word
//to register = 0000 1111 : 0000 0001 : 11 100 reg
IEncode smsw_r(char reg)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x01,0,0x3,0x4,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//to memory = 0000 1111 : 0000 0001 : mod 100 r/m
IEncode smsw_m(char mod, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x01,0,mod,0x4,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///STC : Set Carry Flag = 1111 1001
IEncode stc()
{
    _IENCODE(1,1,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x01,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///STD : Set Direction Flag 1111 1101
IEncode stdf()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xFD,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///STI : Set Interrupt Flag = 1111 1011
IEncode sti()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xFB,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///STOS/STOSB/STOSW/STOSD : Store String Data = 1010 101w
IEncode stos(char w)
{
    _IENCODE(1,0,1,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xAA,0,w,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///STR : Store Task Register
//to register = 0000 1111 : 0000 0000 : 11 001 reg
IEncode str_r(char reg)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x00,0,0x3,0x1,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//to memory = 0000 1111 : 0000 0000 : mod 001 r/m
IEncode str_m(char mod, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x00,0,mod,0x1,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///SUB : Integer Subtraction
//register1 to register2 = 0010 100w : 11 reg1 reg2
IEncode sub_r1_r2(char w, char reg1, char reg2)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x28,0,w,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register2 to register1 = 0010 101w : 11 reg1 reg2
IEncode sub_r2_r1(char w, char reg1, char reg2)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x2A,0,w,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory to register = 0010 101w : mod reg r/m
IEncode sub_m_r(char w, char mod, char reg, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x2A,0,w,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register to memory = 0010 100w : mod reg r/m
IEncode sub_r_m(char w, char mod, char reg, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x28,0,w,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//immediate to register = 1000 00sw : 11 101 reg : immediate data
IEncode sub_i_r(char s, char w, char reg, int imm, int n_byte)
{
    _IENCODE(1,0,1,1,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x80,0,w,s,0x3,0x5,reg,0,0,imm,n_byte);
	_END_IENCODE;
}

//immediate to AL, AX, or EAX = 0010 110w : immediate data
IEncode sub_i_ra(char w, int imm, int n_byte)
{
    _IENCODE(1,0,1,0,0,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x2C,0,w,0,0,0,0,0,0,imm,n_byte);
	_END_IENCODE;
}

//immediate to memory = 1000 00sw : mod 101 r/m : immediate data
IEncode sub_i_m(char s, char w, char mod, char rm, int imm, int n_byte)
{
    _IENCODE(1,0,1,1,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x80,0,w,s,mod,0x5,rm,0,0,imm,n_byte);
	_END_IENCODE;
}

///TEST : Logical Compare
//register1 and register2 = 1000 010w : 11 reg1 reg2
IEncode test_r_r(char w, char reg1, char reg2)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x84,0,w,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory and register = 1000 010w : mod reg r/m
IEncode test_m_r(char w, char mod, char reg, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x84,0,w,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//immediate and register = 1111 011w : 11 000 reg : immediate data
IEncode test_i_r(char w, char reg, int imm, int n_byte)
{
    _IENCODE(1,0,1,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xF6,0,w,0,0x3,0x0,reg,0,0,imm,n_byte);
	_END_IENCODE;
}

//immediate and AL, AX, or EAX = 1010 100w : immediate data
IEncode test_i_ra(char w, int imm, int n_byte)
{
    _IENCODE(1,0,1,0,0,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xA8,0,w,0,0,0,0,0,0,imm,n_byte);
	_END_IENCODE;
}

//immediate and memory = 1111 011w : mod 000 r/m : immediate data
IEncode test_i_m(char w, char mod, char rm, int imm, int n_byte)
{
    _IENCODE(1,0,1,0,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0xF6,0,w,0,mod,0x0,rm,0,0,imm,n_byte);
	_END_IENCODE;
}


///UD2 : Undefined instruction 0000 FFFF : 0000 1011
IEncode ud2()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///VERR : Verify a Segment for Reading
//register = 0000 1111 : 0000 0000 : 11 100 reg
IEncode verr(char reg)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x00,0,0x3,0x4,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory = 0000 1111 : 0000 0000 : mod 100 r/m
IEncode verr(char mod, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x00,0,mod,0x4,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///VERW : Verify a Segment for Writing
//register = 0000 1111 : 0000 0000 : 11 101 reg
IEncode verw(char reg)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x00,0,0x3,0x5,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory = 0000 1111 : 0000 0000 : mod 101 r/m
IEncode verw(char mod, char rm)
{
    _IENCODE(1,1,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x00,0,mod,0x5,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///WAIT : Wait = 1001 1011
IEncode wait()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x9B,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}


///WBINVD : Writeback and Invalidate Data Cache = 0000 1111 : 0000 1001
IEncode wbinvd()
{
    _IENCODE(1,1,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x09,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///WRMSR : Write to Model-Specific Register = 0000 1111 : 0011 0000
IEncode wrmsr()
{
    _IENCODE(1,1,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0x30,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///XADD : Exchange and Add
//register1, register2 = 0000 1111 : 1100 000w : 11 reg2 reg1
IEncode xadd_r_r(char w, char reg1, char reg2)
{
    _IENCODE(1,1,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xC0,w,0x3,reg2,reg1); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory, reg = 0000 1111 : 1100 000w : mod reg r/m
IEncode xadd_m_r(char w, char mod, char reg, char rm)
{
    _IENCODE(1,1,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x0F,0xC0,w,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///XCHG : Exchange Register/Memory with Register
//register1 with register2 = 1000 011w : 11 reg1 reg2
IEncode xchg_r_r(char w, char reg1, char reg2)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x86,0,w,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//AL, AX, or EAX with reg = 10 010 reg
IEncode xchg_ra_r(char reg)
{
    _IENCODE(0,0,0,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0,0,0,0x2,0x2,reg); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory with reg = 1000 011w : mod reg r/m
IEncode xchg_m_r(char w, char mod, char reg, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x86,0,w,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///XLAT/XLATB : Table Look-up Translation = 1101 0111
IEncode xlat()
{
    _IENCODE(1,0,0,0,0,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0xD7,0,0,0,0,0); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

///XOR : Logical Exclusive OR
//register1 to register2 = 0011 000w : 11 reg1 reg2
IEncode xor_r1_r2(char w, char reg1, char reg2)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x30,0,w,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register2 to register1 = 0011 001w : 11 reg1 reg2
IEncode xor_r2_r1(char w, char reg1, char reg2)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x32,0,w,0x3,reg1,reg2); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//memory to register = 0011 001w : mod reg r/m
IEncode xor_m_r(char w, char mod, char reg, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x32,0,w,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//register to memory = 0011 000w : mod reg r/m
IEncode xor_r_m(char w, char mod, char reg, char rm)
{
    _IENCODE(1,0,1,0,1,0,0,0,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	_SET_IENCODE(0x30,0,w,mod,reg,rm); //_SET_IENCODE(_op1, _op2, _wbit, _mod, _reg, _rm)
	_END_IENCODE;
}

//immediate to register = 1000 00sw : 11 110 reg : immediate data
IEncode xor_i_r(char s, char w, char reg, int imm, int n_byte)
{
    _IENCODE(1,0,1,1,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x80,0,w,s,0x3,0x6,reg,0,0,imm,n_byte);
	_END_IENCODE;
}

//immediate to AL, AX, or EAX = 0011 010w : immediate data
IEncode xor_i_ra(char w, int imm, int n_byte)
{
    _IENCODE(1,0,1,0,0,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x34,0,w,0,0,0,0,0,0,imm,n_byte);
	_END_IENCODE;
}

//immediate to memory = 1000 00sw : mod 110 r/m : immediate data
IEncode xor_i_m(char s, char w, char mod, char rm, int imm, int n_byte)
{
    _IENCODE(1,0,1,1,1,0,0,1,0,0); //_IENCODE(_op1, _op2, _wbit, _sbit, _modrm, _sib, _dispb, _immb, _dbit, _tttn)
	//_SET_FULL_IENCODE(_op1, _op2, _wbit, _sbit, _mod, _reg, _rm, _disp, _n_disp_byte, _imm, _n_imm_byte)
	_SET_FULL_IENCODE(0x80,0,w,s,mod,0x6,rm,0,0,imm,n_byte);
	_END_IENCODE;
}


/**************************
* UTIL
**************************/
void printHex(char ch)
{
	char tmp = (ch&0xF0)>>4;
	cout << hex << (int)tmp;

	tmp = ch&0x0F;
	cout << hex << (int)tmp;
}

void printHex(int i32, int n_byte, char invert)
{
	if(invert){
        char *tmp = (char*)(&i32);
	    for(int i = 0; i<n_byte; i++){
            printHex(tmp[i]);
            cout << ' ';
	    }
	}else{
	    char *tmp = (char*)(&i32);
	    for(int i = n_byte-1; i>=0; i--) {
            printHex(tmp[i]);
            cout << ' ';
	    }
	}
}

void printModRM(ModRM modrm)
{
	char tmp = (modrm.mod << 6) | (modrm.reg << 3) | (modrm.rm);
	printHex(tmp);
}

void print(IEncode ie)
{
	if(ie.op1.p) {
		char op = ie.op1.op;
		if(ie.sbit.p && !ie.op2.p)
			op = op | ie.sbit.s <<1;
		if(ie.wbit.p && !ie.op2.p)
			op = op | ie.wbit.w;
        if(ie.cond.p && !ie.op2.p)
            op = op | ie.cond.tttn;
		printHex(op);
	}

	if(ie.op2.p) {
	    cout << ' ';
	    char op = ie.op2.op;
	    if(ie.sbit.p)
			op = op | ie.sbit.s <<1;
		if(ie.wbit.p)
			op = op | ie.wbit.w;
        if(ie.cond.p)
            op = op | ie.cond.tttn;
		printHex(op);
	}

	if(ie.modrm.p) {
	    cout << ' ';
		printModRM(ie.modrm);
	}

	if(ie.immb.p) {
	    cout << ' ';
		printHex(ie.immb.imm, ie.immb.n_byte, 1);
	}
}


void writeModRM(ofstream &o, ModRM &modrm)
{
    char tmp = (modrm.mod << 6) | (modrm.reg << 3) | (modrm.rm);
	o.put(tmp);
}

void writeBytes(ofstream &o, int i32, int n_byte, char invert)
{
    if(invert){
        char *tmp = (char*)(&i32);
	    for(int i = 0; i<n_byte; i++){
            o.put(tmp[i]);
	    }
	}else{
	    char *tmp = (char*)(&i32);
	    for(int i = n_byte-1; i>=0; i--) {
            o.put(tmp[i]);
	    }
	}

}

void write(ofstream &o, IEncode &ie)
{
    if(ie.op1.p) {
		char op = ie.op1.op;
		if(ie.sbit.p && !ie.op2.p)
			op = op | ie.sbit.s <<1;
		if(ie.wbit.p && !ie.op2.p)
			op = op | ie.wbit.w;
        if(ie.cond.p && !ie.op2.p)
            op = op | ie.cond.tttn;
		o.put(op);
	}

	if(ie.op2.p) {
	    char op = ie.op2.op;
	    if(ie.sbit.p)
			op = op | ie.sbit.s <<1;
		if(ie.wbit.p)
			op = op | ie.wbit.w;
        if(ie.cond.p)
            op = op | ie.cond.tttn;
		o.put(op);
	}

	if(ie.modrm.p) {
		writeModRM(o,ie.modrm);
	}

	if(ie.immb.p) {
		writeBytes(o, ie.immb.imm, ie.immb.n_byte, 1);
	}
}
