#ifndef IMEM
#define IMEM

#include <vector>
#include "typedefs.hpp"
#include <iostream>

class Imem
{
    public:
    Imem() = default;

    void init(dword size)
    {
        iarr.resize(size);
        isize = size;
    }

    void i_write(dword address, qword value)
    {
        if(address > isize || address < 0)
        {
           std::cerr<<"Error: Address out of bounds"<<std::endl;
           exit(-1);
        }
        iarr[address] = value;
    }

    void i_resize(dword __inc_by)
    {
        iarr.resize(isize + __inc_by);
        isize += __inc_by;
    }

    qword i_read(dword address)
    {
        if(address > isize || address < 0)
        {
           std::cerr<<"Error: Address out of bounds"<<std::endl;
           exit(-1);
        }
        return iarr[address];
    }

    private:
    std::vector<qword> iarr;
    dword isize;
};

#endif