#ifndef MEMORY
#define MEMORY

#include "typedefs.hpp"
#include <cstdlib>
#include <vector>
#include <iostream>

class Memory
{
public:
    Memory() = default;

    void init(dword size, bool _is_variable)
    {
        memArray.resize(size);
        this->_is_variable = _is_variable;
        memSize = size;
    }

    void increase_size(dword __inc_by)
    {
        if (_is_variable == false)
        {
            std::cerr << "Error: The size of this memory cannot be increased." << std::endl;
        }
        if (memArray.capacity() >= __inc_by)
        {
            return;
        }
        memArray.resize(memSize + __inc_by);
    }

    byte get_size(dword address)
    {
        return address >> 24;
    }

    dword get_addr(dword address)
    {
        return address & 16777215;
    }

    qword mem_read(dword address)
    {
        byte size = get_size(address);
        dword addr = get_addr(address);
        if (addr > memSize || addr < 0)
        {
            std::cerr << "Accessing out of bounds memory. Execution terminated" << std::endl;
            exit(-1);
        }
        if (size != 1 && size != 2 && size != 4 && size != 8)
        {
            std::cerr << "Invalid memory access." << std::endl;
            exit(-1);
        }
        qword res;
        switch (size)
        {
        case 1:
            return memArray[addr];
        case 2:
            res = memArray[addr];
            res = (res << 8) | memArray[addr + 1];
            break;
        case 4:
            for (int i = 0; i < 4; i++)
            {
                res = (res << 8) | memArray[addr + i];
            }
            break;
        case 8:
            for (int i = 0; i < 8; i++)
            {
                res = (res << 8) | memArray[addr + i];
            }
            break;
        }
        return res;
    }

    void mem_write(qword address, qword value)
    {
        byte size = get_size(address);
        dword addr = get_addr(address);
        if (addr > memSize || addr < 0)
        {
            std::cerr << "Accessing out of bounds memory. Execution terminated" << std::endl;
            exit(-1);
        }
        if (size != 1 && size != 2 && size != 4 && size != 8)
        {
            std::cerr << "Invalid memory access." << std::endl;
            exit(-1);
        }
        switch (size)
        {
        case 1:
            memArray[addr] = value;
        case 2:
            memArray[addr] = (value >> 8) & 255;
            memArray[addr + 1] = (value & 255);
            break;
        case 4:
            for (int i = 0, j = 3; i < 4; i++, j--)
            {
                memArray[addr + i] = (value >> j * 8) & 255;
            }
            break;
        case 8:
            for (int i = 0, j = 7; i < 8; i++, j--)
            {
                memArray[addr + i] = (value >> j * 8) & 255;
            }
            break;
        }
    }

private:
    std::vector<byte> memArray;
    dword memSize;
    bool _is_variable;
};

#endif