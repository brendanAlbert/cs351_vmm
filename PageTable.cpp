// Page Table class implementation file

#include "PageTable.h"
using namespace std;

// Constructor
PageTable::PageTable()
{
	for (int i = 0; i < PAGE_TABLE_SIZE; i++)
	{
		page_table[i].page.value_ = UINT32_MAX;
		page_table[i].frame.value_ = UINT32_MAX;
	}
}

// method checks if pagenumber is in the page table
int PageTable::pagehit(Word pg)
{
	for (int i = 0; i < PAGE_TABLE_SIZE; i++)
	{
		if (page_table[i].page.value_ == pg.value_)
		{
			return i;
		}
	}

	return -1;
}

/// method searches table for pagenumber
// returns the framenumber
Word PageTable::access(Word pg)
{
	// return framenumber
	return page_table[pagehit(pg)].frame;
}