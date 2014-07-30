/****************************************************/
/* File: i386encode.h                               */
/* ROCHA, Rodrigo Caetano de Oliveira			    */
/* rcor                                             */
/****************************************************/
#ifndef _I386ENCODER_H_
#define _I386ENCODER_H_

#include "i386encode.h"
#include "i386reg.h"

#define BIT_8       0
#define BIT_16      1
#define BIT_32      2

#define OPT_NONE    0
#define OPT_REG     1
#define OPT_IMM     2
#define OPT_DISP    3
#define OPT_LABEL   4

#define OP_NONE     0
#define OP_EAX      1
#define OP_EBX      2
#define OP_ECX      3
#define OP_EDX      4
#define OP_AX       5
#define OP_BX       6
#define OP_CX       7
#define OP_DX       8
#define OP_AL       9
#define OP_BL       10
#define OP_CL       11
#define OP_DL       12
#define OP_AH       13
#define OP_BH       14
#define OP_CH       15
#define OP_DH       16

#define I_NONE 0
#define I_AAA 1
#define I_AAD 2
#define I_AAM 3
#define I_AAS 4
#define I_ADC 5
#define I_ADD 6

#define _ISNONE(_operand_) (_operand_.type==OPT_NONE)
#define _ISREG(_operand_) (_operand_.type==OPT_REG)
#define _ISIMM(_operand_) (_operand_.type==OPT_IMM)

#define _REG(_operand_) (_operand_.op)
#define _IMM(_operand_) (_operand_.op)
#define _IMMSIZE(_operand_) (_operand_.n_byte)
/*
#define LABEL_LEN 64
typedef struct {
    int     nline;
    char    label[LABEL_LEN];
} LABEL;
*/

typedef struct {
    char    type;
    int     op;
    int     n_byte;
} OPERAND;

char _bits = BIT_16;

void set_bits(char bit);
char get_bits();

OPERAND op_none();
OPERAND op_reg(int reg);
OPERAND op_imm(int imm, int n_byte=sizeof(int));

IEncode instruction(int inst);
IEncode instruction(int inst, OPERAND op1);
IEncode instruction(int inst, OPERAND op1, OPERAND op2);

char getreg(int reg);

void set_bits(char bit)
{
    _bits = bit;
}

char get_bits()
{
    return _bits;
}

OPERAND op_none()
{
    OPERAND op;
    op.type = OPT_NONE;
    return op;
}

OPERAND op_reg(int reg)
{
    OPERAND op;
    op.type = OPT_REG;
    op.op = reg;
    return op;
}

OPERAND op_imm(int imm, int n_byte)
{
    OPERAND op;
    op.type = OPT_IMM;
    op.op = imm;
    op.n_byte = n_byte;
    return op;
}

IEncode instruction(int inst)
{
    return instruction(inst, op_none(), op_none());
}

IEncode instruction(int inst, OPERAND op1)
{
    return instruction(inst, op1, op_none());
}

IEncode instruction(int inst, OPERAND op1, OPERAND op2)
{
    IEncode ie;

    char w = 0;
    char s = 0;

    if( _ISREG(op1) ) {
        if(_REG(op1)>=OP_EAX && _REG(op1)<=OP_DX)
            w = 1;
        else if(_REG(op1)>=OP_AL && _REG(op1)<=OP_DH)
            w = 0;
    }

    switch(inst){
        case I_AAA:
            ie = aaa();
            break;
        case I_AAD:
            ie = aad();
            break;
        case I_AAM:
            ie = aam();
            break;
        case I_AAS:
            ie = aas();
            break;
        case I_ADC:
            if( _ISREG(op1) ) {
                if( _ISREG(op2) ) {
                    ie = adc_r1_r2(w, getreg(_REG(op2)), getreg(_REG(op1)));
                }else if( _ISIMM(op2) ) {
                    if(_REG(op1)==OP_AL || _REG(op1)==OP_AX || _REG(op1)==OP_EAX )
                        ie = adc_i_ra(w, _IMM(op2), _IMMSIZE(op2));
                    else
                        ie = adc_i_r(s, w, getreg(_REG(op1)), _IMM(op2), _IMMSIZE(op2));
                } //else if op2 is memory
                /*
                    ADC : ADD with Carry
                    memory to register 0001 001w : mod reg r/m
                    register to memory 0001 000w : mod reg r/m
                    immediate to memory 1000 00sw : mod 010 r/m : immediate data
                */
            }
            break;
        case I_ADD:
            if( _ISREG(op1) ) {
                if( _ISREG(op2) ) {
                    ie = add_r1_r2(w, getreg(_REG(op2)), getreg(_REG(op1)));
                }else if( _ISIMM(op2) ) {
                    if(_REG(op1)==OP_AL || _REG(op1)==OP_AX || _REG(op1)==OP_EAX )
                        ie = add_i_ra(w, _IMM(op2), _IMMSIZE(op2));
                    else
                        ie = add_i_r(s, w, getreg(_REG(op1)), _IMM(op2), _IMMSIZE(op2));
                } //else if op2 is memory
                /*
                    ADC : ADD with Carry
                    memory to register 0001 001w : mod reg r/m
                    register to memory 0001 000w : mod reg r/m
                    immediate to memory 1000 00sw : mod 010 r/m : immediate data
                */
            }
            break;
    }
    return ie;
}

char getreg(int reg)
{
    char creg;
    switch(reg){
        case OP_EAX:
            creg = REG_EAX;
            break;
        case OP_EBX:
            creg = REG_EBX;
            break;
        case OP_ECX:
            creg = REG_ECX;
            break;
        case OP_EDX:
            creg = REG_EDX;
            break;
        case OP_AX:
            creg = REG_AX;
            break;
        case OP_BX:
            creg = REG_BX;
            break;
        case OP_CX:
            creg = REG_CX;
            break;
        case OP_DX:
            creg = REG_DX;
            break;

        case OP_AL:
            creg = REG_AL;
            break;
        case OP_BL:
            creg = REG_BL;
            break;
        case OP_CL:
            creg = REG_CL;
            break;
        case OP_DL:
            creg = REG_DL;
            break;

        case OP_AH:
            creg = REG_AH;
            break;
        case OP_BH:
            creg = REG_BH;
            break;
        case OP_CH:
            creg = REG_CH;
            break;
        case OP_DH:
            creg = REG_DH;
            break;

        default:
            break;
    }
    return creg;
}

#endif
