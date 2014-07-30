/****************************************************/
/* File: main.cpp                                   */
/* ROCHA, Rodrigo Caetano de Oliveira			       */
/* rcor                                             */
/****************************************************/
#include <iostream>
using namespace std;

#include "i386encoder.h"

int main()
{
    IEncode ie;

    ie = instruction(I_ADD, op_reg(OP_EBX), op_reg(OP_ECX));
    print(ie);
    cout << endl;

    ie = instruction(I_ADD, op_reg(OP_BX), op_reg(OP_CX));
    print(ie);
    cout << endl;

    ie = instruction(I_ADD, op_reg(OP_BL), op_reg(OP_CL));
    print(ie);
    cout << endl;



    ie = instruction(I_ADD, op_reg(OP_AX), op_imm(0xFFFF, 2));
    print(ie);
    cout << endl;

    ie = instruction(I_ADD, op_reg(OP_BX), op_imm(0xFFFF, 2));
    print(ie);
    cout << endl;

    ie = instruction(I_ADD, op_reg(OP_AL), op_imm(0xFF, 1));
    print(ie);
    cout << endl;

    ie = instruction(I_ADD, op_reg(OP_BL), op_imm(0xFF, 1));
    print(ie);
    cout << endl;

    ie = instruction(I_ADD, op_reg(OP_ECX), op_imm(0xFFFF, 4));
    print(ie);
    cout << endl;

    return 0;
}
