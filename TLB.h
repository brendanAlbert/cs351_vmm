#ifndef TLB_H
#define TLB_H

#include "Address.h"
#include "PageFault.h"

#define TLB_SIZE 16 // size of TLB

class TLB
{
    public:
        TLB();
        bool isFull();
        int hit(Address pg);
        int access(Address pg);
        Address TLBEntries[TLB_SIZE];
        int TLBHitRatio[TLB_SIZE];
        int size;
};

#endif