#ifndef __CONCAT_H__
#define __CONCAT_H__

#include "pri.h"

class concat{
private:
	int num;
	pri **pa;

// You can declare more member variables and member functions here..


public:
	concat(void);
	concat(int* priority, char **words, int n);
	~concat(void);

	char* concatenate(void);
	void countSort(int* prioritys,int* tmp,int* sortedIdx,int i);
	void radixSort(void);
};

#endif
