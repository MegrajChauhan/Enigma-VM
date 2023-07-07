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

#ifndef E_INSTRUCTIONS
#define E_INSTRUCTIONS

#include "EnigmaCPU.hpp"

/*
Many of these instructions are very very similar, about 99%, becuase they follow the same way of executing the instruction
*/

void Add()
{
    // 0xxxxxx7 8 xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx
    // bits 0 to 7 = instruction
    // bit 8 = instruction mode
    // 0 => register-register, 1 => register-immediate
    byte mode = ((CPU::__current_memory_input >> 55) & 1UL);
    switch (mode)
    {
    case 0:
    {
        // 0xxxxxx7 8 xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx dest = [xxxx] src = [xxxx]
        CPU::_e_registers[(CPU::__current_memory_input >> 3) & 15] += CPU::_e_registers[CPU::__current_memory_input & 15];
        if (CPU::_e_registers[(CPU::__current_memory_input >> 3) & 15] >> 63 == 1)
        {
            CPU::_f_register[CPU::NEGATIVE] = 1;
        }
        else
        {
            CPU::_f_register[CPU::NEGATIVE] = 0;
        }
        if (CPU::_e_registers[(CPU::__current_memory_input >> 3) & 15] == 0)
        {
            CPU::_f_register[CPU::ZERO] = 1;
        }
        else
        {
            CPU::_f_register[CPU::ZERO] = 0;
        }
        break;
    }
    case 1:
    {
        // 0xxxxxx7 8 src = [xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxx] dest = [xxxx]
        CPU::_e_registers[CPU::__current_memory_input & 15] += (CPU::__current_memory_input)&0x7FFFFFFFFFFFF;
        if (CPU::_e_registers[CPU::__current_memory_input & 15] >> 63 == 1)
        {
            CPU::_f_register[CPU::NEGATIVE] = 1;
        }
        else
        {
            CPU::_f_register[CPU::NEGATIVE] = 0;
        }
        if (CPU::_e_registers[CPU::__current_memory_input & 15] == 0)
        {
            CPU::_f_register[CPU::ZERO] = 1;
        }
        else
        {
            CPU::_f_register[CPU::ZERO] = 0;
        }
        break;
    }
    }
}

void Sub()
{
    // 0xxxxxx7 8 xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx
    // bits 0 to 7 = instruction
    // bit 8 = instruction mode
    // 0 => register-register, 1 => register-immediate
    byte mode = ((CPU::__current_memory_input >> 55) & 1UL);
    switch (mode)
    {
    case 0:
    {
        // 0xxxxxx7 8 xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx dest = [xxxx] src = [xxxx]
        CPU::_e_registers[(CPU::__current_memory_input >> 3) & 15] -= CPU::_e_registers[CPU::__current_memory_input & 15];
        if (CPU::_e_registers[(CPU::__current_memory_input >> 3) & 15] >> 63 == 1)
        {
            CPU::_f_register[CPU::NEGATIVE] = 1;
        }
        else
        {
            CPU::_f_register[CPU::NEGATIVE] = 0;
        }
        if (CPU::_e_registers[(CPU::__current_memory_input >> 3) & 15] == 0)
        {
            CPU::_f_register[CPU::ZERO] = 1;
        }
        else
        {
            CPU::_f_register[CPU::ZERO] = 0;
        }
        break;
    }
    case 1:
    {
        // 0xxxxxx7 8 src = [xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxx] dest = [xxxx]
        CPU::_e_registers[CPU::__current_memory_input & 15] -= (CPU::__current_memory_input)&0x7FFFFFFFFFFFF;
        if (CPU::_e_registers[CPU::__current_memory_input & 15] >> 63 == 1)
        {
            CPU::_f_register[CPU::NEGATIVE] = 1;
        }
        else
        {
            CPU::_f_register[CPU::NEGATIVE] = 0;
        }
        if (CPU::_e_registers[CPU::__current_memory_input & 15] == 0)
        {
            CPU::_f_register[CPU::ZERO] = 1;
        }
        else
        {
            CPU::_f_register[CPU::ZERO] = 0;
        }
        break;
    }
    }
}

