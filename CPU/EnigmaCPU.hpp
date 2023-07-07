/*
Copyright (c) 2023 MegrajChauhan

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef E_CPU
#define E_CPU

#include "../ememory.hpp"
#include "../imemory.hpp"
#include "../OS.hpp"

namespace CPU
{
    // all of these registers accept regsp, regbp, regpc can be used for anything
    enum Register : qword
    {
        rega,
        regb,
        regc,
        regd,
        rege,
        regf,
        reg1,
        reg2,
        reg3,
        reg4,
        reg5,
        reg6,
        regsp,
        regbp,
        regpc,
        REGR_COUNT
    };

    enum Flags : byte
    {
        ZERO,
        EQUAL,
        GREATER,
        SMALLER,
        NEGATIVE,
        FLAG_COUNT,
    };

    enum Instructions : byte
    {
        NOP,
        ADD, // for arithmetic operations
        SUB,
        MUL,
        DIV,
        INC,
        DEC,
        AND, // logical operations
        OR,
        NOT,
        XOR,
        LSHIFT,    // shift left by specified bits
        RSHIFT,    // shift right by specified bits
        MOV,       // move values from other registers or an immediate value to the destination register
        LOAD,      // load values at specific address to the destination register
        LEA,       // load the address instead of the value into the register
        SWAP,      // swap the values of two registers with each other
        STORE,     // take the register value and then save it to the given address
        PUSH,      // push all of the registers to the stack in a specified order
        POP,       // do the opposite of push
        PUSH_REGR, // push just the specified register to the stack
        POP_REGR,  // pop the top of stack to the specified register
        PUSH_VAL,  // push a value to the top of stack
        POP_VAL,   // pop a value from the top of stack. If the program needs that value popr should be used instead
        CMP,       // comparisons
        JMP,       // jmp to certain location in the main_memory
        JZ,        // jump if zero
        JNZ,       // jump not zero
        JG,        // jump if greater than
        JGE,       // jump if greater or equal
        JL,        // jump if less than
        JLE,       // jump if less than or equal
        JN,        // jump if negative
        JNN,       // jump if not negative
        JE,        // jump if equal
        JNE,       // jump if not equal
        MOVZ,      // move if zero
        MOVNZ,     // move if not zero
        MOVG,      // move if greater
        MOVGE,     // move if greater or equal
        MOVL,      // move if less
        MOVLE,     // move if less than or equal
        MOVN,      // move if negative
        MOVNN,     // move if not negative
        MOVE,      // move if equal
        MOVNE,     // move if not equal
        SYSCALL,
        HALT,
        // since the instructions take up a whole byte, we can have upto 255 instructions! But because of how things work, we can only have 99 not more.
    };

    qword _e_registers[REGR_COUNT];
    byte _f_register[FLAG_COUNT];
    static Imem instr_memory;  // the instruction memory[it's size can only be increased by the OS]
    static Memory data_memory; // the data memory[it's size is changeable by the user]
    static Memory stack;
    static Memory IObuffer; // this is also changeable but by only the OS

    static qword __current_memory_input;
    static byte __current_instruction;

    static bool running = true;

    void init();

    void fetch();
    void decode();

    void execute();
    void run();
};

void CPU::init()
{
    instr_memory.init(1024);
    data_memory.init(1024, true);
    stack.init(512, false);
    _e_registers[regsp] = 0;
    _e_registers[regpc] = 0;
}

void CPU::fetch()
{
    __current_memory_input = instr_memory.i_read(_e_registers[regpc]);
}

void CPU::decode()
{
    __current_instruction = (__current_memory_input >> 56);
}

#include "EnigmaInstruction.hpp"

void CPU::execute()
{
    switch (__current_instruction)
    {
    case NOP:
        break;
    case ADD:
        Add();
        break;
    case SUB:
        Sub();
        break;
    case MUL:
        Mul();
        break;
    case DIV:
        Div();
        break;
    case INC:
        Inc();
        break;
    case DEC:
        Dec();
        break;
    case AND:
        And();
        break;
    case OR:
        Or();
        break;
    case NOT:
        Not();
        break;
    case XOR:
        Xor();
        break;
    case LSHIFT:
        lshift();
        break;
    case RSHIFT:
        rshift();
        break;
    case MOV:
        Mov();
        break;
    case LOAD:
        Load();
        break;
    case LEA:
        Lea();
        break;
    case SWAP:
        Swap();
        break;
    case STORE:
        Store();
        break;
    case PUSH:
        Push();
        break;
    case POP:
        Pop();
        break;
    case PUSH_REGR:
        Pushr();
        break;
    case POP_REGR:
        Popr();
        break;
    case PUSH_VAL:
        Pushv();
        break;
    case POP_VAL:
        Popv();
        break;
    case CMP:
        Cmp();
        break;
    case JMP:
        Jmp();
        break;
    case JZ:
        Jz();
        break;
    case JNZ:
        Jnz();
        break;
    case JG:
        Jg();
        break;
    case JGE:
        Jge();
        break;
    case JL:
        Js();
        break;
    case JLE:
        Jse();
        break;
    case JN:
        Jn();
        break;
    case JNN:
        Jnn();
        break;
    case JE:
        Je();
        break;
    case JNE:
        Jne();
        break;
    case MOVZ:
        Movz();
        break;
    case MOVNZ:
        Movnz();
        break;
    case MOVG:
        Movg();
        break;
    case MOVGE:
        Movge();
        break;
    case MOVL:
        Movs();
        break;
    case MOVLE:
        Movse();
        break;
    case MOVN:
        Movn();
        break;
    case MOVNN:
        Movnn();
        break;
    case MOVE:
        Move();
        break;
    case MOVNE:
        Movne();
        break;
    case HALT:
        running = false;
        break;
    default:
        std::cerr << "Unknown Instructions. Bad Instruction[Terminating Execution]" << std::endl;
        _e_registers[rega] = -1;
        running = false;
    }
}

void CPU::run()
{
    while (running)
    {
        fetch();
        decode();
        execute();
        _e_registers[regpc]++;
    }
    std::cout << _e_registers[regb] << std::endl;
}

#endif