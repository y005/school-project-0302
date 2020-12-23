#ifndef __MAX_SUM_H__
#define __MAX_SUM_H__

class maxSum{
private:
	int num;
	int* money;

// Declare member variables or functions here if you need...

public:
	maxSum(int n, int *m);
	~maxSum();
	int max(void);
	int findMax(int l,int r,int** m);
};

#endif