void Mul()
{
    // 0xxxxxx7 8 xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx
    // bits 0 to 7 = instruction
    // bit 8 = instruction mode
    // 0 => register-register, 1 => register-immediate
    byte mode = ((CPU::__current_memory_input >> 55) & 1UL);
    switch (mode)
    {
    case 0:
    {
        // 0xxxxxx7 8 xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx dest = [xxxx] src = [xxxx]
        CPU::_e_registers[(CPU::__current_memory_input >> 3) & 15] *= CPU::_e_registers[CPU::__current_memory_input & 15];
        if (CPU::_e_registers[(CPU::__current_memory_input >> 3) & 15] >> 63 == 1)
        {
            CPU::_f_register[CPU::NEGATIVE] = 1;
        }
        else
        {
            CPU::_f_register[CPU::NEGATIVE] = 0;
        }
        if (CPU::_e_registers[(CPU::__current_memory_input >> 3) & 15] == 0)
        {
            CPU::_f_register[CPU::ZERO] = 1;
        }
        else
        {
            CPU::_f_register[CPU::ZERO] = 0;
        }
        break;
    }
    case 1:
    {
        // 0xxxxxx7 8 src = [xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxx] dest = [xxxx]
        CPU::_e_registers[CPU::__current_memory_input & 15] *= (CPU::__current_memory_input)&0x7FFFFFFFFFFFF;
        if (CPU::_e_registers[CPU::__current_memory_input & 15] >> 63 == 1)
        {
            CPU::_f_register[CPU::NEGATIVE] = 1;
        }
        else
        {
            CPU::_f_register[CPU::NEGATIVE] = 0;
        }
        if (CPU::_e_registers[CPU::__current_memory_input & 15] == 0)
        {
            CPU::_f_register[CPU::ZERO] = 1;
        }
        else
        {
            CPU::_f_register[CPU::ZERO] = 0;
        }
        break;
    }
    }
}

void Div()
{
    // 0xxxxxx7 8 xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx
    // bits 0 to 7 = instruction
    // bit 8 = instruction mode
    // 0 => register-register, 1 => register-immediate
    byte mode = ((CPU::__current_memory_input >> 55) & 1UL);
    switch (mode)
    {
    case 0:
    {
        // 0xxxxxx7 8 xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx dest = [xxxx] src = [xxxx]
        CPU::_e_registers[(CPU::__current_memory_input >> 3) & 15] /= CPU::_e_registers[CPU::__current_memory_input & 15];
        if (CPU::_e_registers[(CPU::__current_memory_input >> 3) & 15] >> 63 == 1)
        {
            CPU::_f_register[CPU::NEGATIVE] = 1;
        }
        else
        {
            CPU::_f_register[CPU::NEGATIVE] = 0;
        }
        if (CPU::_e_registers[(CPU::__current_memory_input >> 3) & 15] == 0)
        {
            CPU::_f_register[CPU::ZERO] = 1;
        }
        else
        {
            CPU::_f_register[CPU::ZERO] = 0;
        }
        break;
    }
    case 1:
    {
        // 0xxxxxx7 8 src = [xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxx] dest = [xxxx]
        CPU::_e_registers[CPU::__current_memory_input & 15] /= (CPU::__current_memory_input)&0x7FFFFFFFFFFFF;
        if (CPU::_e_registers[CPU::__current_memory_input & 15] >> 63 == 1)
        {
            CPU::_f_register[CPU::NEGATIVE] = 1;
        }
        else
        {
            CPU::_f_register[CPU::NEGATIVE] = 0;
        }
        if (CPU::_e_registers[CPU::__current_memory_input & 15] == 0)
        {
            CPU::_f_register[CPU::ZERO] = 1;
        }
        else
        {
            CPU::_f_register[CPU::ZERO] = 0;
        }
        break;
    }
    }
}

void Inc()
{
    // this only takes registers as operand
    CPU::_e_registers[CPU::__current_memory_input & 15]++; // this is it
}

void Dec()
{
    CPU::_e_registers[CPU::__current_memory_input & 15]--;
}

void And()
{
    // 0xxxxxx7 8 xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx
    // bits 0 to 7 = instruction
    // bit 8 = instruction mode
    // 0 => register-register, 1 => register-immediate
    byte mode = ((CPU::__current_memory_input >> 55) & 1UL);
    switch (mode)
    {
    case 0:
    {
        // 0xxxxxx7 8 xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx dest = [xxxx] src = [xxxx]
        CPU::_e_registers[(CPU::__current_memory_input >> 3) & 15] &= CPU::_e_registers[CPU::__current_memory_input & 15];
        break;
    }
    case 1:
    {
        // 0xxxxxx7 8 src = [xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxx] dest = [xxxx]
        CPU::_e_registers[CPU::__current_memory_input & 15] &= (CPU::__current_memory_input)&0x7FFFFFFFFFFFF;
        break;
    }
    }
}

