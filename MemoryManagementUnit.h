
#ifndef MEMORYMANAGEMENTUNIT_H
#define MEMORYMANAGEMENTUNIT_H

#include <iostream>
#include <ctype.h>
#include "PageFault.h"
// #include "LRU.h"
#include "FIFO.h"
#include <fstream>
#include "Address.h"
#include "TLB.h"
#include "ram.h"
#include "PageTable.h"
#include "backingStore.h"
#include "MemoryManager.h"

using namespace std;

class MemoryManagementUnit
{
    public:
        MemoryManagementUnit();

        Address read(int logical_address);
        void displayDataValue();
        int pageAccesses(Address page);
        void pageFaults(Address page);
        void tlbAccesses(Address page);
        void tlbFaults(Address page);

        void clearTLB();

        TLB tlb;
        RAM physical_memory;
        BackingStore b;
        MemoryManager mm;
        PageTable PCB;
        Pagereplacement algorithm;
    
    private:
        
        int page_access_count_ = 0;
        int page_in_faults_ = 0;

        
        int tlb_access_count_ = 0;
        int tlb_faults_ = 0;
        int tlb_hits_ = 0;

};

#endif