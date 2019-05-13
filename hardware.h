#include "ram.h"

class Hardware
{
    // MemoryManagementUnit
        // PageFault
    // Word
        // Address
    // BackingStore
    //RAM
    RAM random_access_memory;
        // Status
};

class RunTimeError
{

};

class PageFault
{
    public:
        PageFault();
        Word pageNumber_;
};

class MemoryManagementUnit
{
    public:
        void clearTLB();
        MemoryManagementUnit& instance();
        MemoryManagementUnit();
        // overload = operator
        pageAccesses();
        pageFaults();
        // <T> use template
        void read<T>();
        tlbAccesses();
        tlbFaults();
    private:
        MemoryManagementUnit();
        int page_access_count_;
        int page_in_faults_;
        TLB tlb_;
        int tlb_access_count_;
        int tlb_faults_;
};