void Or()
{
    // 0xxxxxx7 8 xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx
    // bits 0 to 7 = instruction
    // bit 8 = instruction mode
    // 0 => register-register, 1 => register-immediate
    byte mode = ((CPU::__current_memory_input >> 55) & 1UL);
    switch (mode)
    {
    case 0:
    {
        // 0xxxxxx7 8 xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx dest = [xxxx] src = [xxxx]
        CPU::_e_registers[(CPU::__current_memory_input >> 3) & 15] |= CPU::_e_registers[CPU::__current_memory_input & 15];
        break;
    }
    case 1:
    {
        // 0xxxxxx7 8 src = [xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxx] dest = [xxxx]
        CPU::_e_registers[CPU::__current_memory_input & 15] |= (CPU::__current_memory_input)&0x7FFFFFFFFFFFF;
        break;
    }
    }
}

void Not()
{
    // 0xxxxxx7 xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxx regr = [xxxx]
    // bits 0 to 7 = instruction
    // this only works on registers. We take the register's value, apply not and put it back
    CPU::_e_registers[CPU::__current_memory_input & 15] = ~CPU::_e_registers[CPU::__current_memory_input & 15];
}

void Xor()
{
    // 0xxxxxx7 8 xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx
    // bits 0 to 7 = instruction
    // bit 8 = instruction mode
    // 0 => register-register, 1 => register-immediate
    byte mode = ((CPU::__current_memory_input >> 55) & 1UL);
    switch (mode)
    {
    case 0:
    {
        // 0xxxxxx7 8 xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx dest = [xxxx] src = [xxxx]
        CPU::_e_registers[(CPU::__current_memory_input >> 3) & 15] ^= CPU::_e_registers[CPU::__current_memory_input & 15];
        break;
    }
    case 1:
    {
        // 0xxxxxx7 8 src = [xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxx] dest = [xxxx]
        CPU::_e_registers[CPU::__current_memory_input & 15] ^= (CPU::__current_memory_input)&0x7FFFFFFFFFFFF;
        break;
    }
    }
}

void lshift()
{
    // 0xxxxxx7 8 xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx
    // this instruction has formats as well
    // checks will be made for immediate value
    // if imm > 64 or < 0, the shift will not be performed and the program will continue
    // no errors will be displayed, the same is for the rshift as well
    byte mode = ((CPU::__current_memory_input >> 55) & 1UL);
    switch (mode)
    {
    case 0:
    {
        auto shift_by = CPU::_e_registers[CPU::__current_memory_input & 15];
        if (shift_by > 64 || shift_by < 0)
        {
            break;
        }
        CPU::_e_registers[(CPU::__current_memory_input >> 3) & 15] = CPU::_e_registers[(CPU::__current_memory_input >> 3) & 15] << shift_by;
        break;
    }
    case 1:
    {
        auto shift_by = (CPU::__current_memory_input)&0x7FFFFFFFFFFFF;
        if (shift_by > 64 || shift_by < 0)
        {
            break;
        }
        CPU::_e_registers[CPU::__current_memory_input & 15] = CPU::_e_registers[CPU::__current_memory_input & 15] << shift_by;
        break;
    }
    }
}

void rshift()
{
    byte mode = ((CPU::__current_memory_input >> 55) & 1UL);
    switch (mode)
    {
    case 0:
    {
        auto shift_by = CPU::_e_registers[CPU::__current_memory_input & 15];
        if (shift_by > 64 || shift_by < 0)
        {
            break;
        }
        CPU::_e_registers[(CPU::__current_memory_input >> 3) & 15] = CPU::_e_registers[(CPU::__current_memory_input >> 3) & 15] >> shift_by;
        break;
    }
    case 1:
    {
        auto shift_by = (CPU::__current_memory_input)&0x7FFFFFFFFFFFF;
        if (shift_by > 64 || shift_by < 0)
        {
            break;
        }
        CPU::_e_registers[CPU::__current_memory_input & 15] = CPU::_e_registers[CPU::__current_memory_input & 15] >> shift_by;
        break;
    }
    }
}

void Mov()
{
    // 0xxxxxx7 8 xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx
    // bits 0 to 7 = instruction
    // bit 8 = instruction mode
    // 0 => register-register, 1 => register-immediate
    byte mode = ((CPU::__current_memory_input >> 55) & 1UL);
    switch (mode)
    {
    case 0:
    {
        // 0xxxxxx7 8 xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx dest = [xxxx] src = [xxxx]
        CPU::_e_registers[(CPU::__current_memory_input >> 3) & 15] = CPU::_e_registers[CPU::__current_memory_input & 15];
        break;
    }
    case 1:
    {
        // 0xxxxxx7 8 src = [xxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx] xxxx dest = [xxxx]
        CPU::_e_registers[CPU::__current_memory_input & 15] = (CPU::__current_memory_input >> 8) & 0x7FFFFFFFFFFF;
        break;
    }
    }
}

