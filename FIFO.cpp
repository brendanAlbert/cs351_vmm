// First In First Out Algorithm implementation

#include "FIFO.h"

// constructor
Pagereplacement::Pagereplacement() {};

// method finds the victim and deletes it
// victim is the first pagenumber put in for FIFO
int Pagereplacement::findVictim(int TLBHitRatio[], Address tlb[])
{
	// first entry is always at the 0 index
	// front = TLBEntries[0].page.value_;

	// scoot every entry over
	// this overwrites the first entry and so deleting it
	for (int i = 0; i < 16; i++)
	{
		tlb[i].page.value_ = tlb[i + 1].page.value_;
		tlb[i].frame.value_ = tlb[i + 1].frame.value_;
        TLBHitRatio[i] = 0;
	}

	// empty last slot
	tlb[15].page.value_ = UINT32_MAX;
	tlb[15].frame.value_ = UINT32_MAX;

	// return the victim
	return 0;
}

// method finds empty slot and enters new entry
void Pagereplacement::replace(int position, Address tlb[], Word page, PageTable pcb)
{
	tlb[15].page.value_ = page.value_;
	tlb[15].frame.value_ = pcb.access(page).value_;
    position = 0;
}