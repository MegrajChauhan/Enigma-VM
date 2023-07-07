#ifndef MEMORYHUB
#define MEMORYHUB

#include <unistd.h>
#include <stdlib.h>
#include "typedefs.hpp"
#include <iostream>

class MemoryHub
{
public:
    MemoryHub() = default;

    void init(dword __size)
    {
        void *rets = sbrk(__size);
        if (rets == (void *)-1)
        {
            std::cerr << "Internal error: Cannot initialze memory" << std::endl;
            exit(-1);
        }
        poolSize = __size;
    }

    void increase_poolsize(dword __inc_by)
    {
        if ((poolSize - poolInUse) >= __inc_by)
        {
            return;
        }
        void *rets = sbrk(__inc_by - (poolSize - poolInUse));
        if (rets == (void *)-1)
        {
            std::cerr << "Error: Could not increase memory pool" << std::endl;
            exit(-1);
        }
        poolSize += __inc_by - (poolSize - poolInUse);
    }

    void request_memory(dword _req_size, bool _inc_not_avai)
    {
        if ((poolSize - poolInUse) >= _req_size)
        {
            poolInUse += _req_size;
            return;
        }
        increase_poolsize(_req_size);
        poolInUse += _req_size;
    }

private:
    dword poolSize;
    dword poolInUse;
};

#endif