void Load()
{
    // 0xxxxxx7 xxxxxxxx xxxxxxxx address = [xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx] xxxx dest = [xxxx]
    // bits 0 to 7 = instruction
    // this instruction only takes the destination register and the address
    CPU::_e_registers[CPU::__current_memory_input & 15] = CPU::data_memory.mem_read((CPU::__current_memory_input >> 8) & 4294967295);
    // for the sake of proper working of the instructions, the addresses are recommended to be correct
}

void Lea()
{
    // 0xxxxxx7 xxxxxxxx xxxxxxxx address = [xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx] xxxx dest = [xxxx]
    // bits 0 to 7 = instruction
    // this instruction only takes the destination register and the address
    // same as Load but without the need to read the memory
    CPU::_e_registers[CPU::__current_memory_input & 15] = (CPU::__current_memory_input >> 8) & 4294967295;
}

void Swap()
{
    // 0xxxxxx7 xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx regr1 =[xxxx] regr2 = [xxxx]
    // bits 0 to 7 = instruction
    // this instruction only takes two registers and then it swaps their values
    auto x = CPU::_e_registers[(CPU::__current_memory_input >> 3) & 15]; // first value
    CPU::_e_registers[(CPU::__current_memory_input >> 3) & 15] = CPU::_e_registers[CPU::__current_memory_input & 15];
    CPU::_e_registers[CPU::__current_memory_input & 15] = x;
}

void Store()
{
    // 0xxxxxx7 xxxxxxxx xxxxxxxx address = [xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx] xxxx src = [xxxx]
    // bits 0 to 7 = instruction
    // this instruction only takes the destination register and the address
    CPU::data_memory.mem_write((CPU::__current_memory_input >> 8) & 4294967295, CPU::_e_registers[CPU::__current_memory_input & 15]);
}

void Push()
{
    // 0xxxxxx7 xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx
    // this takes nothing as operands
    // the order of push is:
    // regpc regbp, regsp, reg6, reg5 ------------- rega
    if ((CPU::_e_registers[CPU::regsp] & 16777215) + 15 * 8 > 255)
    {
        std::cerr << "Stack Overflow: Terminating Execution." << std::endl;
        exit(-1);
    }
    for (int i = 0; i < 15; i++)
    {
        CPU::stack.mem_write(CPU::_e_registers[CPU::regsp], CPU::_e_registers[i]);
        CPU::_e_registers[CPU::regsp] += 8;
    }
}

void Pop()
{
    // 0xxxxxx7 xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx
    // this takes nothing as operands
    // the order of pop is:
    // rega regb regc  ------ regpc
    if ((CPU::_e_registers[CPU::regsp] & 16777215) < 15 * 8)
    {
        std::cerr << "Stack Underflow: Terminating Execution." << std::endl;
        exit(-1);
    }
    for (int i = 14; i >= 0; i--)
    {
        CPU::_e_registers[CPU::regsp] -= 8;
        CPU::_e_registers[i] = CPU::stack.mem_read(CPU::_e_registers[CPU::regsp]);
    }
}

void Pushr()
{
    // 0xxxxxx7 xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxx src = [xxxx]
    if ((CPU::_e_registers[CPU::regsp] & 16777215) + 8 > 255)
    {
        std::cerr << "Stack Overflow: Terminating Execution." << std::endl;
        exit(-1);
    }
    CPU::stack.mem_write(CPU::_e_registers[CPU::regsp], CPU::_e_registers[CPU::__current_memory_input & 15]);
    CPU::_e_registers[CPU::regsp] += 8;
}

void Popr()
{
    // 0xxxxxx7 xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxx dest = [xxxx]
    if ((CPU::_e_registers[CPU::regsp] & 16777215) < 8)
    {
        std::cerr << "Stack Underflow: Terminating Execution." << std::endl;
        exit(-1);
    }
    CPU::_e_registers[CPU::regsp] -= 8;
    CPU::_e_registers[CPU::__current_memory_input & 15] = CPU::stack.mem_read(CPU::_e_registers[CPU::regsp]);
    ;
}

void Pushv()
{
    // 0xxxxxx7 xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx
    // the value can be as large as 56 bits
    if ((CPU::_e_registers[CPU::regsp] & 16777215) + 8 > 255)
    {
        std::cerr << "Stack Overflow: Terminating Execution." << std::endl;
        exit(-1);
    }
    CPU::stack.mem_write(CPU::_e_registers[CPU::regsp], CPU::__current_memory_input & 0xFFFFFFFFFFFFFF);
    CPU::_e_registers[CPU::regsp] += 8;
}

