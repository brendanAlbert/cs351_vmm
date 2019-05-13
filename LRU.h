#pragma once

#include "PageTable.h"
#ifndef LRU_H
#define LRU_H


class Pagereplacement
{
public:
	int findVictim(int TLBHitRatio[], Address tlb[]);
	Pagereplacement();
	void replace(int i, Address tlb[], Word page, PageTable pcb);
};

#endif