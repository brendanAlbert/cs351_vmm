/*Page Table header*/

// additional variables needed to update
// page_faults_
// page_access_count_

#ifndef PAGETABLE_H
#define PAGETABLE_H

#include "Word.h"
#include "Address.h"

#define PAGE_TABLE_SIZE 256 // size of the page table

using namespace std;

class PageTable
{
public:
	// constructor
	PageTable();

	// method searches table for pagenumber
	// returns the framenumber
	Word access(Word pg);

	// method checks the page table for the pagenumber
	int pagehit(Word pg);

	// method fills in the page table
	// void fillTable(backingstore); ???
	Address page_table[PAGE_TABLE_SIZE];

private:
};
#endif