void Popv()
{
    // 0xxxxxx7 xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx
    if ((CPU::_e_registers[CPU::regsp] & 16777215) < 8)
    {
        std::cerr << "Stack Underflow: Terminating Execution." << std::endl;
        exit(-1);
    }
    CPU::_e_registers[CPU::regsp] -= 8;
}

void Cmp()
{
    // 0xxxxxx7 xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx regr1 = [xxxx] regr2 = [xxxx]
    // only applies to registers
    auto regr1 = CPU::_e_registers[(CPU::__current_memory_input >> 3) & 15];
    auto regr2 = CPU::_e_registers[CPU::__current_memory_input & 15];
    if (regr1 == regr2)
    {
        CPU::_f_register[CPU::EQUAL] = 1;
    }
    else
    {
        CPU::_f_register[CPU::EQUAL] = 0;
    }
    if (regr1 == regr2 == 0)
    {
        CPU::_f_register[CPU::ZERO] = 1;
    }
    else
    {
        CPU::_f_register[CPU::ZERO] = 0;
    }
    if (regr1 < regr2)
    {
        CPU::_f_register[CPU::SMALLER] = 1;
    }
    else
    {
        CPU::_f_register[CPU::SMALLER] = 0;
    }
    if (regr1 > regr2)
    {
        CPU::_f_register[CPU::GREATER] = 1;
    }
    else
    {
        CPU::_f_register[CPU::GREATER] = 0;
    }
}

void Jmp()
{
    // 0xxxxxx7 xxxxxxxx xxxxxxxx xxxxxxxx address = [xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx]
    // the address should be given
    auto addr = CPU::__current_memory_input & 4294967295;
    CPU::_e_registers[CPU::regpc] = addr;
}

void Jz()
{
    if (CPU::_f_register[CPU::ZERO] == 1)
    {
        Jmp();
    }
}

void Jnz()
{
    if (CPU::_f_register[CPU::ZERO] != 1)
    {
        Jmp();
    }
}

void Jg()
{
    if (CPU::_f_register[CPU::GREATER] == 1)
    {
        Jmp();
    }
}

void Jge()
{
    if (CPU::_f_register[CPU::GREATER] == 1 || CPU::_f_register[CPU::EQUAL] == 1)
    {
        Jmp();
    }
}

void Js()
{
    if (CPU::_f_register[CPU::SMALLER] == 1)
    {
        Jmp();
    }
}

void Jse()
{
    if (CPU::_f_register[CPU::SMALLER] == 1 || CPU::_f_register[CPU::EQUAL] == 1)
    {
        Jmp();
    }
}

void Jn()
{
    if (CPU::_f_register[CPU::NEGATIVE] == 1)
    {
        Jmp();
    }
}

void Jnn()
{
    if (CPU::_f_register[CPU::NEGATIVE] != 1)
    {
        Jmp();
    }
}

void Je()
{
    if (CPU::_f_register[CPU::EQUAL] == 1)
    {
        Jmp();
    }
}

void Jne()
{
    if (CPU::_f_register[CPU::EQUAL] != 1)
    {
        Jmp();
    }
}

void Movz()
{
    if (CPU::_f_register[CPU::ZERO] == 1)
    {
        Mov();
    }
}

void Movnz()
{
    if (CPU::_f_register[CPU::ZERO] != 1)
    {
        Mov();
    }
}

void Movg()
{
    if (CPU::_f_register[CPU::GREATER] == 1)
    {
        Mov();
    }
}

void Movge()
{
    if (CPU::_f_register[CPU::GREATER] == 1 || CPU::_f_register[CPU::EQUAL] == 1)
    {
        Jmp();
    }
}

void Movs()
{
    if (CPU::_f_register[CPU::SMALLER] == 1)
    {
        Jmp();
    }
}

void Movse()
{
    if (CPU::_f_register[CPU::SMALLER] == 1 || CPU::_f_register[CPU::EQUAL] == 1)
    {
        Mov();
    }
}

void Movn()
{
    if (CPU::_f_register[CPU::NEGATIVE] == 1)
    {
        Mov();
    }
}

void Movnn()
{
    if (CPU::_f_register[CPU::NEGATIVE] != 1)
    {
        Mov();
    }
}

void Move()
{
    if (CPU::_f_register[CPU::EQUAL] == 1)
    {
        Mov();
    }
}

void Movne()
{
    if (CPU::_f_register[CPU::EQUAL] != 1)
    {
        Mov();
    }
}

#endif