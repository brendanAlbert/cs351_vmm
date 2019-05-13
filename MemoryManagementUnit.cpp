#include "MemoryManagementUnit.h"
#include "MemoryManager.h"
#include "PageTable.h"
#include "backingStore.h"
// #include "LRU.h"
#include "TLB.h"
#include "ram.h"
#include <iostream>

// To perform the address translations
void getPageNumberAndOffset(int address, int & page_number, int & offset)
{
    // shifting 8 bits to the right gives the 8 leftmost bits, the PageNumber
    unsigned int left_most_8bits = address >> 8;
    // masking the 8 right bits gives the 8 rightmost bits, the Offset
    unsigned int right_most_8bits = address & 0xFF;
    page_number = left_most_8bits;
    offset = right_most_8bits;
}

Address MemoryManagementUnit::read(int logical_address)
{
    // pass in the logical address received from the CPU, and separate it into its two constituent parts
    // the page number and offset
    int page_number, offset;
    getPageNumberAndOffset(logical_address, page_number, offset);

    // Assign the page number and offset to the passed in Page.
    Address page;
    Word word_pg, word_offset;
    word_pg.value_     = page_number;
    word_offset.value_ = offset;
    page.address       = word_pg;
    page.displacement  = word_offset;

    return page;
}

void MemoryManagementUnit::displayDataValue()
{
    // cout the data value
    cout << "Page faults: " << page_in_faults_ << "\n" ;
    cout << "TLB hits: " << tlb_hits_ << "\n";
}

void MemoryManagementUnit::tlbAccesses(Address page)
{
    // Address temp_Display;
	tlb_access_count_++;
	int HitOrMiss = tlb.hit(page); // Step 1

	if (HitOrMiss == -1) // Miss	//Step2
	{
		tlbFaults(page);
	}
	else// hit //Step 2
	{
		tlb_hits_++;
	    int frame_number = tlb.access(page);
		//Save to ram;
        physical_memory.memory.at(frame_number).physical_address = page.address.value_;
        physical_memory.memory.at(frame_number).frame_number = frame_number;
        
        // Get the data value stored from the associated frame in physical memory

	}
}

void MemoryManagementUnit::tlbFaults(Address page)
{
    tlb_faults_++;
    if(tlb.isFull())
    {
        //PageReplacementAlgorithm();
        algorithm.replace(algorithm.findVictim(tlb.TLBHitRatio, tlb.TLBEntries), tlb.TLBEntries, page.page, PCB);
    }
    else
    {
        for (int i = 0; i < TLB_SIZE; ++i)
    {
        // first empty slot
        // needs reference to page table to get frame number
        if (tlb.TLBEntries[i].address.value_ == UINT32_MAX)
        {
            tlb.TLBEntries[i].page.value_ = page.address.value_;
            tlb.TLBEntries[i].frame.value_ = pageAccesses(page);
            tlb.TLBHitRatio[i] = 16;
            tlb.size++;
            break;
        }
    }
    }
	pageAccesses(page);
}

int MemoryManagementUnit::pageAccesses(Address page)
{
    page_access_count_++;
	int HitOrMiss = PCB.pagehit(page.address);

	if(HitOrMiss == -1) //step 4
	{
		pageFaults(page);
        // access the backing_store
        return -1;
	}
	else
	{
		PCB.access(page.address);


        int frame_number = PCB.access(page.address).value_;
		//Save to ram;
        physical_memory.memory.at(frame_number).physical_address = page.address.value_;
        physical_memory.memory.at(frame_number).frame_number = frame_number;
        return frame_number;
	}
}

void MemoryManagementUnit::pageFaults(Address page)
{
    page_in_faults_++;
    // get value from backing store
    int data_value = b.read(page.address.value_, page.displacement.value_);

    // Get free frame from freeFrameList
    
    int frame_number = mm.getFrameNumber();
    // insert page

    //Save to ram;
    physical_memory.memory.at(frame_number).data_value = data_value;
    
    PCB.page_table[page.address.value_].page.value_ = page.address.value_;
    PCB.page_table[page.address.value_].frame.value_ = frame_number;


}

void MemoryManagementUnit::clearTLB()
{
    for (int i = 0; i < 16; i--)
	{
		tlb.TLBEntries[i].page.value_ = -1;
		tlb.TLBEntries[i].frame.value_ = -1;
		tlb.TLBHitRatio[i] = -1;
	}
}


MemoryManagementUnit::MemoryManagementUnit()
{
    RAM physical_memory;
    BackingStore b;
    MemoryManager mm;
    PageTable PCB;
    TLB tlb;
    Pagereplacement algorithm;
}