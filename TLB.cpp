#include "TLB.h"
#include "PageTable.h"
#include "Address.h"
#include "MemoryManagementUnit.h"
#include <iostream>

using namespace std;

TLB::TLB()
{
	for(int i = 0; i < TLB_SIZE; ++i)
	{
		TLBEntries[i].page.value_ = UINT32_MAX;
		TLBEntries[i].frame.value_ = UINT32_MAX;
		TLBHitRatio[i] = -1;
	}
	size = 0;
}

bool TLB::isFull()
{
	return size == TLB_SIZE;
}

// methods checks if pagenumber argument exists in the TLB
// if it exists, returns the position in the array
// returns -1 if it doesn't exist (a miss)
int TLB::hit(Address pg)
{
	for(int i = 0; i < TLB_SIZE; ++i)
	{
		if(TLBEntries[i].page.value_ == pg.page.value_)
		{
			return i;
		}
	}
	return -1;
}

// adds a new entry to the TLB if it doesnt exist in the TLB
int TLB::access(Address pg)
{
	if (!isFull())
	{
		for (int i = 0; i < TLB_SIZE; i++)
		{
			// decrement hit ratio if position is not empty and is not an entry
			if (TLBHitRatio[i] != -1)
			{
				TLBHitRatio[i]--;
			}
		}
		TLBHitRatio[hit(pg)] = 16;

		return TLBEntries[hit(pg)].frame.value_;
		
	}
	// if TLB is full, check if the pagenumber exists in the TLB
	else
	{
		for (int i = 0; i < TLB_SIZE; ++i)
		{
			// if entry is miss, decrement hit ratio
			if(TLBEntries[i].page.value_ != pg.address.value_)
			{
				TLBHitRatio[i]--;
			}
			// if the entry is a hit, then set hit ratio to 16
			else if (TLBEntries[i].page.value_ == pg.address.value_)
			{
				TLBHitRatio[i] = 16;
			}
		}
		return TLBEntries[hit(pg)].frame.value_;
	}
}