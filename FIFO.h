
// First In First Out Algorithm header
// inherits the Page Replacement Algorithm Class

#ifndef FIFO_H
#define FIFO_H
#include "PageTable.h"

class Pagereplacement
{
public:
	int findVictim(int TLBHitRatio[], Address tlb[]);
	Pagereplacement();
	void replace(int i, Address tlb[], Word page, PageTable pcb);
};

#endif